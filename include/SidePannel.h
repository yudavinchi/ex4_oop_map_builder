#pragma once
#include <SFML/Graphics.hpp>


class SidePannel
{
public:
	//C-tors:
	SidePannel(float height_of_window, float widht_of_window);

	//Getters:
	int getWidth();

	//Helpers:
	void Draw(sf::RenderWindow& window);

private:
	
	//function and members for draw:
	sf::RectangleShape get_inner_rect();
	sf::RectangleShape get_outer_rect();
	sf::Vector2f m_location = sf::Vector2f(0, 0);
	sf::Color m_inside_color = sf::Color(21, 50, 67,200);
	sf::Color m_outside_color = sf::Color(21, 50, 67,250);

	//members:
	float m_width;
	float m_height;

};