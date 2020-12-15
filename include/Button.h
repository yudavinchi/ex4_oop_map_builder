#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>  //for debug 

class Button
{
public:
	Button(sf::Vector2f & vector, int height, int witdth, sf::Font & font,std::string text);

	void Draw(sf::RenderWindow& window);

	//should be specific for each buttton
	void handle_click_button(sf::Vector2f& location);
private:

	
	sf::RectangleShape get_inner_rect();
	sf::RectangleShape get_outer_rect();

	sf::Color m_outer_color = sf::Color(104,104,104);
	sf::Color m_inner_color = sf::Color(87, 87, 87);

	sf::Text getText();
	
	sf::Vector2f m_position;
	
	std::string m_text;

	sf::Font m_font;

	float m_width;
	float m_height;
};
