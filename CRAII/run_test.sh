#!/usr/bin/env bash
set -euo pipefail

exercise_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
temp_dir="$(mktemp -d)"
trap 'rm -rf "$temp_dir"' EXIT

"${CXX:-g++}" -std=c++17 -Wall -Wextra -pedantic "$exercise_dir/run_test.cpp" -o "$temp_dir/test"
"$temp_dir/test"
