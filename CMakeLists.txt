cmake_minimum_required(VERSION 3.10)
project(AudioController)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files from src directory
file(GLOB SRC_FILES src/*.cpp)

add_executable(AudioController ${SRC_FILES})
