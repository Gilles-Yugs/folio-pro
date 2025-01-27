# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17
# Include directory
INCLUDES = -I./src
# Source files directory
SRC_DIR = ./src
# Object files directory
OBJ_DIR = ./build/obj
# Output directory
OUT_DIR = ./build/out
# Target executable
TARGET = $(OUT_DIR)/rps_game

# Find all .cpp files in SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Generate object file names by replacing .cpp with .o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: prepare $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES)

# Rule to compile .cpp files into .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

# Prepare the output and object directories
prepare:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OBJ_DIR)

# Clean up build artifacts
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)
	rm -rf $(OUT_DIR)
	rm -rf $(OBJ_DIR)

# Phony targets
.PHONY: all clean prepare