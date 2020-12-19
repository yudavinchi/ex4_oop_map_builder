#pragma once
#include <Button.h>

#include <SFML/Graphics.hpp>

//SHOULD IT BE ITS OWN CLASS???
class RemoveButton :public Button
{
public:
	using Button::Button;
	void set_pressed();
	void set_texture(std::shared_ptr <sf::Texture > &pressed, std::shared_ptr <sf::Texture > &not_pressed);
	void draw_remove(sf::RenderWindow &window);
	sf::Sprite get_sprite();
	bool button_pressed(sf::Vector2f &location);

private:
	bool m_pressed = false;
	sf::Texture *m_texture_not_pressed;
	sf::Texture *m_texture_pressed;

};