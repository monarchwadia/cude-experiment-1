# Initial Setup

Install `libsdl2-dev`

You'll also need `CMake`

## Building imgui 

There is a git submodule `imgui` that is a clone of https://github.com/ocornut/imgui. This will need to be pulled via the git submodule system too.

```
TODO: build instructions for imgui
```

## Building sdl

There is a git submodule `sdl` that is a clone of SDL2. We need to build that.

You'll have to set the built path as shown below. A good place to put it would be in `./sdl/built` but you'll have to refer to it with an absolute path.

```
SDL_BUILT_PATH=<absolute path to where you want the built binaries to go>
cd sdl
mkdir build
cd build
../configure --prefix $SDL_BUILT_PATH
make
make install
```

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