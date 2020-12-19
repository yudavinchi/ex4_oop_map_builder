#pragma once
#include <Button.h>

#include <SFML/Graphics.hpp>


class AddButton :public Button
{
public:
	using Button::Button;
	void set_texture( std::shared_ptr <sf::Texture > & texure);
	void Draw_add(sf::RenderWindow& window);
	void set_pressed();
	sf::Sprite get_sprite();
	char get_char();
	
private:
	sf::Texture * m_texture;
	
};