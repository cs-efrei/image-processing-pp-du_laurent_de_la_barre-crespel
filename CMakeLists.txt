cmake_minimum_required(VERSION 3.30)
project(image_processing_gr7 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(image_processing_gr7
    functions.c
    functions.h
    main.c)
