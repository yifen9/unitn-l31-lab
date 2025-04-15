import Pkg
Pkg.activate(".")
Pkg.instantiate()
Pkg.add("YAML")

using Markdown
using Dates
using Printf
using YAML

const SRC_DIR = "src"
const DOCS_DIR = "docs"
const COURSES_DIR = joinpath(DOCS_DIR, "courses")
const BASE_URL = "/UNITN.BSc"

function prettify_name(text::AbstractString)
    cleaned = replace(replace(String(text), "_" => " "), "-" => " ")
    return join([uppercasefirst(lowercase(w)) for w in split(cleaned)], " ")
end

function extract_course_info(name::String)
    parts = split(name, "_", limit=3)
    if length(parts) < 3
        return nothing
    end
    return (
        id = parts[1],
        # prof = uppercasefirst(lowercase(String(parts[2]))),
        # title = prettify_name(String(parts[3]))
        prof = parts[2],
        title = parts[3]
    )
end

function generate_courses_index(course_dirs::Vector{String})
    path = joinpath(COURSES_DIR, "index.md")
    open(path, "w") do f
        println(f, "# Courses")
        println(f, "\n")
        println(f, "| Course | ID | Professor | Last Modified |")
        println(f, "|-------------|----|-----------|---------------|")
        for dir in course_dirs
            info = extract_course_info(basename(dir))
            if info !== nothing
                name = prettify_name(info.title)
                id = info.id
                prof = info.prof
                mtime = Dates.format(Dates.unix2datetime(stat(joinpath("./", basename(dir))).mtime), "yyyy-mm-dd")
                println(f, "| [$name](./$(basename(dir))/index.md) | $id | $prof | $mtime |")
            end
        end
    end
end

function human_readable_size(size::Integer)
    if size < 1024
        return "$size B"
    elseif size < 1024^2
        return @sprintf("%.1f KB", size / 1024)
    elseif size < 1024^3
        return @sprintf("%.1f MB", size / 1024^2)
    else
        return @sprintf("%.1f GB", size / 1024^3)
    end
end

function list_directory_table(src_path::String, rel_web::String)
    entries = readdir(src_path)
    dirs = filter(name -> isdir(joinpath(src_path, name)), entries)
    files = filter(name -> isfile(joinpath(src_path, name)), entries)

    table = String[]
    push!(table, "\n")
    push!(table, "| Name | Type | Description | Last Modified |")
    push!(table, "|------|------|-------------|---------------|")
    for d in sort(dirs)
        full_path = joinpath(src_path, d)
        name = prettify_name(d)
        desc = "$(length(readdir(full_path))) item(s)"
        mtime = Dates.format(Dates.unix2datetime(stat(full_path).mtime), "yyyy-mm-dd")
        push!(table, "| [$name]($d/) | Directory | $desc | $mtime |")
    end
    for f in sort(files)
        full_path = joinpath(src_path, f)
        name = prettify_name(f)
        size_str = human_readable_size(stat(full_path).size)
        mtime = Dates.format(Dates.unix2datetime(stat(full_path).mtime), "yyyy-mm-dd")
        push!(table, "| [$name]($f/) | File | $size_str | $mtime |")
    end
    return join(table, "\n")
end

function generate_directory_tree(full_path::String, root_path::String, root_name::AbstractString)
    rel_parts = split(relpath(full_path, root_path), Base.Filesystem.path_separator)
    acc = ["$root_name/"]
    for (i, part) in enumerate(rel_parts)
        indent = repeat("    ", i)
        icon = i == length(rel_parts) ? "└──" : "├──"
        display_name = prettify_name(part)
        push!(acc, "$indent$icon $display_name")
    end
    return join(acc, "\n")
end

