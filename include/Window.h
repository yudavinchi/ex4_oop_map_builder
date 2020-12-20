/*
Class for holding the primetive window members
*/
#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window
{
public:
	//C-tors:
	Window(int width, int height, std::string name);

	//Getters:
	int get_width();
	int get_height();
    std::string get_name();

private:

	//Members:
	int m_width;
	int m_height;
	std::string m_name;
};