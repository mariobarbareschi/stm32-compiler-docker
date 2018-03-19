#!/bin/bash

arm-none-eabi-gcc -I. -mthumb -fno-builtin -Og -g -o main.c.obj -c main.c

arm-none-eabi-gcc -I. -mthumb -x assembler-with-cpp -g -o startup_stm32f407xx.s.obj -c startup_stm32f407xx.s

arm-none-eabi-gcc -mthumb -fno-builtin -Og -g  -Wl,--gc-sections -Tstm32f4-flash-ram.ld main.c.obj startup_stm32f407xx.s.obj -o bare_bin

