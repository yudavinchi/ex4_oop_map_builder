#include "SpriteButton.h"


//------------------------------Setters--------------------------
void SpriteButton::set_texture(std::shared_ptr <sf::Texture >& pressed,
							   std::shared_ptr <sf::Texture >& not_pressed)
{
	m_texture_pressed = &(*pressed);
	m_texture_not_pressed = &(*not_pressed);
}
//---------------------------------------------------------------

void SpriteButton::set_pressed()
{
	if (m_pressed)
		m_pressed = false;
	else
		m_pressed = true;
}
//---------------------------------------------------------------

//------------------------------Getters--------------------------
sf::Sprite SpriteButton::get_sprite()
{
	sf::Sprite sprite;
	if (m_pressed)
		sprite.setTexture(*m_texture_pressed);
	else
		sprite.setTexture(*m_texture_not_pressed);

	sprite.setPosition(m_position);
	sprite.scale(sf::Vector2f(0.5, 0.5));

	return sprite;
}
//---------------------------------------------------------------

//------------------------------Helpers--------------------------

void SpriteButton::draw_remove(sf::RenderWindow &window)
{
	window.draw(get_sprite());
};
//---------------------------------------------------------------

bool SpriteButton::button_pressed(sf::Vector2f &location) 
{
	if (get_sprite().getGlobalBounds().contains(location))
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------------
