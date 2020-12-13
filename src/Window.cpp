#include "Window.h"


Window::Window(int width, int height, std::string name)
	: m_width(width), m_height(height), m_name(name)
{}


int Window::get_width()
{
	return m_width;
}

int Window::get_height()
{
	return m_height;
}

std::string Window::get_name()
{
	return m_name;
}

void Window::draw_ui()
{
	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
}