cmake_minimum_required(VERSION 3.27)
project(CudaExperiment1 CUDA CXX)

# Project settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(main main.cpp gpu.cu)

# CUDA
include(CheckLanguage)
check_language(CUDA)
enable_language(CUDA)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# ImgUI
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/imgui)
set(IMGUI_BACKENDS ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp ${IMGUI_PATH}/backends/imgui_impl_sdlrenderer2.cpp)
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp) 
add_library("ImGui" STATIC ${IMGUI_SOURCES} ${IMGUI_BACKENDS})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})

# Link the libraries
target_link_libraries(main ImGui ${SDL2_LIBRARIES})
target_include_directories(main PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})