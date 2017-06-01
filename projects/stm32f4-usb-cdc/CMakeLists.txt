PROJECT(stm32f4-usb-cdc)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ENABLE_LANGUAGE(ASM)

FIND_PACKAGE(CMSIS REQUIRED)
FIND_PACKAGE(STM32HAL COMPONENTS gpio tim usb pcd REQUIRED)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMSIS_INCLUDE_DIRS}
    ${STM32HAL_INCLUDE_DIR}
    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc

)

SET(PROJECT_SOURCES
    main.c
    stm32f4_discovery.c
    syscalls.c
    usb_device.c
    usbd_cdc_if.c
    usbd_conf.c
    usbd_desc.c
    stm32f4xx_it.c

    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c

    ${STM32Cube_DIR}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES} ${CMSIS_SOURCES} ${STM32HAL_SOURCES})

STM32_SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME})
STM32_ADD_HEX_BIN_TARGETS(${CMAKE_PROJECT_NAME})

add_custom_target(deploy
    COMMAND sudo openocd -f board/stm32f4discovery.cfg -c "program ${CMAKE_PROJECT_NAME} verify reset exit"
    DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
