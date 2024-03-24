cmake_minimum_required(VERSION 3.27)
project(CudaExperiment1 CUDA CXX)

# Project settings
message("!!!! Project settings")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CUDA
message("!!!! CUDA")
include(CheckLanguage)
check_language(CUDA)
enable_language(CUDA)

# SDL2
message("!!!! SDL2")
set(SDL2_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/sdl/built/include/SDL2)
set(SDL2_LIBRARIES ${CMAKE_SOURCE_DIR}/sdl/built/lib/libSDL2.so)

if(NOT EXISTS ${SDL2_INCLUDE_DIRS})
    message(FATAL_ERROR "SDL2 include directory not found at ${SDL2_INCLUDE_DIRS}")
endif()

if(NOT EXISTS ${SDL2_LIBRARIES})
    message(FATAL_ERROR "SDL2 library not found at ${SDL2_LIBRARIES}")
endif()

# ImgUI
message("!!!! ImGui")
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/imgui)
set(IMGUI_BACKENDS ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp ${IMGUI_PATH}/backends/imgui_impl_sdlrenderer2.cpp)
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp) 
add_library("ImGui" STATIC ${IMGUI_SOURCES} ${IMGUI_BACKENDS})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})

# Link the libraries
message("!!!! Compiling")
add_executable(main main.cpp gpu.cu)
message("!!!! Linking libraries")
target_link_libraries(main ImGui ${SDL2_LIBRARIES})
target_include_directories(main PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})