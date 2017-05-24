# STM32-Compiler/Projects

Projects provided here are developed under CMake projects.
Following the strategy of ObKo project, you should provide to cmake some sensitive information, such as the toolchain-path, the CubeMX installation path, and so forth.

For having a practical usage of every example, within the docker image, you can run the run_compilation.sh script and, whenever you need, modify it for your needs.

## STM32F4-Blink

This example provides you a project involving GPIO and EXTI

## STM32F4-USB_CDC

This example implements a USB CDC device on the STM32F4 and sets the printf to work over the VCP port
