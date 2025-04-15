import Pkg
Pkg.activate(".")
Pkg.instantiate()

using Markdown
using Dates
using Printf

# === Configuration ===
const SRC_DIR = "src"              # Folder containing raw course files
const DOCS_DIR = "docs"            # Output folder for MkDocs
const BASE_URL = "/UNITN.BSc"     # Base URL used for absolute links in GitHub Pages

# Capitalize the first letter of each word, lowercase the rest
function capitalize_title(text::String)
    return join([uppercasefirst(lowercase(w)) for w in split(text, r"[ _]+")], " ")
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
        prof = uppercasefirst(lowercase(parts[2])),
        title = capitalize_title(parts[3])
    )
end

# Generate markdown bullet list of files in a course directory
function list_files_md(src_path::String, web_path::String)
    lines = String[]
    for file in sort(readdir(src_path))
        full = joinpath(src_path, file)
        if isfile(full)
            push!(lines, "- [$file]($web_path/$file)")
        end
    end
    return join(lines, "\n")
end

# Generate docs/CourseName/README.md for each course
function generate_course_page(course_dir::String)
    info = extract_course_info(basename(course_dir))
    if info === nothing
        println("[WARN] Skipping unrecognized directory: $course_dir")
        return
    end

    target_dir = joinpath(DOCS_DIR, basename(course_dir))
    mkpath(target_dir)

    web_path = "$BASE_URL/$SRC_DIR/$(basename(course_dir))"
    content = list_files_md(course_dir, web_path)

    readme_path = joinpath(target_dir, "README.md")
    open(readme_path, "w") do f
        println(f, "# ", info.title)
        println(f, "**Course ID:** ", info.id)
        println(f, "\n**Professor:** ", info.prof)
        println(f, "\n## Files\n")
        println(f, content)
    end
end

# Generate docs/index.md by copying GitHub repo README.md
function copy_readme_to_index()
    if isfile("README.md")
        cp("README.md", joinpath(DOCS_DIR, "index.md"); force=true)
        println("[INFO] index.md generated from root README.md")
    else
        println("[WARN] README.md not found in project root")
    end
end

# Generate docs/courses.md: an overview of all courses in a table format
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

# Generate the full website structure
function main()
    mkpath(DOCS_DIR)
    all = joinpath.(SRC_DIR, readdir(SRC_DIR))
    course_dirs = filter(isdir, all)
    extra_files = filter(f -> isfile(f) && endswith(f, ".pdf"), all)

    for course_dir in course_dirs
        generate_course_page(course_dir)
    end

    copy_readme_to_index()
    generate_courses_md(course_dirs)
    println("[DONE] All course pages and index files have been generated under docs/")
end

main()