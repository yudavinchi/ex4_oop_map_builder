/*
Holds the most premetive basic button
*/

#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	//C-tors:
	Button();
	Button(sf::Vector2f& vector, int height, int width);
protected:

	//Members:
	sf::Vector2f m_position;
	float m_width;
	float m_height;
};
