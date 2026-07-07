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

std::vector<int> smoothMap(int width, int height, 
	std::vector<int> const& map, int times)
{
	std::vector<int> smooth(map.size());
	int height = map.size() / width;

	for(int time = 0; time < times; ++time)
	{
		for(int x = 0; x < width; ++x)
		{
			for(int y = 0; y < height; ++y)
			{
				int floors = 0;
				int rocks = 0;

				for(int ox = -1; ox <= 1; ++ox)
				{
					for(int oy = -1; oy <= 1; ++oy)
					{
						if(x + ox < 0 
							|| x + ox >= width 
							|| y + oy < 0 
							|| y + oy >= height) 
								continue;
						if(map[x + ox + (y + oy) * width] == 0) ++floors;
						else ++ rocks;
					}
				}
				smooth[x + y * width] = floors >= rocks ? 0 : 1;
			}
		}
	}
	return smooth;
}
