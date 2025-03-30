#!/usr/bin/env bash

set -e

if ! command -v clang-format &> /dev/null; then
  echo "⚠️ clang-format not found, skipping. Install with: sudo apt install clang-format"
  exit 1
fi

echo "🧼 Running clang-format..."
clang-format -i \
  $(find include src tests -name '*.cpp' -o -name '*.hpp')

# run clang-tidy if configured
if command -v clang-tidy &> /dev/null; then
echo "🔍 Running clang-tidy..."
clang-tidy $(find src -name '*.cpp') -- -Iinclude || true
else
  echo "⚠️ clang-tidy not found, skipping. Install with: sudo apt install clang-tidy"
fi

echo "✅ Done!"