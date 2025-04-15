import Pkg
Pkg.activate(".")
Pkg.instantiate()
Pkg.add("YAML")
Pkg.add("XLSX")
Pkg.add("StringEncodings")

using YAML
using Dates
using Printf
using XLSX
using StringEncodings

const SRC_DIR = "src"
const DOCS_DIR = "docs"
const COURSES_DIR = joinpath(DOCS_DIR, "courses")
const BASE_URL = "/UNITN.BSc"

const CP1252_MAP = Dict{UInt8, Char}(
    0x80 => '€',   # Euro Sign
    0x82 => '‚',   # Single Low-9 Quotation Mark
    0x83 => 'ƒ',   # Latin Small Letter F with Hook
    0x84 => '„',   # Double Low-9 Quotation Mark
    0x85 => '…',   # Horizontal Ellipsis
    0x86 => '†',   # Dagger
    0x87 => '‡',   # Double Dagger
    0x88 => 'ˆ',   # Modifier Letter Circumflex
    0x89 => '‰',   # Per Mille Sign
    0x8A => 'Š',   # Latin Capital Letter S with Caron
    0x8B => '‹',   # Single Left-Pointing Angle Quotation Mark
    0x8C => 'Œ',   # Latin Capital Ligature OE
    0x8E => 'Ž',   # Latin Capital Letter Z with Caron
    0x91 => '‘',   # Left Single Quotation Mark
    0x92 => '’',   # Right Single Quotation Mark
    0x93 => '“',   # Left Double Quotation Mark
    0x94 => '”',   # Right Double Quotation Mark
    0x95 => '•',   # Bullet
    0x96 => '–',   # En Dash
    0x97 => '—',   # Em Dash
    0x98 => '˜',   # Small Tilde
    0x99 => '™',   # Trade Mark Sign
    0x9A => 'š',   # Latin Small Letter S with Caron
    0x9B => '›',   # Single Right-Pointing Angle Quotation Mark
    0x9C => 'œ',   # Latin Small Ligature oe
    0x9E => 'ž',   # Latin Small Letter Z with Caron
    0x9F => 'Ÿ'    # Latin Capital Letter Y with Diaeresis
)

const HEX_DIGITS = "0123456789abcdef"

const LANGUAGE_MAP = Dict(
    "jl"   => "julia",
    "py"   => "python",
    "rb"   => "ruby",
    "c"    => "c",
    "h"    => "c",
    "cpp"  => "cpp",
    "hpp"  => "cpp",
    "java" => "java",
    "js"   => "javascript",
    "ts"   => "typescript",
    "html" => "html",
    "xml"  => "xml",
    "json" => "json",
    "md"   => "markdown",
    "csv"  => "plaintext",   # treat CSV as plain text for highlighting
    "txt"  => "plaintext",
    "sh"   => "bash",
    "bat"  => "batch",
    "go"   => "go",
    "rs"   => "rust"
    # ... add more as needed
)

function escape_text_to_html(text::String)::String
    # Normalize line breaks: convert CRLF and lone CR to "\n"
    text = replace(text, "\r\n" => "\n")
    text = replace(text, "\r" => "\n")
    # Build escaped result
    local io = IOBuffer()
    for c in text
        # Special HTML characters
        if c == '&'
            write(io, "&amp;")
        elseif c == '<'
            write(io, "&lt;")
        elseif c == '>'
            write(io, "&gt;")
        # Preserve common whitespace
        elseif c == '\n' || c == '\t'
            write(io, c)
        # Escape control characters (ASCII 0x00–0x1F, 0x7F)
        elseif c ≤ '\x1f' || c == '\x7f'
            @assert sizeof(c) == 1  # c is in Basic Multilingual Plane control range
            # Write as \xHH
            code = UInt8(c)%0x100  # codepoint in 0-255 range
            hi = (code >> 4) & 0xF
            lo = code & 0xF
            write(io, "\\x", HEX_DIGITS[hi+1], HEX_DIGITS[lo+1])
        else
            # Other characters (including non-ASCII letters, symbols) can be written directly.
            # They will be UTF-8 encoded in the output, which is fine.
            write(io, c)
        end
    end
    return String(take!(io))
