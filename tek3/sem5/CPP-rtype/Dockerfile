FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive \
    LANG=C.UTF-8 \
    LC_ALL=C.UTF-8

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

WORKDIR /usr/src/
COPY . .

RUN rm -rf build && mkdir build && cd build && cmake .. && make

EXPOSE 8080

CMD ["./build/r-type_server", "8080"]
