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
        prof = uppercasefirst(lowercase(String(parts[2]))),
        title = prettify_name(String(parts[3]))
    )
end

function list_directory_table(src_path::String, rel_web::String)
    entries = readdir(src_path)
    dirs = filter(name -> isdir(joinpath(src_path, name)), entries)
    files = filter(name -> isfile(joinpath(src_path, name)), entries)

    table = String[]
    push!(table, "\n\n<style>table { width: 100%; table-layout: fixed; } th, td { width: 25%; word-wrap: break-word; }</style>")
    push!(table, "| Name | Type | Description | Link |")
    push!(table, "|------|------|-------------|------|")
    for d in sort(dirs)
        readme = joinpath(src_path, d, "README.md")
        desc = isfile(readme) ? first(split(read(readme, String), "\n")) : ""
        name = prettify_name(d)
        push!(table, "| $name | Directory | $desc | [$name]($d/) |")
    end
    for f in sort(files)
        name = prettify_name(f)
        push!(table, "| $name | File |  | [$name]($rel_web/$f) |")
    end
    return join(table, "\n")
end

function generate_directory_tree(full_path::String, root_path::String, root_name::String)
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

    open(joinpath(target_dir, "index.md"), "w") do f
        if is_course_root
            println(f, "# ", course_info.title)
            println(f, "\n- **Course ID:** ", course_info.id)
            println(f, "- **Professor:** ", course_info.prof)
        else
            println(f, "# ", prettify_name(basename(course_dir)))
            println(f, "\n**Course:** ", course_info.title)
        end

        println(f, "\n```text")
        println(f, generate_directory_tree(course_dir, SRC_DIR, prettify_name(basename(course_dir))))
        println(f, "```")

        println(f, "\n## Directory Contents { #directory-contents }\n")
        println(f, list_directory_table(course_dir, rel_web))

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
    nav = Any[]

    for entry in entries
        name = prettify_name(basename(entry))
        relpath = joinpath("courses", relative_path(entry, joinpath(DOCS_DIR, "courses")))

        if isdir(entry)
            index_path = joinpath(relpath, "index.md")
            children_nav = build_nested_nav(entry)
            push!(nav, Dict(name => vcat([index_path], children_nav)))
        elseif endswith(entry, "index.md")
            continue  # handled via directory case
        end
    end

    return nav
end

function update_mkdocs_nav()
    mkdocs_path = "mkdocs.yml"
    original_lines = readlines(mkdocs_path)
    new_lines = String[]

    nav_indent = 0
    in_nav_section = false

    for line in original_lines
        if startswith(strip(line), "nav:")
            push!(new_lines, "nav:")
            nav_indent = length(line) - length(lstrip(line)) + 2
            in_nav_section = true
            continue
        end

        if in_nav_section && startswith(strip(line), "- Courses:")
            continue
        end

        if in_nav_section && startswith(strip(line), "-")
            in_nav_section = false
        end

        push!(new_lines, line)
    end

    nav_tree = build_nested_nav(joinpath(DOCS_DIR, "courses"))
    nav_yaml = YAML.write(Dict("Courses" => nav_tree))
    nav_yaml_lines = split(nav_yaml, "\n")
    indented = [" "^nav_indent * repeat(" ", nav_indent) * l for l in nav_yaml_lines if !isempty(l)]
    append!(new_lines, indented)

    open(mkdocs_path, "w") do f
        write(f, join(new_lines, "\n"))
    end  # ✅ 正确关闭 open block
end  # ✅ 正确关闭函数定义

function main()
    mkpath(DOCS_DIR)
    mkpath(COURSES_DIR)
    all = joinpath.(SRC_DIR, readdir(SRC_DIR))
    course_dirs = filter(isdir, all)

    for course_dir in course_dirs
        generate_course_page(course_dir)
    end

    copy_readme_to_index()
    update_mkdocs_nav()
    println("[DONE] All course pages and navigation structure updated.")
end

main()