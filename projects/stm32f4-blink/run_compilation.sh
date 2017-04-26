#!/bin/bash
if [ -d ./build ]; then
  rm -R -f ./build;
fi
mkdir build
cd build
cmake -DSTM32_CHIP=STM32F407VGT6 -DCMAKE_TOOLCHAIN_FILE=/opt/cmake/gcc_stm32.cmake -DCMAKE_BUILD_TYPE=Debug -DSTM32Cube_DIR=/opt/STM32Cube_FW_F4_V1.11.0/ ..
make -j2


