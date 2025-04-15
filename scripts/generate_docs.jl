import Pkg
Pkg.activate(".")
Pkg.instantiate()

using Markdown
using Dates
using Printf

# === Configuration ===
const SRC_DIR = "src"                        # Folder containing raw course files
const DOCS_DIR = "docs"                      # Output folder for MkDocs
const COURSES_DIR = joinpath(DOCS_DIR, "courses")  # Where all generated course pages go
const BASE_URL = "/UNITN.BSc"               # Base URL used for absolute links in GitHub Pages

# Capitalize the first letter of each word, replacing _ and - with space
function prettify_name(text::String)
    cleaned = replace(replace(text, "_" => " "), "-" => " ")
    return join([uppercasefirst(lowercase(w)) for w in split(cleaned)], " ")
end

# Extract course information from folder name
# Expected format: COURSEID_PROFESSOR_COURSENAME
function extract_course_info(name::String)
    parts = split(name, "_", limit=3)
    if length(parts) < 3
        return nothing
    end
    return (
        id = parts[1],
        prof = uppercasefirst(lowercase(String(parts[2]))),
        title = prettify_name(String(parts[3]))
    )
end

# Generate a Markdown list of files in the given directory
function list_files_md(path::String, rel_link::String)
    entries = readdir(path)
    files = filter(f -> isfile(joinpath(path, f)), entries)
    return join(["- [$f]($rel_link/$f)" for f in sort(files)], "\n")
end

# Generate table for immediate contents of a directory
function list_directory_table(src_path::String, rel_web::String)
    entries = readdir(src_path)
    dirs = filter(name -> isdir(joinpath(src_path, name)), entries)
    files = filter(name -> isfile(joinpath(src_path, name)), entries)

    table = String[]
    push!(table, "<div style='width: 100%; overflow-x: auto;'>\n\n")
    push!(table, "| Name | Type | Description | Link |")
    push!(table, "|------|------|-------------|------|")
    for d in sort(dirs)
        readme = joinpath(src_path, d, "README.md")
        desc = isfile(readme) ? first(split(read(readme, String), "\n")) : ""
        name = prettify_name(d)
        push!(table, "| $name | Directory | $desc | [$d/]($d/) |")
    end
    for f in sort(files)
        name = prettify_name(f)
        push!(table, "| $name | File |  | [$f]($rel_web/$f) |")
    end
    push!(table, "\n</div>")
    return join(table, "\n")
end

# Generate directory tree with clickable links
function generate_directory_tree(full_path::String, root_path::String)
    rel_parts = split(relpath(full_path, root_path), Base.Filesystem.path_separator)
    acc = []
    push!(acc, "docs/")
    push!(acc, "└── courses/")
    for (i, part) in enumerate(rel_parts)
        link = joinpath("../" ^ (length(rel_parts)-i), part, "")
        indent = repeat("    ", i)
        display_name = prettify_name(part)
        is_last = i == length(rel_parts)
        icon = is_last ? "├──" : "└──"
        push!(acc, "$indent$icon [$display_name]($link)")
    end
    return join(acc, "\n")
end

# Generate index.md for course and all subfolders recursively
function generate_nested_pages(course_dir::String, target_dir::String, rel_web::String, course_name::String)
    mkpath(target_dir)

    entries = readdir(course_dir)
    dirs = filter(name -> isdir(joinpath(course_dir, name)), entries)
    files = filter(name -> isfile(joinpath(course_dir, name)), entries)

    open(joinpath(target_dir, "README.md"), "w") do f
        # Title
        println(f, "# ", prettify_name(basename(course_dir)))
        println(f, "\n**Course:** $course_name\n")

        # Directory tree
        println(f, "```")
        println(f, generate_directory_tree(course_dir, SRC_DIR))
        println(f, "```")

        # Directory table
        println(f, "\n## Directory Contents\n")
        println(f, list_directory_table(course_dir, rel_web))

        # README if present
        readme_path = joinpath(course_dir, "README.md")
        if isfile(readme_path)
            println(f, "\n## README.md\n")
            println(f, read(readme_path, String))
        end
    end

    for d in dirs
        generate_nested_pages(
            joinpath(course_dir, d),
            joinpath(target_dir, d),
            joinpath(rel_web, d),
            course_name
        )
    end
end

# Generate courses/CourseName/README.md for each course
function generate_course_page(course_dir::String)
    info = extract_course_info(basename(course_dir))
    if info === nothing
        println("[WARN] Skipping unrecognized directory: $course_dir")
        return
    end

    target_dir = joinpath(COURSES_DIR, basename(course_dir))
    rel_web = joinpath("src", basename(course_dir))
    generate_nested_pages(course_dir, target_dir, rel_web, info.title)
end

# Copy root-level README.md to docs/index.md
function copy_readme_to_index()
    src = "README.md"
    dest = joinpath(DOCS_DIR, "index.md")
    if isfile(src)
        cp(src, dest; force=true)
        println("[INFO] Copied root README.md to index.md")
    else
        println("[WARN] README.md not found")
    end
end

# Generate docs/courses.md overview table
function generate_courses_md(course_dirs::Vector{String})
    path = joinpath(DOCS_DIR, "courses.md")
    open(path, "w") do f
        println(f, "# Course Directory\n")
        println(f, "This page lists all archived course notes, organized by course ID, name, and instructor.\n")
        println(f, "| Course ID | Course Name | Professor | Link |")
        println(f, "|-----------|-------------|-----------|------|")
        for dir in course_dirs
            info = extract_course_info(basename(dir))
            if info !== nothing
                course_path = basename(dir)
                println(f, "| ", info.id, " | ", info.title, " | ", info.prof, " | [View]($course_path/) |")
            end
        end
    end
    println("[INFO] courses.md generated")
end

function main()
    mkpath(DOCS_DIR)
    mkpath(COURSES_DIR)
    all = joinpath.(SRC_DIR, readdir(SRC_DIR))
    course_dirs = filter(isdir, all)

    for course_dir in course_dirs
        generate_course_page(course_dir)
    end

    copy_readme_to_index()
    generate_courses_md(course_dirs)
    println("[DONE] Course documentation generated under docs/courses/")
end

main()
