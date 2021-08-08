cmake_minimum_required(VERSION 3.19)
project(mlx C)

set(CMAKE_C_STANDARD 99)

find_library(LIB_TO_INCLUDE mlx /usr/local/lib/libmlx.a)
find_path (LIB_INCLUDES mlx.h /usr/local/include/mlx.h)
find_library(LIB_TO_INCLUDE_2 mlx /usr/local/lib/libmlx_Linux.a)
find_path (LIB_INCLUDES_2 mlx.h /usr/local/include/mlx.h)
add_executable(mlx main.c version1.c fractol.h)
target_link_libraries(mlx ${LIB_TO_INCLUDE})
target_link_libraries(mlx ${LIB_TO_INCLUDE_2})
