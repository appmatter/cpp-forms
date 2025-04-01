
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

echo "✅ Done!"