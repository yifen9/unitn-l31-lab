import Pkg

Pkg.activate(".")
Pkg.instantiate()
Pkg.add("YAML")

using Dates
using Markdown
using Printf
using YAML

const DIR_BASE = "/UNITN.BSc"
const DIR_SRC = "src"
const DIR_DOCS = "docs"

const DIR_SRC_COURSES = joinpath(DIR_SRC, "courses")
const DIR_DOCS_COURSES = joinpath(DIR_DOCS, "courses")

# Which will give you a nice String
# e.g., "146140_MARCHETTO_Computer_Programming_1" -> "146140 MARCHETTO Computer Programming 1"
function name_clean(text::AbstractString)::String
    return replace(replace(String(text), "_" => " "), "-" => " ")
end

# Formatting the name, also do the work of name_clean()
# e.g., "MARCHETTO" -> "Marchetto"
function name_prettify(text::AbstractString)::String
    return join([uppercasefirst(lowercase(w)) for w in split(name_clean(text))], " ")
end

# e.g., "146140_MARCHETTO_Computer_Programming_1" -> (
#   id=146140,
#   prof = MARCHETTO,
#   name = Computer_Programming_1
#   )
function course_info_extract(course::String)
    parts = split(course, "_", limit=3)
    if length(parts) < 3
        return nothing
    end
    return (
        id = parts[1],
        prof = parts[2],
        name = parts[3]
    )
end

# The reverse of course_info_extract()
function course_info_whole(course_info)::String
    return string(course_info.id, "_", course_info.prof, "_", replace(course_info.name, " " => "_"))
end

# Classify cases and return a proper String indicating the number of items in a dir
function dir_item_count(dir::String)::String
    n = length(readdir(dir))
    if n == 0
        return nothing
    elseif n == 1
        return "$n item"
    else
        return "$n items"
    end
end

# Return the size of a file in readable format
function size_human_readable(size::Integer)::String
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

# Generate Course Index Table
function course_index_generate(path_src::Vector{String})
    path_docs = joinpath(DIR_DOCS_COURSES, "index.md")
    
    open(path_docs, "w") do f
        println(f, "# Courses Index")
        println(f, "\n")
        println(f, "### Directory")
        println(f, "\n")
        println(f, "| Course | ID | Professor | Last Modified |")
        println(f, "|--------|----|-----------|---------------|")
        for course in path_src
            info = course_info_extract(basename(course))
            if info !== nothing
                name = name_clean(info.name)
                id = info.id
                prof = name_prettify(info.prof)
                time_m = Dates.format(Dates.unix2datetime(stat(course).mtime), "yyyy-mm-dd")
                println(f, "| [$name](./$(basename(course))/index.md) | $id | $prof | $time_m |")
            end
        end
    end
end

# Generate a nice directory tree
# e.g.,
# Computer_Programming_1
# └──Lecture_41_LAB_Simulation
#    └──1.cpp
function directory_tree_generate(path_src::String, path_root::String, name_root::AbstractString)
    rel_parts = split(relpath(path_src, path_root), Base.Filesystem.path_separator)
    tree = String[]
    push!(tree, "### Directory Tree")
    push!(tree, "```")
    push!(tree, "$name_root")
    for (i, part) in enumerate(rel_parts)
        indent = repeat("    ", i-1)
        icon = "└──"
        name_display = name_clean(part)
        push!(tree, "$indent$icon $name_display")
    end
    push!(tree, "```")
    return join(tree, "\n")
end

