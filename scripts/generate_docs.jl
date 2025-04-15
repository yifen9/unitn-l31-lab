import Pkg
Pkg.activate(".")
Pkg.instantiate()

using Markdown
using Dates
using Printf

const SRC_DIR = "src"
const DOCS_DIR = "docs"
const BASE_URL = "/UNITN.BSc"

function extract_course_info(name::String)
    parts = split(name, "_", limit=3)
    if length(parts) < 3
        return nothing
    end
    return (id = parts[1], prof = parts[2], title = parts[3])
end

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

function generate_course_page(course_dir::String)
    info = extract_course_info(basename(course_dir))
    if info === nothing
        println("⚠️ Skipping unrecognized directory: $course_dir")
        return
    end

    target_dir = joinpath(DOCS_DIR, basename(course_dir))
    mkpath(target_dir)

    web_path = "$BASE_URL/$SRC_DIR/$(basename(course_dir))"
    content = list_files_md(course_dir, web_path)

    readme_path = joinpath(target_dir, "README.md")
    open(readme_path, "w") do f
        println(f, "# 📘 ", info.title)
        println(f, "* **Course ID:** ", info.id)
        println(f, "* **Professor:** ", info.prof)
        println(f, "\n## 📂 Files\n")
        println(f, content)
    end
end

function generate_index(course_dirs::Vector{String}, extra_files::Vector{String})
    index_path = joinpath(DOCS_DIR, "index.md")
    open(index_path, "w") do f
        println(f, "# 🎓 UNITN BSc\n")
        println(f, "## 📚 Course List\n")
        for dir in course_dirs
            info = extract_course_info(basename(dir))
            if info !== nothing
                path = basename(dir)
                println(f, "- [", info.title, " (", info.prof, ")]($path/)")
            end
        end
        if !isempty(extra_files)
            println(f, "\n## 📎 Attach\n")
            for file in extra_files
                println(f, "- [$file]($BASE_URL/$SRC_DIR/$file)")
            end
        end
        println(f, "\n_Last update $(Dates.format(now(), "yyyy-mm-dd HH:MM"))_")
    end
end

function main()
    mkpath(DOCS_DIR)
    all = joinpath.(SRC_DIR, readdir(SRC_DIR))
    course_dirs = filter(isdir, all)
    extra_files = filter(f -> isfile(f) && endswith(f, ".pdf"), all)

    for course_dir in course_dirs
        generate_course_page(course_dir)
    end
    generate_index(course_dirs, basename.(extra_files))
    println("✅ docs/")
end

main()