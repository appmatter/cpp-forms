#!/usr/bin/env bash

set -e

meson test -C build --suite=form --verbose \
  --test-args='--reporter console --durations yes'


echo "✅ Done!"