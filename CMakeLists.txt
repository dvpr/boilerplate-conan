cmake_minimum_required(VERSION 3.0.0)
project(ConanFirst VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ConanFirst main.cpp)
target_link_libraries(ConanFirst ${CONAN_LIBS})