[![Image](https://github.com/yifen9/unitn-l31-lab/actions/workflows/image.yaml/badge.svg)](https://github.com/yifen9/unitn-l31-lab/actions/workflows/image.yaml)

```
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519

git config user.name yifen9
git config user.email mail@yifen9.li

git submodule update --init --recursive
git submodule update --recursive --remote

git pull origin main

git add .
git commit -m ""
git push origin main
```