#pragma once
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>  //for debug 

class Button
{
public:
	Button() = default;
	Button(sf::Vector2f& vector, int height, int width);


protected:

	sf::Vector2f m_position;

	float m_width;

	float m_height;
};