end

function escape_bytes_to_html(bytes::Vector{UInt8})::String
    local io = IOBuffer()
    local i = 1
    while i <= length(bytes)
        b = bytes[i]
        if b == 0x0A  # LF
            write(io, '\n')
        elseif b == 0x09  # TAB
            write(io, '\t')
        elseif b == 0x0D  # CR
            # Convert CR to newline (avoid double newlines for CRLF handled below)
            write(io, '\n')
            # If this CR is followed by LF, skip the LF to prevent duplicate newlines
            if i < length(bytes) && bytes[i+1] == 0x0A
                i += 1  # skip the following LF
            end
        elseif b == 0x26  # '&'
            write(io, "&amp;")
        elseif b == 0x3C  # '<'
            write(io, "&lt;")
        elseif b == 0x3E  # '>'
            write(io, "&gt;")
        elseif 0x20 <= b <= 0x7E
            # Printable ASCII (space through ~, except handled &<>) can be written directly
            write(io, Char(b))
        elseif 0xA0 <= b <= 0xFF
            # Extended ASCII (Latin-1 range). These map to Unicode directly (e.g. 0xA0 -> NBSP).
            write(io, Char(b))
        elseif 0x80 <= b <= 0x9F
            # Windows-1252 special range
            if haskey(CP1252_MAP, b)
                write(io, CP1252_MAP[b])  # mapped to a Unicode character
            else
                # Undefined control (0x81, 0x8D, 0x8F, 0x90, 0x9D)
                # Escape as \xHH
                hi = (b >> 4) & 0xF
                lo = b & 0xF
                write(io, "\\x", HEX_DIGITS[hi+1], HEX_DIGITS[lo+1])
            end
        else
            # Covers 0x00–0x1F (except \t,\n,\r handled) and 0x7F.
            hi = (b >> 4) & 0xF
            lo = b & 0xF
            write(io, "\\x", HEX_DIGITS[hi+1], HEX_DIGITS[lo+1])
        end
        i += 1
    end
    return String(take!(io))
end

function detect_language(file::AbstractString)::String
    ext = lowercase(splitext(file)[2])  # get ".ext"
    if startswith(ext, ".")
        ext = ext[2:end]  # drop leading dot
    end
    return get(LANGUAGE_MAP, ext, "plaintext")
end

function get_file_preview(file::AbstractString; max_bytes::Int=100_000)::String
    # Read file as raw bytes (to handle any encoding)
    bytes = read(file)  # Vector{UInt8}
    # Optionally truncate content for preview if it's very large
    local truncated = false
    if length(bytes) > max_bytes
        bytes = bytes[1:max_bytes]
        truncated = true
    end

    # Try to decode as UTF-8 text
    local content_html::String
    try
        # If bytes form valid UTF-8, create a Julia String (which is always UTF-8 internally)
        local text = String(bytes)  # will throw if invalid UTF-8 sequence
        content_html = escape_text_to_html(text)
    catch
        # If UTF-8 decoding fails, fall back to byte-wise escaping (treat as possibly Windows-1252)
        content_html = escape_bytes_to_html(bytes)
    end

    # Wrap the escaped content in an HTML <pre><code> block with appropriate class
    local lang = detect_language(file)
    # Start code block
    local html = "<pre><code class=\"language-$lang\">$content_html"
    # If truncated, add an indicator line (inside the code block or as a note below)
    if truncated
        # Ensure the content ends with a newline before adding the truncation notice
        if !endswith(html, "\n")
            html *= "\n"
        end
        html *= "... (truncated) ...\n"
    end
    html *= "</code></pre>"

    return html
end

