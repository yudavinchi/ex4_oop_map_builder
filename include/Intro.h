#pragma once

// include section
#include "Window.h"
#include "IntroButton.h"
#include <string>
#include <filesystem>
#include <SFML/Graphics.hpp>

// const section
const int MAX_LENGTH = 5;
const int MAX_HEIGHT = 150;
const int MAX_WIDTH  = 450;
const sf::Vector2f SIZE = { 180, 50 };

class Intro : public Window
{
public:
	//C-tors
	Intro();

	// func
	sf::Vector2i run();

private:

	// private functions
	int				   convert_into_int(std::string &string) const;
	sf::Text		   init_text(std::string &string, sf::Vector2f &location) const;
	sf::RectangleShape init_input_box(sf::Vector2f size, sf::Vector2f &location) const;

	sf::Font m_font;

	// location members
	sf::Vector2f m_location_height_input;
	sf::Vector2f m_location_width_input;
	sf::Vector2f m_location_send_button;
};