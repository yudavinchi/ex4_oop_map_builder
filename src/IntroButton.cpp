#include "IntroButton.h"

sf::RectangleShape IntroButton::get_inner_rect()
{
	auto rect = sf::RectangleShape({ m_width - 5, m_height - 5 });
	rect.setPosition(m_position);
	rect.setFillColor(m_inner_color);

	return rect;
}
sf::RectangleShape IntroButton::get_outer_rect() {
	auto rect = sf::RectangleShape({ m_width, m_height });
	rect.setPosition(m_position);
	rect.setFillColor(m_outer_color);

	return rect;
}
void IntroButton::set_text(std::string const &text, sf::Font &font)
{
	m_text = text;
	m_font = font;
}

sf::Text IntroButton::getText()
{
	//size of button
	int widht = m_width;
	int height = m_height;

	auto text = sf::Text(m_text, m_font);

	//text.setCharacterSize(m_height / 2);
	text.setCharacterSize(16);
	float x = m_position.x;
	float y = m_position.y + (0.2) * m_height;
	sf::Vector2f location(x, y);
	text.setPosition(location);

	return text;
}

void IntroButton::Draw(sf::RenderWindow &window)
{
	window.draw(get_outer_rect());
	window.draw(get_inner_rect());
	window.draw(getText());
};


bool IntroButton::button_pressed(sf::Vector2f &location)
{
	if (get_outer_rect().getGlobalBounds().contains(location)) {
		return true;
	}
	return false;
}

//check if click was inside our button
bool IntroButton::contain_click_button(sf::Vector2i &location)
{
	if (get_outer_rect().getGlobalBounds().contains(location.x, location.y))
		return true;

	return false;
}