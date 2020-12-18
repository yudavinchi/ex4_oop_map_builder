#pragma once
#include <SFML/Graphics.hpp>


class SidePannel
{
public:
	SidePannel(float height_of_window, float widht_of_window);

	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape get_inner_rect();
	sf::RectangleShape get_outer_rect();
	sf::Vector2f m_location = sf::Vector2f(0, 0);
	sf::Color m_inside_color = sf::Color(196, 196, 196);
	sf::Color m_outside_color = sf::Color(169, 169, 169);
	float m_width;
	float m_height;

};