function clean_generated_md_files()
    println("[INFO] Cleaning old generated *.md files...")

    for (root, _, files) in walkdir(COURSES_DIR)
        for file in files
            file_path = joinpath(root, file)

            # 识别并删除双扩展文件，如 xxx.csv.md、xxx.txt.md、xxx.py.md 等
            if occursin(r"\.\w+\.md$", file)
                println("[CLEAN] Removing legacy double-extension file: ", file_path)
                rm(file_path; force=true)
                continue
            end

            # 删除普通的冗余 .md 文件（排除 index.md 和 *_preview.md）
            if endswith(file, ".md") &&
               !(endswith(file, "_preview.md") || file == "index.md")
                println("[CLEAN] Removing unwanted: ", file_path)
                rm(file_path; force=true)
            end
        end
    end

    # 删除所有空目录（从最深层往上删）
    function delete_empty_dirs(path)
        for (root, dirs, _) in walkdir(path; topdown=false)
            for d in dirs
                full_d = joinpath(root, d)
                if isempty(readdir(full_d))
                    println("[CLEAN] Removing empty directory: ", full_d)
                    rm(full_d; force=true, recursive=true)
                end
            end
        end
    end

    delete_empty_dirs(COURSES_DIR)
end

function prettify_name(text::AbstractString)
    cleaned = replace(replace(String(text), "_" => " "), "-" => " ")
    return join([uppercasefirst(lowercase(w)) for w in split(cleaned)], " ")
end

function extract_course_info(name::String)
    parts = split(name, "_", limit=3)
    return length(parts) < 3 ? nothing : (id=parts[1], prof=parts[2], title=parts[3])
end

function human_readable_size(size::Integer)
    size < 1024 && return "$size B"
    size < 1024^2 && return @sprintf("%.1f KB", size / 1024)
    size < 1024^3 && return @sprintf("%.1f MB", size / 1024^2)
    return @sprintf("%.1f GB", size / 1024^3)
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

function safe_read_text(file_path::String)
    bytes = read(file_path)
    try
        return String(bytes)
    catch
        try
            return String(bytes, enc"Windows-1252")
        catch
            return nothing
        end
    end
end

function safe_preview_csv(file_path::String, max_lines::Int=64)
    try
        # 手动读取为字节，再尝试解码为 UTF-8 或 fallback 为 Windows-1252
        bytes = read(file_path)
        content = try
            String(bytes)  # 尝试 UTF-8
        catch
            String(bytes, enc"Windows-1252")  # fallback 编码
        end
        lines = split(content, '\n')
        preview = join(first(lines, max_lines), "\n")
        return "```csv\n$preview\n```"
    catch e
        return "_CSV preview not available due to encoding issues: $(e)_"
    end
end

function safe_preview_xlsx(file_path::String; max_rows::Int=64)
    try
        XLSX.openxlsx(file_path) do xf
            sheet = first(values(xf))
            content = ""
            for row in 1:min(max_rows, XLSX.nrows(sheet))
                values = [XLSX.getvalue(sheet, row, col) for col in 1:XLSX.ncols(sheet)]
                content *= join(values, ", ") * "\n"
            end
            return "```csv\n$content```"
        end
    catch e
        return "_XLSX preview not available: $(e)_"
    end
end

function generate_file_page(file::AbstractString, docs_dir::AbstractString, base_dir::AbstractString)
    # Determine output path (mirror directory structure, add ".md" extension to file name)
    local rel_path = relpath(file, base_dir)
    # Include original file extension in the output filename to avoid name collisions
    local out_path = joinpath(docs_dir, rel_path * ".md")
    mkpath(dirname(out_path))  # ensure the output directory exists

    # Generate the content preview block
    local preview_block = get_file_preview(file)

    # Construct the Markdown content for the file page.
    # We include a heading with the file name, and then the content preview block.
    local title = basename(file)
    local md_content = "# File: $title\n\n$preview_block\n"

    # Write the markdown content to the output file (as UTF-8).
    open(out_path, "w") do f
        write(f, md_content)
    end
