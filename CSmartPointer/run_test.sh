#!/usr/bin/env bash
set -euo pipefail

exercise_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
temp_dir="$(mktemp -d)"
trap 'rm -rf "$temp_dir"' EXIT

# The original raw-pointer starter already prints the expected output. Check
# the ownership type as well as the program's behavior.
if ! grep -Eq '^[[:space:]]*(std::unique_ptr[[:space:]]*<[[:space:]]*DisplayABC[[:space:]]*>[[:space:]]+pemily|auto[[:space:]]+pemily[[:space:]]*=[[:space:]]*std::unique_ptr[[:space:]]*<[[:space:]]*DisplayABC[[:space:]]*>)' "$exercise_dir/main.cpp"; then
    echo 'Own Emily with a std::unique_ptr<DisplayABC>.' >&2
    exit 1
fi
if grep -Eq '^[[:space:]]*delete[[:space:]]+pemily[[:space:]]*;' "$exercise_dir/main.cpp"; then
    echo 'Remove the manual delete of pemily.' >&2
    exit 1
fi

"${CXX:-g++}" -std=c++17 -Wall -Wextra -pedantic "$exercise_dir/main.cpp" -o "$temp_dir/main"
"$temp_dir/main" > "$temp_dir/output"
printf '[1] Bill\n[2] Emily (chemistry)\nDestructing scientist: Emily\n' > "$temp_dir/expected"
diff -u "$temp_dir/expected" "$temp_dir/output"
echo 'CSmartPointer passed'
