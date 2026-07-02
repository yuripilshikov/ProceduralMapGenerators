cmake_minimum_required(VERSION 3.14)
project(mapgenerators VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mapgenerators src/generator.cpp)

target_include_directories(mapgenerators PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

# Alias
add_library(mapgenerators::mapgenerators ALIAS mapgenerators)

# Catch2 part (for testing purposes)
include(FetchContent)
FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

enable_testing() # activates CTest
add_executable(unit_tests tests/test_main.cpp)
target_link_libraries(unit_tests PRIVATE mapgenerators Catch2::Catch2WithMain)

# Automatic tests, CTest
#include(ParseAndAddCatchTests) # old version
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(unit_tests)

