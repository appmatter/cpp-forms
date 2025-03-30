#!/usr/bin/env bash

set -e

BUILD_DIR="build"
TEST_BIN="${BUILD_DIR}/tests/test_form"

# Ensure build exists
if [ ! -d "$BUILD_DIR" ]; then
  echo "🔧 No build directory found. Running meson setup..."
  meson setup "$BUILD_DIR"
fi

# Build the tests
echo "🔨 Building..."
ninja -C "$BUILD_DIR"

# Run your tests only (skip subproject tests)
if [ -f "$TEST_BIN" ]; then
  echo "🚀 Running tests: $TEST_BIN"
  "$TEST_BIN" --reporter console --success --durations yes
else
  echo "❌ Test binary not found: $TEST_BIN"
  exit 1
fi

echo "✅ Done! Tests passed."