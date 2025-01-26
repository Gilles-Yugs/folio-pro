# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17
# Include directory
INCLUDES = -I../src
# Source files directory
SRC_DIR = ../src
# Output directory
OUT_DIR = ./out
# Target executable
TARGET = $(OUT_DIR)/rps_game

# Find all .cpp files in SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Generate object file names by replacing .cpp with .o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SRCS))

# Default target
all: prepare $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES)

# Rule to compile .cpp files into .o files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

# Prepare the output directory
prepare:
	@mkdir -p $(OUT_DIR)

# Clean up build artifacts
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
	rm -rf $(OUT_DIR)

# Phony targets
.PHONY: all clean prepare