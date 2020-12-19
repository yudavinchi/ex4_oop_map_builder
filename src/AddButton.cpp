#include "AddButton.h"



char AddButton::get_char() {
	return m_action;
}
void AddButton::Draw_add(sf::RenderWindow & window)
{
	window.draw(get_rectangle());
	window.draw(get_sprite());
}
void AddButton::set_pressed()
{
	if (m_color == sf::Color(255, 255, 255, 0))
		m_color = sf::Color::Red;
	else
		m_color = sf::Color(255, 255, 255, 0);
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
	sprite.scale(sf::Vector2f(1, 1));
	
	return sprite;
}

bool AddButton::button_pressed(sf::Vector2f &location) {
	if (get_sprite().getGlobalBounds().contains(location))
	{
		return true;
	}
	return false;
}


sf::RectangleShape AddButton::get_rectangle()
{
	sf::RectangleShape rect;
	sf::Vector2f size(get_sprite().getGlobalBounds().height, get_sprite().getGlobalBounds().width);
	rect.setPosition(m_position);
	rect.setSize(size);
	rect.setOutlineColor(m_color);
	rect.setOutlineThickness(3);
	
	return rect;
}