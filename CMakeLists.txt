cmake_minimum_required(VERSION 3.14)
project(mapgenerators VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mapgenerators src/generator.cpp)

target_include_directories(mapgenerators PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

add_library(mapgenerators::mapgenerators ALIAS mapgenerators)

