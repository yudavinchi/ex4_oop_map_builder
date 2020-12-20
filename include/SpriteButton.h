/*
This class is for buttons constructed with sprites.
aka main action buttons of the ui.
*/

#pragma once
#include <Button.h>
#include <SFML/Graphics.hpp>


class SpriteButton :public Button
{
public:
	//C-tors:
	using Button::Button;

	//Setters:
	void set_pressed();
	void set_texture(std::shared_ptr <sf::Texture > &pressed, std::shared_ptr <sf::Texture > &not_pressed);

	//Getters:
	sf::Sprite get_sprite();

	//Helpers:
	void draw_remove(sf::RenderWindow &window);
	bool button_pressed(sf::Vector2f &location);

private:

	//Members:
	bool m_pressed = false;
	sf::Texture *m_texture_not_pressed;
	sf::Texture *m_texture_pressed;

};