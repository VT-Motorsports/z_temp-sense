# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

# Generates compile_commands.json for clangd LSP support.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(vcu)

# include/ is the single root for all headers.
# Use prefixed includes for subfolders: #include "threads/APPS.h", #include "can_decoders/dti_decoders.h"
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Gather all C and C++ source files under src/ recursively (picks up subfolders automatically).
file(GLOB_RECURSE APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

target_sources(app PRIVATE ${APP_SOURCES})

target_compile_options(app PRIVATE
    -Wall
    -Wextra
    -Wno-unused-parameter
)
