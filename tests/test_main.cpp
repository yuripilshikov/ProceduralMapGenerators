#include <catch2/catch_test_macros.hpp>
#include "../include/generator.h"

TEST_CASE("Add correct", "[math]")
{
	REQUIRE(lib_add(2, 2) == 4);
	REQUIRE(lib_add(-1, 1) == 0);	
}

TEST_CASE("Create array m x n", "[map]")
{
	REQUIRE(createRandomMap(10, 10).size() == 100);
}