# Generate directory table
function directory_table_generate(path_src::String)
    entries = readdir(path_src)
    dirs = filter(name -> isdir(joinpath(path_src, name)), entries)
    files = filter(name -> isfile(joinpath(path_src, name)), entries)

    table = String[]
    push!(table, "### Directory Table")
    push!(table, "| Name | Type | Description | Last Modified |")
    push!(table, "|------|------|-------------|---------------|")
    for d in sort(dirs)
        path_src_full = joinpath(path_src, d)
        name = name_clean(d)
        desc = dir_item_count(path_src_full)
        time_m = Dates.format(Dates.unix2datetime(stat(path_src_full).mtime), "yyyy-mm-dd")
        push!(table, "| [$name]($d/) | Directory | $desc | $time_m |")
    end
    for f in sort(files)
        path_src_full = joinpath(path_src, f)
        name = name_clean(f)
        desc = size_human_readable(stat(path_src_full).size)
        time_m = Dates.format(Dates.unix2datetime(stat(path_src_full).mtime), "yyyy-mm-dd")
        push!(table, "| [$name]($f/) | File | $desc | $time_m |")
    end
    return join(table, "\n")
end

# As the name says
function readme_to_index_copy(dir_src, dir_docs)
    file_src = joinpath(dir_src, "README.md")
    file_docs = joinpath(dir_docs, "index.md")
    if isfile(file_src)
        open(file_docs, "w") do f
            println(f, "\n")
            println(f, read(file_src, String))
        end
        println("[INFO] Copied $file_src to $file_docs")
    else
        println("[WARN] $file_src not found")
    end
end

# Generate nested pages
# e.g.,
# 146140_MARCHETTO_Computer_Programming_1
# ├──index.md <- Generated
# └──Lecture_41_LAB_Simulation
#    ├──index.md <- Generated
#    └──1.cpp
#       └──index.md <- Generated
function nested_pages_generate(dir_src::String, dir_docs::String, course_info)
    mkpath(dir_docs)
    entries = readdir(dir_src)
    dirs = filter(name -> isdir(joinpath(dir_src, name)), entries)
    files = filter(name -> isfile(joinpath(dir_src, name)), entries)

    dir_course = joinpath(DIR_SRC, course_info_whole(course_info))
    is_root_course = dir_src == dir_course

    course_info_id = course_info.id
    course_info_prof = name_prettify(course_info.prof)
    course_info_name = name_clean(course_info.name)

    file_docs = joinpath(dir_docs, "index.md")

    open(file_docs, "w") do f
        if is_root_course
            println(f, "# ", course_info_name)
            println(f, "\n")
            println(f, "- **Course ID:** ", course_info_id)
            println(f, "- **Professor:** ", course_info_prof)
        else
            println(f, "# ", name_clean(basename(dir_src)))
            println(f, "\n")
            println("**Course:** ", course_info.name)
            println(f, directory_tree_generate(dir_src, dir_course, name_clean(course_info.name)))
        end
        println(f, directory_table_generate(dir_src))
    end

    # Copy Readme
    readme_to_index_copy(dir_src, dir_docs)

    # Recursive
    for d in dirs
        nested_pages_generate(
            joinpath(dir_src, d),
            joinpath(dir_docs, d),
            course_info
        )
    end
end

# Generate pages
function course_page_generate(dir_course::String)
    course_info = course_info_extract(basename(dir_course))
    if course_info === nothing
        println("[WARN] Skipping unrecognized directory: $dir_course")
        return
    end
    dir_docs = joinpath(DIR_DOCS_COURSES, basename(dir_course))
    nested_pages_generate(dir_course, dir_docs, course_info)
end

function nested_nav_build(path::String)
    entries = readdir(path; join=true, sort=true)
    nav = Vector{Any}()

    for entry in entries
        if isdir(entry)
            name = name_clean(basename(entry))
            rel = joinpath("courses", relpath(entry, DIR_DOCS_COURSES))
            index_path = joinpath(rel, "index.md")
            children = nested_nav_build(entry)
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
    append!(nested_courses, nested_nav_build(DIR_DOCS_COURSES))
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
    mkpath(DIR_DOCS)
    mkpath(DIR_DOCS_COURSES)
    all = joinpath.(DIR_SRC, readdir(DIR_SRC))
    course_dirs = filter(isdir, all)

    course_index_generate(course_dirs)

    for course_dir in course_dirs
        course_page_generate(course_dir)
    end

    readme_to_index_copy("", DIR_DOCS)

    update_mkdocs_nav()

    println("[DONE] All course pages and navigation structure updated.")
end

main()