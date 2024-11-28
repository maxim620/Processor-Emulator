cmake_minimum_required(VERSION 3.10)

project(ProcessorEmulator)

# Укажите все исходные файлы
set(SOURCES
    main.c
    processor.c
    instruction_handlers.c
)

# Добавьте директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR})

add_executable(ProcessorEmulator ${SOURCES})

