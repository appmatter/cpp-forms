project('cpp-forms', 'cpp')

cpp_forms_dirs = include_directories('include')

cpp_forms_dep = declare_dependency(
    include_directories: cpp_forms_dirs,
)

meson.override_dependency('cpp-forms', cpp_forms_dep)

if not meson.is_subproject()
    subdir('tests')
endif
