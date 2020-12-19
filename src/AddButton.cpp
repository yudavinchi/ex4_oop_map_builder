#include "AddButton.h"



char AddButton::get_char() {
	return m_action;
}
void AddButton::Draw_add(sf::RenderWindow & window)
{
	window.draw(get_sprite());
}
void AddButton::set_pressed()
{

}
void AddButton::set_texture( std::shared_ptr<sf::Texture >& texture)
{

	m_texture = &(*texture);
}
void AddButton::set_action(const char &action)
{
	m_action = action;
}

sf::Sprite AddButton::get_sprite()
{
	sf::Sprite sprite;
	sprite.setTexture(*m_texture);
	sprite.setPosition(m_position);
	sprite.scale(sf::Vector2f(1.5, 1.5));
	
	return sprite;
}

bool AddButton::button_pressed(sf::Vector2f &location) {
	if (get_sprite().getGlobalBounds().contains(location))
	{
		return true;
	}
	return false;
}