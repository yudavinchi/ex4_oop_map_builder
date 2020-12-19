#pragma once
#include "Macros.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <string.h>

class IntroButton : public Button
{
public:
	using Button::Button;
	void set_text( std::string const &text, sf::Font &font);
	void Draw(sf::RenderWindow &window);
	bool button_pressed(sf::Vector2f &location);
	bool contain_click_button(sf::Vector2i &location);
private:
	sf::RectangleShape get_inner_rect();
	sf::RectangleShape get_outer_rect();
	sf::Text getText();
	std::string  m_text;
	sf::Font m_font;
	sf::Color m_outer_color = sf::Color(104, 104, 104);
	sf::Color m_inner_color = sf::Color(87, 87, 87);
};