cmake_minimum_required(VERSION 3.29.0)

project(scheduler_test)



set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

# set(CMAKE_VERBOSE_MAKEFILE OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../components/yas yas)

set(TEST_SOURCES
    ../src/main.c
)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE scheduler)



