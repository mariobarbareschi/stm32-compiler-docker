FROM ubuntu:16.04

MAINTAINER Mario Barbareschi <mario.barbareschi@unina.it>

RUN apt-get -y update && \
    apt-get -y install software-properties-common && \
    add-apt-repository -y ppa:team-gcc-arm-embedded/ppa && \
    apt-get -y update && \
    apt-get install -y gcc-arm-embedded && \
    apt-get -y install git cmake && \
    apt-get purge -y --auto-remove

#Unfortunately, there is not an official repository which anyone can easily access
#These files are copied from an instance of the STMCubeMX software for the F4 target
COPY STM32Cube_FW_F4_V1.11.0 /opt/STM32Cube_FW_F4_V1.11.0
#Thanks to ObKo, we get a cmake project for compiling projects by means of CMake (https://github.com/ObKo/stm32-cmake)
COPY cmake /opt/cmake

RUN useradd -ms /bin/bash embedded

USER embedded
