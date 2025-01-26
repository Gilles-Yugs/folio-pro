# CMake configuration for Rock-Paper-Scissors Game

cmake_minimum_required(VERSION 3.27.2) # Minimum CMake version required

project(RPS_Game VERSION 1.0 LANGAUGES CXX) # Project name

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths
set(S)

# Set paths relative to the build directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src) # Point to src/
set(BUILD_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/out)  # Points to out/ under build/

# Include the src directory for header files
include_directories(${SOURCE_DIR})

# Gather all source files from the src directory
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp"))

# Add the executable using the gathered source files
add_executable(rps_executable ${SOURCES})

# Set the output directory for the executable
set_target_properties(rps_executable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_OUTPUT})
