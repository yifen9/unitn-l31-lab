import Pkg

Pkg.activate(".")
Pkg.instantiate()
Pkg.add("StringEncodings")
Pkg.add("YAML")

"""
Pkg.add("CSV")
Pkg.add("DataFrames")
Pkg.add("XLSX")
"""

using Dates
using Markdown
using Printf
using StringEncodings
using YAML

"""
using CSV
using DataFrames
using XLSX
"""

const DIR_BASE_REPO = "https://github.com/yifen9/UNITN.BSc/tree/main"

const DIR_BASE = "/UNITN.BSc"
const DIR_SRC = "src"
const DIR_DOCS = "docs"

const DIR_SRC_COURSES = joinpath(DIR_SRC, "courses")
const DIR_DOCS_COURSES = joinpath(DIR_DOCS, "courses")

# Which will give you a nice String
# e.g., "146140_MARCHETTO_Computer_Programming_1" -> "146140 MARCHETTO Computer Programming 1"
function name_clean(text::AbstractString)::String
    cleaned = replace(replace(String(text), "_" => " "), "-" => " ")
    return occursin(r"^0\d+", cleaned) ? replace(cleaned, r"^0" => "0\u200B") : cleaned
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
    if length(parts) < 4
        return nothing
    end
    return (
        id = parts[1],
        moodle = parts[2],
        prof = parts[3],
        name = parts[4]
    )
end

# The reverse of course_info_extract()
function course_info_whole(course_info)::String
    return string(course_info.id, "_", course_info.moodle, "_", course_info.prof, "_", replace(course_info.name, " " => "_"))
end

function file_extension_get(f::String)::String
    ext = lowercase(splitext(basename(f))[2])
    return startswith(ext, ".") ? ext[2:end] : ext
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

# As the name says
function size_directory_get(path::AbstractString)::Int
    total = 0
    for (root, _, files) in walkdir(path)
        for file in files
            path_file = joinpath(root, file)
            try
                total += stat(path_file).size
            catch
                println("[WARN] Skipping file: $file_path")
            end
        end
    end
    return total
end

# Return the size of a file in readable format
function size_human_readable(size::Integer)::String
    if size < 1024
        return "$size B"
    elseif size < 1024^2
        return @sprintf("%.3f KiB", size / 1024)
    elseif size < 1024^3
        return @sprintf("%.3f MiB", size / 1024^2)
    else
        return @sprintf("%.3f GiB", size / 1024^3)
    end
end

# Generate Course Index Table
function course_index_generate(path_src::Vector{String})
    path_docs = joinpath(DIR_DOCS_COURSES, "index.md")
    
    open(path_docs, "w") do f
        println(f, "# Courses", "\n")
        println(f, "## Index", "\n")
        println(f, "| Course | ID | Professor | Moodle |")
        println(f, "|--------|----|-----------|--------|")
        for course in path_src
            info = course_info_extract(basename(course))
            if info !== nothing
                name = name_clean(info.name)
                id = info.id
                prof = name_prettify(info.prof)
                moodle = info.moodle
                println(f, "| [$name](./$(basename(course))/index.md) | $id | $prof | [🡥](https://didatticaonline.unitn.it/dol/course/view.php?id=$moodle) |")
            end
        end
        println(f, "\n---\n")
        println(f, "## Study Plan", "\n")
        println(f, file_preview_generate(joinpath(DIR_SRC, "Manifesto_LT_INFO_EN_24-25.pdf")))
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

    table = String["\n"]
    push!(table, "| Name | Type | Item | Size |")
    push!(table, "|------|------|------|------|")
    for d in sort(dirs)
        path_src_full = joinpath(path_src, d)
        name = name_clean(d)
        item_count = dir_item_count(path_src_full)
        size = size_human_readable(size_directory_get(path_src_full))
        push!(table, "| [$name]($d/) | / | $item_count | $size |")
    end
    for f in sort(files)
        path_src_full = joinpath(path_src, f)
        name = name_clean(splitext(f)[1])
        ext = file_extension_get(f)
        size = size_human_readable(stat(path_src_full).size)
        push!(table, "| [$name]($f/) | $ext | / | $size |")
    end
    return join(table, "\n")
end

# As the name says
function readme_to_index_copy(dir_src, dir_docs)
    file_src = joinpath(dir_src, "README.md")
    file_docs = joinpath(dir_docs, "index.md")
    if isfile(file_src)
        open(file_docs, "a") do f
            println(f, "\n---\n")
            println(f, "## More Info", "\n")
            println(f, read(file_src, String))
        end
    end
