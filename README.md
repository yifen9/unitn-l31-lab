# UniTrento BSc 2024/2025

- Author: [Li Yifeng](https://yifen9.github.io)
- Example Website: [UNITN.BSc](https://yifen9.github.io/UNITN.BSc)

## Basic Info

By implement this, you can have exactly the same beautiful website as [mine](https://yifen9.github.io/UNITN.BSc), where you can share your own notes, your own codes and etc.

The adventage is that this can integrate into your notes perfectly, and **all the pages are generated automatically**, so you actually don't need to do anything after implement this. The only maintaining work is to upload more of your notes, and that's it.

More details will be updated frequently on [my blog](https://yifen9.github.io/2025/04/17/Get-a-Personal-UNITN.BSc) (e.g., how did I do all these things and etc.).

## Setup

Here I will only provide the minimum setup, feel free to modify more if you know what you are doing.

### Upload your repository

1. Firstly you need to have your own repository, create one.
2. Maybe you are already familiar with `Git`, but if not, I recommend you to use `GitHub Desktop`, which I have introduced once on [my blog](https://yifen9.github.io/2025/04/07/Get-a-Personal-Website/#get-github-desktop), but anyway, you need to manage to upload the whole file (files included in `UNITN.BSc.zip`) to your repository.

### GitHub Pages

1. Go to your repository.
2. Go to `Settings` -> `Code and automation` -> `Pages` -> `GitHub Pages` -> `Build and deployment`.
3. Set `Source` to `Deploy from a branch`.
4. Set `Branch` to `gh-pages/(root)`.
5. Click `Save`.

### `/scripts/generate_docs.jl`

```
function page_home_generate(path::String)
    ...
    <img src="https://count.himiku.com/get/@your-prefered-randomname?theme=rule34" alt="visitor count" />
    ...
end
```

```
const DIR_BASE_REPO = "https://github.com/your-github-username/UNITN.BSc/tree/main"
```

Where you need to replace `your-prefered-randomname` by any name you like and replace `your-github-username`.

> How do you know I use Julia?

### `/mkdocs.yml`

```
site_url: https://your-github-username.github.io/UNITN.BSc
```
Where replace it by your own GitHub username, obviously.

What's more, if you choose a different name for your repository, then you need to change `UNITN.BSc` as well.

> E.g., https://smith.github.io/UNITN.ICE

```
repo_url: https://github.com/your-github-username/UNITN.BSc
```
Same as above, replace `your-github-username` by your username, and possibly change `UNITN.BSc`

### Result

By visiting `https://your-github-username.github.io/your-reponame`, you should be able to see sth, if not, then checking the previous steps or simply let me notice.

## Usage

### Create new courses

Inside of `/src`, you can find some pregenerated folders for courses, for example, `146140_MARCHETTO_Computer_Programming_1`.

Similarly, if you want to add more courses, you need to follow the pattern, that is,

```
course-id_professor_course-name
```

> E.g., `146055_PUGLIESE_Calculus_1`

### Create new folders

Beside of courses, let's say you want to add a `Homework` section to your `146060_BONACCORSI_Probability`, then you simply create a folder inside of `/src/146060_BONACCORSI_Probability` then it's done.

By doing so, your directory tree would be look sth like this:

```
src
├── 146060_BONACCORSI_Probability
│   ├── Homework <- You created a folder!
│   └──...
└──...
```

### Create new notes

For example, you may want to write an introduction note of `146140_MARCHETTO_Computer_Programming_1`:

1. Go to `/src/146140_MARCHETTO_Computer_Programming_1`.
2. Create a `README.md`.
3. Write `README.md` in MarkDown syntax.
4. Done.

By doing so, your directory tree should be sth look like this:

```
src
├── 146140_MARCHETTO_Computer_Programming_1
│   ├── README.md <- Your note for CP1
│   └──...
└──...
```

Same method applys to any folder.

E.g., I want to write a note for my Probability Homework, then your directory tree should be sth look like this

```
src
├── 146140_MARCHETTO_Computer_Programming_1
│   ├── README.md
│   └──...
├── 146060_BONACCORSI_Probability
│   ├── Homework
│   │   ├── README.md <- Your note for Homework
│   │   ├── Week_1
│   │   │   └── W1_homework.pdf
│   │   └──...
│   └──...
└──...
```

### Uploading files

Same as creating new folders, you simply upload files to a directory, then it's automatically done.

> **Notice**: Though you can in theory create notes for every **folder**, but it's impossible to create notes for **files**

E.g.:

```
src
├── 146140_MARCHETTO_Computer_Programming_1
│   ├── README.md
│   └──...
├── 146060_BONACCORSI_Probability
│   ├── Homework
│   │   ├── README.md
│   │   ├── Week_1
│   │   │   └── W1_homework.pdf <- You uploaded a file!
│   │   └──...
│   └──...
└──...
```

By default, the file page would be sth look like [this page](https://yifen9.github.io/UNITN.BSc/courses/146060_BONACCORSI_Probability/Homework/W4/Q1.pdf), where you have a basic info section and an automatically generated preview section.

But unfortunately, not every type of file is supported for previewing.

### Delete courses, folders and files

Just delete.

### Commit changes

OK let's say you have done your work on writing notes, writing codes and so on, now you have everything in your `\src`.

Next step is to commit your changes to your nicely website, by pushing your chances to your repository, and then the chances to your websites **will be automatically done**.

## Credits

Made with [Material for MkDocs](https://squidfunk.github.io/mkdocs-material), powered by Julia (and me).
