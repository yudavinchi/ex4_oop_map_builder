#pragma once
#include <vector>



class Map
{
	Map(int m_width, int m_height, int size_of_char);
	void insert(int x, int y, char character);




private:
	//hold the map
	//will hold the size of each char (the font) - so we can calcualte the size of the map 
	int size_of_char;
	//vector of vectors
	std::vector <std::vector<char>> m_map;
	int m_width;
	int m_height;

};