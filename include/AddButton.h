/*
Class for buttons that hold textures you want to add on the map
Specification: to work properly the texture should be 50 / 50.
if you change this size update the m_scale.
if you want a thicker line outside the pressed button update m_out_thi
if you want diffrent color on outline update m_color.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class AddButton :public Button
{
public:
	//using button constructor
	using Button::Button;

	//setters:
	void set_texture( std::shared_ptr <sf::Texture > & texure);
	void set_action(const char & action);
	void set_pressed();

	//getters:
	sf::Sprite get_sprite();
	char get_char();

	//helpers:
	void Draw(sf::RenderWindow& window);
	bool button_pressed(sf::Vector2f &location);

private:

	//members with difult value:
	float m_scale = 1;
	float m_out_thi = 3;
	sf::Color m_color = sf::Color(255, 255, 255, 0);

	//members with set value:
	sf::Texture* m_texture;
	char m_action;

	//helper functions:
	sf::RectangleShape get_rectangle();
};