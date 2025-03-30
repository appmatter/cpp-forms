# cpp-forms

Agnostic Forms for C++


## Features

- [x] Simple to use
- [x] Validation rules
- [x] Reset to original values
- [x] Dirty tracking


## Installation as a dependency

# Meson
To install cpp-forms you can use wrap files.


- Copy `cpp-forms.wrap.template` to `<your-project>/subprojects/cpp-forms.wrap`
  - If you need a specific version, edit the `cpp-forms.wrap` file to set the `version` to a specific commit hash or tag.
- To your `<your-project>/meson.build` file, add the following:
```meson
dependency('cpp-forms', fallback: ['cpp_forms', 'cpp_forms_dep'])
```





# Scripts (/scripts)

In the `/scripts` directory, you'll find a few scripts to help you get started.
The first time you use these scripts, you may need to make them executable with `chmod +x scripts/run_tests.sh`

- `setup.sh` - Setup the project for the first time
- `test.sh` - Run the tests
- `watch_test.sh` - Watch for changes and rerun tests on save (requires entr)
- `build` - Build the project
- `lint.sh` - Format and optionally run static analysis



# Running Tests

```bash
# Using /scripts/run_tests.sh
# on first run, you may need to make it executable with `chmod +x scripts/run_tests.sh`
./scripts/run_tests.sh

# Using /scripts/run_tests_watch.sh - watch for changes and rerun tests on save (requires entr)
./scripts/run_tests_watch.sh

# Using Meson - For a single suite with logging
meson test -C build --suite=form --verbose --test-args='--reporter console
```