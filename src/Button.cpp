#include "Button.h"


//do we want to get all those members? or some should be set as color
Button::Button(sf::Vector2f& vector, int height, int width, sf::Font& font, std::string name)
:m_position(vector), m_height(height), m_width(width), m_font(font),m_text(name)
{
	m_text = name;
};


void Button::Draw(sf::RenderWindow& window)
{
	window.draw(get_outer_rect());
	window.draw(get_inner_rect());
	window.draw(getText());
};

enum pressed Button::get_action()
{
	return m_action;
}
sf::RectangleShape Button::get_inner_rect()
{
	auto rect = sf::RectangleShape({ m_width- 5, m_height -5 });
	rect.setPosition(m_position);
	rect.setFillColor(m_inner_color);

	return rect;
}
sf::RectangleShape Button::get_outer_rect() {
	auto rect = sf::RectangleShape({ m_width, m_height });
	rect.setPosition(m_position);
	rect.setFillColor(m_outer_color);

	return rect;
}

sf::Text Button::getText()
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

//check if click was inside our button
bool Button::button_pressed(sf::Vector2f & location)
{
	if (get_outer_rect().getGlobalBounds().contains(location)) {
		return true;
	}	
	return false;
}

void Button::set_inner_color(const sf::Color & color)
{
	m_inner_color = color;
}

void Button::set_pressed()
{
	set_inner_color(sf::Color::Red);
}

void Button::reset_pressed()
{
	set_inner_color(sf::Color(87, 87, 87));
}

//check if click was inside our button
bool Button::contain_click_button(sf::Vector2i &location)
{
	if (get_outer_rect().getGlobalBounds().contains(location.x, location.y))
		return true;

	return false;
}
