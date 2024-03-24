cmake_minimum_required(VERSION 3.27)
project(CudaExperiment1 CUDA CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CheckLanguage)
check_language(CUDA)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_language(CUDA)
add_executable(main main.cpp gpu.cu)

# ImgUI
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/imgui)
set(IMGUI_BACKENDS ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp ${IMGUI_PATH}/backends/imgui_impl_sdlrenderer2.cpp)
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp) 
add_library("ImGui" STATIC ${IMGUI_SOURCES} ${IMGUI_BACKENDS})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})

# Link SDL2
# target_link_libraries(main ${SDL2_LIBRARIES} ImGui)
target_link_libraries(main ImGui ${SDL2_LIBRARIES})
target_include_directories(main PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})