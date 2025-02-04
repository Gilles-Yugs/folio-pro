# Use an official Ubuntu base image
FROM ubuntu:20.04

# Set environment variables to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    doxygen \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory to /RPS_Game
WORKDIR /RPS_Game

# Copy only necessary files into the container
COPY CMakeLists.txt CMakeLists.txt
COPY src/ src/

# Debugging: Check if files exist
RUN ls -l src/

# Ensure the build directory exists but is clean
RUN rm -rf build && mkdir build

# Set working directory to /RPS_Game/build
WORKDIR /RPS_Game/build

# Configure and compile the project
RUN cmake .. && cmake --build .

# Generate documentation using Doxygen (if a Doxyfile exists in the doc directory)
WORKDIR /RPS_Game/doc
RUN if [ -f Doxyfile ]; then doxygen Doxyfile; fi

# Set the entry point to a shell
CMD ["/bin/bash"]