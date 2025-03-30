catch2 = dependency('catch2', fallback: ['catch2', 'catch2_dep'])

test_exe = executable(
  'test_form',
  'test_main.cpp',
  'test_form.cpp',
  include_directories: include_directories('../include'),
  dependencies: [catch2],
)

test('form unit tests', test_exe, suite: 'form')