function generate_nested_pages(course_dir::String, target_dir::String, rel_web::String, course_info)
    mkpath(target_dir)
    entries = readdir(course_dir)
    dirs = filter(name -> isdir(joinpath(course_dir, name)), entries)
    files = filter(name -> isfile(joinpath(course_dir, name)), entries)

    is_course_root = course_dir == joinpath(SRC_DIR, string(course_info.id, "_", course_info.prof, "_", replace(course_info.title, " " => "_")))

    course_info_id = course_info.id
    course_info_prof = uppercasefirst(lowercase(String(course_info.prof)))
    course_info_title = prettify_name(String(course_info.title))

    open(joinpath(target_dir, "index.md"), "w") do f
        if is_course_root
            println(f, "# ", course_info_title)
            println(f, "\n- **Course ID:** ", course_info_id)
            println(f, "- **Professor:** ", course_info_prof)
        else
            println(f, "# ", prettify_name(basename(course_dir)))
            println(f, "\n**Course:** ", course_info.title)
        end

        println(f, "\n```text")
        println(f, generate_directory_tree(course_dir, SRC_DIR, course_info.title))
        println(f, "```")

        println(f, list_directory_table(course_dir, rel_web))

        readme_path = joinpath(course_dir, "README.md")
        if isfile(readme_path)
            println(f, "\n")
            println(f, read(readme_path, String))
        end
    end

    for d in dirs
        generate_nested_pages(
            joinpath(course_dir, d),
            joinpath(target_dir, d),
            joinpath(rel_web, d),
            course_info
        )
    end
end

function generate_course_page(course_dir::String)
    info = extract_course_info(basename(course_dir))
    if info === nothing
        println("[WARN] Skipping unrecognized directory: $course_dir")
        return
    end
    target_dir = joinpath(COURSES_DIR, basename(course_dir))
    rel_web = joinpath("src", basename(course_dir))
    generate_nested_pages(course_dir, target_dir, rel_web, info)
end

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

function build_nested_nav(path::String)
    entries = readdir(path; join=true, sort=true)
    nav = Vector{Any}()

    for entry in entries
        if isdir(entry)
            name = prettify_name(basename(entry))
            rel = joinpath("courses", relpath(entry, joinpath(DOCS_DIR, "courses")))
            index_path = joinpath(rel, "index.md")
            children = build_nested_nav(entry)
            push!(nav, Dict(name => vcat([index_path], children)))
        end
    end

    return nav
end

function update_mkdocs_nav()
    mkdocs_path = "mkdocs.yml"
    backup_path = mkdocs_path * ".bak"
    cp(mkdocs_path, backup_path; force=true)

    original_lines = readlines(backup_path)
    new_lines = String[]

    in_nav = false
    skipping_courses = false

    for line in original_lines
        stripped = strip(line)

        if stripped == "nav:"
            in_nav = true
            push!(new_lines, "nav:")
            continue
        end

        if in_nav && startswith(stripped, "- Courses:")
            skipping_courses = true
            continue
        elseif in_nav && startswith(stripped, "- ")
            in_nav = false
            skipping_courses = false
        end

        if !skipping_courses
            push!(new_lines, line)
        end
    end

    nested_courses = Any["courses/index.md"]
    append!(nested_courses, build_nested_nav(joinpath(DOCS_DIR, "courses")))
    courses_entry = Dict("Courses" => nested_courses)

    nav_yaml_lines = split(YAML.write([courses_entry]), "\n")
    for line in nav_yaml_lines
        if !isempty(strip(line))
            push!(new_lines, "  " * line)
        end
    end

    open(mkdocs_path, "w") do f
        write(f, join(new_lines, "\n"))
    end

    println("[INFO] mkdocs.yml navigation successfully updated.")
end

function main()
    mkpath(DOCS_DIR)
    mkpath(COURSES_DIR)
    all = joinpath.(SRC_DIR, readdir(SRC_DIR))
    course_dirs = filter(isdir, all)

    generate_courses_index(course_dirs)

    for course_dir in course_dirs
        generate_course_page(course_dir)
    end

    copy_readme_to_index()
    update_mkdocs_nav()
    println("[DONE] All course pages and navigation structure updated.")
end

main()