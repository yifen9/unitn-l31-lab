#!/usr/bin/env bash
set -euo pipefail
lab="${1:-}"; ex="${2:-}"; op="${3:-}"
root="$(cd "$(dirname "$0")/.." && pwd)"
base="$root/src/$lab/tests/$ex"
mkdir -p "$base"

find_free_id() {
  i=0
  while [ -e "$base/$i" ]; do i=$((i+1)); done
  echo "$i"
}

prompt_case() {
  id="$1"
  dir="$base/$id"
  mkdir -p "$dir"
  echo "Paste INPUT, then Ctrl-D:"
  cat > "$dir/i.txt"
  echo "Paste EXPECTED OUTPUT, then Ctrl-D:"
  cat > "$dir/o.txt"
  echo "$id"
}

case "$op" in
  new)
    id="$(find_free_id)"
    prompt_case "$id"
    ;;
  re)
    cid="${4:-}"; [ -n "$cid" ] || { echo "usage: make test $lab $ex re <id>"; exit 1; }
    [ -d "$base/$cid" ] || { echo "no such case: $cid"; exit 1; }
    prompt_case "$cid"
    ;;
  rm)
    cid="${4:-}"; [ -n "$cid" ] || { echo "usage: make test $lab $ex rm <id>"; exit 1; }
    [ -d "$base/$cid" ] || { echo "no such case: $cid"; exit 1; }
    rm -rf "$base/$cid"
    echo "removed $cid"
    ;;
  *)
    echo "unknown op: $op"; exit 1;;
esac
