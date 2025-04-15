import Pkg
Pkg.activate(".")
Pkg.instantiate()

using Markdown
using Dates
using Printf
using Glob

# === Configuration ===
const SRC_DIR = "src"                        # Folder containing raw course files
const DOCS_DIR = "docs"                      # Output folder for MkDocs
const BASE_URL = "/UNITN.BSc"               # Base URL used for absolute links in GitHub Pages

function capitalize_title(text::String)
    return join([uppercasefirst(lowercase(w)) for w in split(text, r"[ _]+")], " ")
end

"Generate a Markdown list of files in the given directory"
function list_files_md(path::String, rel_link::String)
    entries = readdir(path)
    files = filter(f -> isfile(joinpath(path, f)), entries)
    return join(["- [$f]($rel_link/$f)" for f in sort(files)], "\n")
end

"Recursively generate index.md files for all folders in SRC_DIR"
function generate_recursive_index(src_path::String, doc_path::String, rel_web::String)
    mkpath(doc_path)

    entries = readdir(src_path)
    dirs = filter(name -> isdir(joinpath(src_path, name)), entries)
    files = filter(name -> isfile(joinpath(src_path, name)), entries)

    index_path = joinpath(doc_path, "index.md")
    open(index_path, "w") do f
        println(f, "# Directory: ", basename(src_path))
        if !isempty(dirs)
            println(f, "\n## Subdirectories\n")
            println(f, "| Name | Description | Link |")
            println(f, "|------|-------------|------|")
            for d in sort(dirs)
                subreadme = joinpath(src_path, d, "README.md")
                has_readme = isfile(subreadme)
                desc = has_readme ? first(split(read(subreadme, String), "\n")) : ""
                println(f, "| ", d, " | ", desc, " | [Open]($d/) |")
            end
        end

        if !isempty(files)
            println(f, "\n## Files\n")
            println(f, list_files_md(src_path, "../$rel_web"))
        end

        # Copy README.md content if exists
        readme_path = joinpath(src_path, "README.md")
        if isfile(readme_path)
            println(f, "\n## README\n")
            println(f, read(readme_path, String))
        end
    end

    # Recurse into subdirectories
    for d in dirs
        generate_recursive_index(joinpath(src_path, d), joinpath(doc_path, d), joinpath(rel_web, d))
    end
end

"Generate the top-level site index from root README.md"
function generate_top_index()
    src = "README.md"
    dest = joinpath(DOCS_DIR, "index.md")
    if isfile(src)
        cp(src, dest; force=true)
        println("[INFO] Copied top-level README.md to index.md")
    else
        println("[WARN] No top-level README.md found")
    end
end

function main()
    mkpath(DOCS_DIR)
    generate_recursive_index(SRC_DIR, joinpath(DOCS_DIR, SRC_DIR), SRC_DIR)
    generate_top_index()
    println("[DONE] Recursive documentation structure generated under docs/src/")
end

main()