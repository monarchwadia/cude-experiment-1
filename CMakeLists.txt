cmake_minimum_required(VERSION 3.27)
project(CudaExperiment1 CUDA CXX)
include(CheckLanguage)
check_language(CUDA)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_language(CUDA)
add_executable(main main.cu)
