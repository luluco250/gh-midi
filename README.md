# gh-midi

Toy program that converts game controller inputs to MIDI outputs.

Currently adapted for use with Guitar Hero drums and guitar, though not perfect.

# Compiling
This project uses the Meson build system and depends on the fmt, RtMidi and SDL2
libraries being available on the system.
```sh
meson build
cd build
meson compile
```

# Usage
```
gh-midi <--list-ports|--list-inputs|[options] --type <drums|guitar>>
-p --port       The MIDI port number to output to.
-i --input      The game controller number to take input from.
--list-ports    List available ports and quit.
--list-inputs   List available controllers and quit.
--type          Which instrument to map for, either "drums" or "guitar".
```
