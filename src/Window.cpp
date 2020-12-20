#include "Window.h"

//------------------------------C-tors---------------------------
Window::Window(int width, int height, std::string name)
	: m_width(width), m_height(height), m_name(name)
{}
//---------------------------------------------------------------

//------------------------------Getters--------------------------
int Window::get_width()
{
	return m_width;
}
//---------------------------------------------------------------

int Window::get_height()
{
	return m_height;
}
//---------------------------------------------------------------

std::string Window::get_name()
{
	return m_name;
}
//---------------------------------------------------------------
