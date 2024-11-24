cmake_minimum_required(VERSION 3.10)

project(ProcessorEmulator)

# Укажите все исходные файлы
set(SOURCES
    main.c
    processor.c
)

add_executable(ProcessorEmulator ${SOURCES})
