#!/bin/bash

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    unzip \
    locales \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libudev-dev \
    libopenal-dev \
    libogg-dev \
    libvorbis-dev \
    libflac-dev \
    libjpeg-dev \
    libfreetype6-dev \
    libpthread-stubs0-dev \
    libxcb1-dev \
    libx11-xcb-dev \
    libxcb-randr0-dev \
    libxcb-image0-dev \
    && locale-gen en_US.UTF-8

# Update package lists
sudo apt update

# Install C++ compiler
sudo apt install -y g++

# Install CMake
sudo apt install -y cmake

# Provide a link to Docker installation manual
echo "For Docker installation, please refer to: https://docs.docker.com/engine/install/"

echo "Dependencies installed successfully."