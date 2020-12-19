#pragma once
#include "Window.h"
#include "IntroButton.h"
#include <string>
#include <SFML/Graphics.hpp>

const int MAX_LENGTH = 5;
const int MAX_HEIGHT = 150;
const int MAX_WIDTH  = 450;
const sf::Vector2f SIZE = { 180, 50 };

class Intro : public Window
{
public:

	Intro();
	sf::Vector2i run();

private:

	int				   convert_into_int(std::string &string) const;
	sf::Text		   init_text(std::string &string, sf::Vector2f &location) const;
	sf::RectangleShape init_input_box(sf::Vector2f size, sf::Vector2f &location) const;

	sf::Font m_font;

	// location 
	sf::Vector2f m_location_height_input;
	sf::Vector2f m_location_width_input;
	sf::Vector2f m_location_send_button;
};