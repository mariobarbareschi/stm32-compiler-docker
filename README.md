[![Build Status](https://travis-ci.org/mariobarbareschi/stm32-compiler-docker.svg?branch=master)](https://travis-ci.org/mariobarbareschi/stm32-compiler-docker) [![](https://images.microbadger.com/badges/image/mariobarbareschi/stm32-compiler.svg)](https://microbadger.com/images/mariobarbareschi/stm32-compiler "Get your own image badge on microbadger.com")
# stm32-compiler-docker
A Docker image project for compiling STM32 C/C++ projects (currently, this supports STM32F4 only)

## About ##
This project aims to define a Docker image with all you need to compile embedded software for STM32F4 devices and develop applications by means of cross-compilation.
It uses the GNU ARM GCC compiler suite, installed over the Ubuntu 16.04, and the CMake project developed by ObKo, the [stm32-cmake](https://github.com/ObKo/stm32-cmake)
Unfortunately, STMicroelectronics does not provide a direct repository from which we can download the CubeMX projects: at your disposal, in this repository, you have the support for only the STM32F4 discovery board.

## Requirements ##
Do not worry about requirements: just install [Docker](https://www.docker.com) for your operating system

## How to get the docker image ##

    git clone https://github.com/mariobarbareschi/stm32-compiler-docker
    cd stm32-compiler-docker
    docker build . -t <NAME>

Once completed, you should have a docker image named <name>, check it by running

    docker images

Alternatively, if you feel very lazy, check out the docker image by directly pulling it from docker hub

    docker pull mariobarbareschi/stm32-compiler

## How to use the docker image ##
To have an interactive bash interface with the docker image, simply run

    docker run -it -v /path/to/host/folder:/path/to/container/folder <NAME>

## Run examples ##
This repository is released with some examples in the projects folder.
Try them by sharing the folder project with the docker container as follows:

    docker run -it -v $PWD/projects:/home/embedded/projects mariobarbareschi/stm32-compiler
    
## Flashing the board ##
Once compilation succeeds, the binary/elf file under build directory are ready to be flashed onto your board.
Some tools maybe employed, dependind on the operating system of on which you are running this project.
For MS Windows, you can install the official ST-link utility.
Alternatively, for all the OSs, check out the OpenOCD software.

### LICENSE ###
--------

* [GPLV3.0](https://www.gnu.org/licenses/licenses.html)

### Contributing ###
----------

Github is for social coding: if you want to write code, I encourage contributions through pull requests from forks of this repository.
