#!/usr/bin/env bash

set -e

# Requires `entr` (install with: sudo apt install entr)
# Usage: ./scripts/run_tests_watch.sh

# check if entr is installed
if ! command -v entr &> /dev/null; then
  echo "⚠️ entr not found, skipping"
  exit 1
fi

# Find source + test files and watch them
find src include tests -type f \( -name '*.cpp' -o -name '*.hpp' \) \
  | entr -c ./scripts/test.sh


echo "✅ Done!"