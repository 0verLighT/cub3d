project(
  'cub3D',
  'c',
  license : 'MIT',
  meson_version: '>= 0.63.0',
  version : '0.0.1',
  default_options : ['warning_level=2']
)

cc = meson.get_compiler('c')

if cc.links('#include <math.h>\nint main(){log(0);}')
  m_dep = declare_dependency()
else
  m_dep = cc.find_library('m')
endif

sources = files(
  'src/main.c'
)

deps = [
  dependency('libft'),
  dependency('mlx'),
  m_dep,
]

inc = include_directories('includes')

executable(
  'cub3D',
  sources,
  include_directories : inc,
  dependencies : deps,
  install: true,
)
