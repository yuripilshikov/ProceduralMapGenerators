#include "generator.h"

void someFunc()
{
	std::cout << "Here be something!";
}

int lib_add(int a, int b)
{
	return a + b;
}

std::vector<int> createRandomMap(int width, int height)
{
	int size = width * height;
	std::vector<int> randomMap(size);
	for(int i = 0; i < size; ++i)
	{
		randomMap[i] = (std::rand() % 2 < 1 ? 0 : 1);
	}
	return randomMap;
}
