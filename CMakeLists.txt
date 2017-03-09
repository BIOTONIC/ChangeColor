cmake_minimum_required(VERSION 3.6)
project(ChangeColor)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OPENGL")
set(GLFW3_LIBRARY "/usr/local/lib/libglfw.3.2.dylib")

set(SOURCE_FILES colorChanging.cpp)
add_executable(ChangeColor ${SOURCE_FILES})
target_link_libraries(ChangeColor ${GLFW3_LIBRARY})