import Pkg
Pkg.activate(".")
Pkg.instantiate()

using Markdown
using Dates
using Printf

# === Configuration ===
const SRC_DIR = "src"                        # Folder containing raw course files
const DOCS_DIR = "docs"                      # Output folder for MkDocs
const BASE_URL = "/UNITN.BSc"               # Base URL used for absolute links in GitHub Pages

# Capitalize the first letter of each word, lowercase the rest
function capitalize_title(text::String)
    return join([uppercasefirst(lowercase(w)) for w in split(text, r"[ _]+")], " ")
end

"Generate a Markdown list of files in the given directory"
function list_files_md(path::String, rel_link::String)
    entries = readdir(path)
    files = filter(f -> isfile(joinpath(path, f)), entries)
    return join(["- [$f]($rel_link/$f)" for f in sort(files)], "\n")
end

"Generate table for immediate contents of a directory"
function list_directory_table(src_path::String, rel_web::String)
    entries = readdir(src_path)
    dirs = filter(name -> isdir(joinpath(src_path, name)), entries)
    files = filter(name -> isfile(joinpath(src_path, name)), entries)

    table = String[]
    push!(table, "| Name | Type | Description | Link |")
    push!(table, "|------|------|-------------|------|")
    for d in sort(dirs)
        readme = joinpath(src_path, d, "README.md")
        desc = isfile(readme) ? first(split(read(readme, String), "\n")) : ""
        push!(table, "| $d | Directory | $desc | [$d/]($d/) |")
    end
    for f in sort(files)
        push!(table, "| $f | File |  | [$f]($rel_web/$f) |")
    end
    return join(table, "\n")
end

"Recursively generate index.md files for all folders in SRC_DIR"
function generate_recursive_index(src_path::String, doc_path::String, rel_web::String)
    mkpath(doc_path)

    index_path = joinpath(doc_path, "index.md")
    open(index_path, "w") do f
        println(f, "# `", basename(src_path), "`")

        println(f, "\n## Directory Contents\n")
        println(f, list_directory_table(src_path, rel_web))

        readme_path = joinpath(src_path, "README.md")
        if isfile(readme_path)
            println(f, "\n## README.md\n")
            println(f, read(readme_path, String))
        end
    end

    for d in sort(filter(name -> isdir(joinpath(src_path, name)), readdir(src_path)))
        generate_recursive_index(joinpath(src_path, d), joinpath(doc_path, d), joinpath(rel_web, d))
    end
end

"Copy root-level README.md to docs/index.md"
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

function main()
    mkpath(DOCS_DIR)
    generate_recursive_index(SRC_DIR, joinpath(DOCS_DIR, SRC_DIR), SRC_DIR)
    copy_readme_to_index()
    println("[DONE] Documentation generated under docs/src with nested structure.")
end

main()