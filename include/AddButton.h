#pragma once
#include <Button.h>

#include <SFML/Graphics.hpp>


class AddButton :public Button
{
public:
	using Button::Button;
	void set_texture( std::shared_ptr <sf::Texture > & texure);
	void set_action(const char & action);
	void Draw_add(sf::RenderWindow& window);
	void set_pressed();
	sf::Sprite get_sprite();
	char get_char();
	bool button_pressed(sf::Vector2f &location);
private:
	sf::Texture * m_texture;
	char m_action;
};