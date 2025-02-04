cmake_minimum_required(VERSION 3.16.3)

# Project name and version
project(RPS_Game VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths relative to the build directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src) # Points to the src/ directory
set(BUILD_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/out)   # Points to the out/ directory under build/

# Include the src directory for header files
include_directories(${SOURCE_DIR})

# Gather all source files from the src directory
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
message(STATUS "Looking for source files in: ${SOURCE_DIR}")
message(STATUS "Found source files: ${SOURCES}")

# Stop if no sources are found
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src/. Check CMake path configuration.")
endif()

# Gathered files confirmation message
message(STATUS "Source files: ${SOURCES}")

# Add the executable using the gathered source files
add_executable(rps_executable ${SOURCES})

# Set the output directory for the executable
set_target_properties(rps_executable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_OUTPUT})

# Custom clean target (removes everything except CMakeLists.txt)
add_custom_target(clear
  COMMAND ${CMAKE_COMMAND} -E rm -rf *
  COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_SOURCE_DIR}/CMakeLists.txt
  COMMENT "Cleaning build directory (except CMakeLists.txt)"
)

# Custom clean target
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/out
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/obj
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Cleaning up build files."
)

# Custom run target (runs the executable after building)
add_custom_target(run
  COMMAND ${BUILD_OUTPUT}/rps_executable
  DEPENDS rps_executable
  COMMENT "Running the RPS game executable"
)

# Make 'run' dependent on 'clean' and 'configure'
add_custom_target(rebuild_and_run
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --clean-first
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target run
  COMMENT "Cleaning, building, and running the executable"
)

# Optionally, you can also make 'make all' trigger the build and run as needed:
add_dependencies(run rps_executable)
