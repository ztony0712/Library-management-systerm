cmake_minimum_required(VERSION 3.11.4)

project(library)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")


add_executable(library main.c interface.c global_management.c book_management.c user_management.c book_use.c)


install(TARGETS library RUNTIME DESTINATION bin)
