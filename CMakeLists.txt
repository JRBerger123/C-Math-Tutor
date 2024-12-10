 # Minimum CMake version required
 cmake_minimum_required(VERSION 3.10)

 # Project name
 project(MathTutor)

 # Set the C++ standard
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_STANDARD_REQUIRED True)

 # Include directories (if required)
 include_directories(${CMAKE_SOURCE_DIR})

 # Add the executable for your project
 add_executable(MathTutor main.cpp MathTutor.cpp)
