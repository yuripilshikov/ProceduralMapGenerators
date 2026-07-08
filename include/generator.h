#pragma once
#include <iostream>
#include <vector>

void someFunc();

int lib_add(int a, int b);

/**
	\brief Creates random map of zeros and ones
	\param[in] width Desired width of map
	\param[in] height Desired height of map
	\return Created map (vector of ints, by value)
*/
std::vector<int> createRandomMap(int width, int height);

/**
	\brief Smoothes random map (Moore celluar automata algorythm)
	\param[in] width Desired width of map
	\param[in] height Desired height of map
	\param[in] map Random map to smooth
	\param[in] times How many times to smooth
*/
std::vector<int> smoothMap(int width, int height, 
	std::vector<int> const& map, int times);

/**
\brief Random walk algorythm. Good for islands and caves.
\param[in] width Desired width of the map
\param[in] height Desired height of the map
\param[in] steps Count of steps
*/
std::vector<int> randomWalk(int width, int height, int steps);