end

# Somehow I fail to implement this, will positively add this feature in near future
"""
function table_dataframe_to_markdown(df::DataFrame)::String
    io = IOBuffer()

    header = string.(names(df))
    println(io, "| ", join(header, " | "), " |")
    println(io, "|", join(["---" for _ in header], "|"), "|")

    for row in eachrow(df)
        values = string.(row)
        println(io, "| ", join(values, " | "), " |")
    end

    @show String(take!(io))

    return String(take!(io))
end
"""

# Generate the preview section for file page
function file_preview_generate(file_src::String)::String
    ext = lowercase(file_extension_get(file_src))
    file_src_full = joinpath(DIR_BASE, file_src)

    if ext in ["png", "jpg", "jpeg", "gif", "svg", "ppm"]
        return "<img src=\"$file_src_full\" alt=\"Image Preview\" style=\"width: 100%; height: auto; display: block; margin: auto;\" />"
    elseif ext in ["mp4", "webm"]
        return "<video controls style=\"width: 100%; height: auto; display: block; margin: auto;\">
            <source src=\"$file_src_full\" type=\"video/$ext\">
        </video>"
    elseif ext == "pdf"
        return "<iframe src=\"$file_src_full\" style=\"width:100%; height:100vh; border:none;\"></iframe>"
    elseif ext == "csv"
        try
            # df = CSV.read(file_src, DataFrame; limit=64)
            # return table_dataframe_to_markdown(df)
            return "_Please imagine there is a CSV table_"
        catch e
            println("[WARN] CSV table $file_src failed to generate preview")
            return "_Please imagine there is a CSV table_"
        end
    elseif ext == "xlsx"
        return "_Please imagine there is a XLSX table_"
    else
        try
            bytes = read(file_src)
    
            content = try
                String(bytes)
            catch
                String(bytes, enc"Windows-1252")
            end
    
            if any(c -> c < ' ' && c != '\n' && c != '\t', content)
                return "_Please imagine there is a $ext file_"
            end
    
            escaped = replace(content, r"&" => "&amp;", r"<" => "&lt;", r">" => "&gt;")
            return "```plaintext\n" * escaped * "\n```"
        catch
            return "_Please imagine there is a $ext file_"
        end
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
    is_dir = isdir(dir_src)

    if is_dir
        entries = readdir(dir_src)
        dirs = filter(name -> isdir(joinpath(dir_src, name)), entries)
        files = filter(name -> isfile(joinpath(dir_src, name)), entries)
    end

    dir_course = joinpath(DIR_SRC, course_info_whole(course_info))
    is_root_course = dir_src == dir_course

    course_info_id = course_info.id
    course_info_prof = name_prettify(course_info.prof)
    course_info_name = name_clean(course_info.name)

    file_docs = joinpath(dir_docs, "index.md")
    file_origin = joinpath(DIR_BASE_REPO, dir_src)

    # Generate basic info about the page
    open(file_docs, "w") do f
        if is_root_course
            println(f, "# ", course_info_name, "\n")
            println(f, "<small>[← Back](../index.md)</small>", "\n")
            println(f, "## Basic Info", "\n")
            println(f, "- **Course ID:** ", course_info_id)
            println(f, "- **Professor:** ", course_info_prof)
            println(f, "- **[Origin]($file_origin)**", "\n")
            println(f, "\n")
            println(f, directory_table_generate(dir_src))

            # Prepare for copying Readme
            println(f, "\n")
        elseif is_dir
            println(f, "# ", name_clean(basename(dir_src)), "\n")
            println(f, "<small>[← Back](../index.md)</small>", "\n")
            println(f, "## Basic Info", "\n")
            println(f, "- **Item:** ", dir_item_count(dir_src))
            println(f, "- **Size:**  ", size_human_readable(size_directory_get(dir_src)))
            println(f, "- **[Origin]($file_origin)**", "\n")
            println(f, "\n")
            println(f, directory_tree_generate(dir_src, dir_course, name_clean(course_info.name)))
            println(f, "\n")
            println(f, directory_table_generate(dir_src))

            # Prepare for copying Readme
            println(f, "\n")
        else
            println(f, "# ", name_clean(splitext(basename(dir_src))[1]), "\n")
            println(f, "<small>[← Back](../index.md)</small>", "\n")
            println(f, "## Basic Info", "\n")
            println(f, "- **Type:    **", file_extension_get(dir_src))
            println(f, "- **Size:    **", size_human_readable(stat(dir_src).size))
            println(f, "- **[Origin]($file_origin)**", "\n")

            link_download = joinpath(DIR_BASE, dir_src)
            println(f, "- **<a href=\"$link_download\" download>Download</a>**")

            println(f, "\n")
            println(f, directory_tree_generate(dir_src, dir_course, name_clean(course_info.name)))
            println(f, "\n---\n")
            if lowercase(file_extension_get(dir_src)) == "md"
                println(f, "## More Info", "\n")
                println(f, read(dir_src, String))
            else
                println(f, "## Preview", "\n")
                println(f, file_preview_generate(dir_src))
            end
        end
    end

    if is_dir
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

        # I don't know why here I seperate dirs and files, but just in case
        for f in files
            nested_pages_generate(
                joinpath(dir_src, f),
                joinpath(dir_docs, f),
                course_info
            )
        end
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
            name = name_clean(basename(String(entry)))
            rel = joinpath("courses", relpath(entry, DIR_DOCS_COURSES))
            index_path = joinpath(rel, "index.md")
            children = nested_nav_build(entry)
            push!(nav, Dict("$name" => vcat([index_path], children)))
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
end

