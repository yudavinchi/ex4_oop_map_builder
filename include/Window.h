#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window(int width, int height, std::string name);
	int get_width();
	int get_height();
	void draw_ui();
    std::string get_name();

private:
	int m_width;
	int m_height;
	std::string m_name;
};