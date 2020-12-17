#include "Map.h"


Map::Map(int width, int height, int size_of_char):
	m_width(width), m_height(height),size_of_char(size_of_char)
{
	std::vector <std::vector<char> > map;
	map.resize(height);

	//setting sizes
	for (int i = 0; i < height; ++i)
	{
		map[i].resize(width);
	}

	m_map = map;

}

void Map::insert(int x, int y, char character) {

	m_map[x][y] == character;
}