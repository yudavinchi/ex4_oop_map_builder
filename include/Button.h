#pragma once
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>  //for debug 

class Button
{
public:
	Button() = default;
	Button(sf::Vector2f& vector, int height, int width, sf::Font& font, std::string text);

	void Draw(sf::RenderWindow& window);
  bool button_pressed(sf::Vector2f& location);
  void set_inner_color(const sf::Color& color);
	enum pressed get_action();
	void set_pressed();
	void reset_pressed();
  void handle_click_button(sf::Vector2f &location);
	bool contain_click_button(sf::Vector2i &location);
  pressed m_action;
protected:


	sf::RectangleShape get_inner_rect();
	sf::RectangleShape get_outer_rect();
	sf::Text getText();

	sf::Color m_outer_color = sf::Color(104,104,104);
	sf::Color m_inner_color = sf::Color(87, 87, 87);

	
	
	sf::Vector2f m_position;
	
	std::string m_text;

	sf::Font m_font;

	float m_width;

	float m_height;
};
