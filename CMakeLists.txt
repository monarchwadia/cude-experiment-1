cmake_minimum_required(VERSION 3.27)
project(CudaExperiment1 CUDA CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CheckLanguage)
check_language(CUDA)

# find_package(SDL2 REQUIRED)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_language(CUDA)
add_executable(main main.cpp gpu.cu)
