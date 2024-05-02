cmake_minimum_required(VERSION 3.24)
project(Ballrenderproject)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ballrenderproject src/main.cpp
        src/main.cpp
        src/point.cpp
        src/point.h
        src/point.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/C++ExternalLibs/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/C++ExternalLibs/SFML/include/SFML)
target_link_libraries(Ballrenderproject sfml-system sfml-window sfml-graphics sfml-audio)