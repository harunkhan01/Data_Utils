cmake_minimum_required(VERSION 3.12)

project(data_utils)

add_executable(data)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(data
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/queue.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vector.c
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)