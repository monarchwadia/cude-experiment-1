# Initial Setup

Install `libsdl2-dev`

You'll also need `CMake`

There is a git submodule `imgui` that is a clone of https://github.com/ocornut/imgui. This will need to be pulled via the git submodule system too.

# Then

```
cmake .
make
```

To run

```
bin/make
```

# Commands

Delete cache, rebuild, and run

```
rm CMakeCache.txt && cmake . && make && ./bin/main
```