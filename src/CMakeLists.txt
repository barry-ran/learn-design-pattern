cmake_minimum_required(VERSION 3.16)

# 项目名称
set(PROJECT_NAME "all")

# 声明项目
project(${PROJECT_NAME})

# 设置可执行程序、静态库、动态库都生成在同一个目录
# 以便在windows上不需要修改运行可执行文件的路径（windows上exe要和依赖的dll在同一目录）
if(MSVC)
    # msvc不需要指定CMAKE_BUILD_TYPE，会自动生成到CMAKE_ARCHIVE_OUTPUT_DIRECTORY/[Debug/Release/..]
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
endif()

message(STATUS "CMAKE_BUILD_TYPE:${CMAKE_BUILD_TYPE}")

# c++11支持
set(CMAKE_CXX_STANDARD 11)

# 添加子项目
add_subdirectory(Behavior)
add_subdirectory(Create)
