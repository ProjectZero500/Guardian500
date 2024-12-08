cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Guardian)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Guardian src/main.cpp src/entropy.cpp src/resource.cpp)

# Include directories
target_include_directories(Guardian PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set the output directory for the executable
set_target_properties(Guardian PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)