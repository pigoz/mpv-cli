project('mpv-cli', 'c')

deps = [
  dependency('mpv'),
  dependency('sdl2'),
]

sources = ['src/keycodes.c', 'src/gamepad.c', 'src/eventloop.c']

executable('mpv-cli',
  sources + ['src/main.c'],
  dependencies: deps)