# Long shit
function page_home_generate(path::String)
    file = joinpath(path, "index.md")
    open(file, "w") do f
        println(f, raw"""---
title: "Bachelor of Computer Science"
hide:
  - navigation
  - toc
---

<link href="https://fonts.googleapis.com/css2?family=Quicksand:wght@500;700&display=swap" rel="stylesheet">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<style>
  .md-content h1 {
    display: none !important;
  }

  .homepage-container {
    width: 90%;
    margin: 0 auto;
    padding: 1rem;
    font-family: 'Quicksand', 'Segoe UI', sans-serif;
    text-align: center;
  }

  .homepage-title {
    font-size: clamp(1.8rem, 5vw, 2.5rem);
    margin-bottom: 0.5rem;
    font-weight: 700;
    color: #2e2e2e;
  }

  .homepage-subtitle {
    font-size: clamp(1rem, 3vw, 1.3rem);
    color: #666;
    margin-bottom: 2rem;
  }

  .homepage-searchbox {
    width: 100%;
    margin: 0 auto 3rem auto;
  }

  .homepage-searchbox input {
    width: 100%;
    padding: 0.9em 1.2em;
    font-size: 1.1em;
    border: 1px solid #ccc;
    border-radius: 0.4em;
    box-shadow: 0 0 8px rgba(0,0,0,0.03);
    transition: border 0.2s ease;
  }

  .homepage-searchbox input:focus {
    border-color: #cc0033;
    outline: none;
  }

  .homepage-footer {
    margin-top: 3rem;
    color: #aaa;
    font-size: 0.9em;
  }

  .homepage-footer img {
    display: inline-block;
    max-width: 100%;
    height: auto;
  }

  /* ========== Dark mode overrides ========== */
  [data-md-color-scheme="slate"] .homepage-title {
    color: #f0f0f0;
  }

  [data-md-color-scheme="slate"] .homepage-subtitle {
    color: #bbb;
  }

  [data-md-color-scheme="slate"] .homepage-searchbox input {
    background-color: #222;
    color: #eee;
    border-color: #555;
  }

  [data-md-color-scheme="slate"] .homepage-searchbox input::placeholder {
    color: #aaa;
  }

  [data-md-color-scheme="slate"] .homepage-footer {
    color: #888;
  }
</style>

<div class="homepage-container">
  <div class="homepage-title">UniTrento BSc 2024/2025</div>
  <div class="homepage-subtitle">Did you study today?</div>

  <div class="homepage-searchbox">
    <input type="text"
           id="custom-search"
           placeholder="Need to study but where..."
    />
  </div>

  <div class="homepage-footer">
    <p>
      <img src="https://count.himiku.com/get/@anto?theme=rule34" alt="visitor count" />
    </p>
  </div>
</div>

<script>
  document.getElementById('custom-search').addEventListener('keydown', function(e) {
    if (e.key === 'Enter') {
      const query = encodeURIComponent(this.value);
      if (query.trim() !== '') {
        window.location.href = "/UNITN.BSc/search/?q=" + query;
      }
    }
  });
</script>
""")
    end
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

    update_mkdocs_nav()

    page_home_generate(DIR_DOCS)

    mkpath(joinpath(DIR_DOCS, "search"))
    page_home_generate(joinpath(DIR_DOCS, "search"))

    println("[DONE] All course pages and navigation structure updated.")
end

main()
