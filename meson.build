project('gh-midi', 'cpp', default_options: [
	'cpp_std=c++20',
	'warning_level=3',
	'werror=true',
])

cmake = import('cmake')

fmt = dependency('fmt', version: '>=8.1.1')
rt_midi = dependency('rtmidi', version: '>=5.0.0')
sdl2 = dependency('sdl2', version: '>=2.0.22')

# argparse wrapper.
argparse_proj = cmake.subproject('argparse')
argparse = argparse_proj.dependency('argparse')

subdir('source')
executable('gh-midi', sources, dependencies: [
	argparse,
	fmt,
	rt_midi,
	sdl2,
])