end

function generate_index_page(dir::AbstractString, docs_dir::AbstractString, base_dir::AbstractString)
    local entries = sort(filter(x -> !startswith(basename(x), "."), readdir(dir, join=true)))
    # Prepare output path for index.md in this directory
    local rel_path = relpath(dir, base_dir)
    local index_out = joinpath(docs_dir, rel_path, "index.md")
    mkpath(dirname(index_out))

    # Start constructing index content
    local buffer = IOBuffer()
    write(buffer, "# Index of `", basename(dir), "`\n\n")

    for entry in entries
        if isdir(entry)
            # Subdirectory: list as a link to its index page
            local subname = basename(entry)
            write(buffer, "- **[", subname, "](./", subname, "/index.md)**\n")
        elseif isfile(entry)
            local fname = basename(entry)
            # List file as a link to its own page
            write(buffer, "- **[", fname, "](./", fname * ".md", ")**\n")
            # Embed a short preview (few KB) of the file content under the list item
            local preview = get_file_preview(entry; max_bytes=1024)  # smaller preview for index
            # Indent the preview HTML block by 4 spaces so it renders as part of the list item
            for line in eachline(preview)
                write(buffer, "    ", line, "\n")
            end
            write(buffer, "\n")  # blank line after each item for separation
        end
    end

    # Write the index markdown file
    open(index_out, "w") do f
        write(f, String(take!(buffer)))
    end
end

function generate_docs(input_dir::AbstractString, output_dir::AbstractString)
    # Recursively process directories and files
    local function process_dir(dir::AbstractString)
        # Generate pages for all files in this directory
        for entry in sort(filter(x -> !startswith(basename(x), "."), readdir(dir, join=true)))
            if isfile(entry)
                generate_file_page(entry, output_dir, input_dir)
            end
        end
        # Recurse into subdirectories
        for entry in sort(filter(x -> !startswith(basename(x), "."), readdir(dir, join=true)))
            if isdir(entry)
                process_dir(entry)
            end
        end
        # Finally, create an index.md for this directory
        generate_index_page(dir, output_dir, input_dir)
    end

    mkpath(output_dir)
    process_dir(input_dir)
end

if abspath(PROGRAM_FILE) == @__FILE__
    if length(ARGS) < 2
        println("Usage: julia generate_docs.jl <input_dir> <output_dir>")
    else
        generate_docs(ARGS[1], ARGS[2])
        println("Documentation generated successfully.")
    end
end

function generate_courses_index(course_dirs::Vector{String})
    path = joinpath(COURSES_DIR, "index.md")
    open(path, "w") do f
        println(f, "# Courses")
        println(f, "\n")
        println(f, "| Course | ID | Professor | Last Modified |")
        println(f, "|--------|----|-----------|---------------|")
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

function list_directory_table(src_path::String, rel_web::String, target_dir::String, course_info)
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
        full_path = joinpath(src_path, d)
        name = prettify_name(f)
        size_str = human_readable_size(stat(full_path).size)
        mtime = Dates.format(Dates.unix2datetime(stat(full_path).mtime), "yyyy-mm-dd")
        # 生成每个文件页面
        generate_file_page(full_path, target_dir, rel_web)
        fname_md = replace(f, "." => "_") * "_preview.md"
        push!(table, "| [$name]($fname_md) | File | $size_str | $mtime |")
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

        println(f, list_directory_table(course_dir, rel_web, target_dir, course_info))

        readme_path = joinpath(course_dir, "README.md")
        if isfile(readme_path)
            println(f, "\n")
            println(f, read(readme_path, String))
        end
    end

    for f in sort(files)
        full_path = joinpath(course_dir, f)
        ext = lowercase(splitext(f)[2])

        if f == "README.md"
            continue
        end

        generate_file_page(full_path, target_dir, rel_web)
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

    clean_generated_md_files()  # ← 加在一开始

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