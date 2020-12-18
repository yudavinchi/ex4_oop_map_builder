#include "Button.h"


//do we want to get all those members? or some should be set as color
Button::Button(sf::Vector2f& vector, int height, int width,  sf::Font& font, std::string name)
:m_position(vector), m_height(height), m_width(width), m_font(font),m_text(name)
{};

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(get_outer_rect());
	window.draw(get_inner_rect());
	window.draw(getText());
};


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

	text.setCharacterSize(m_height / 2);

	float x = m_position.x;
	float y = m_position.y + (0.2) * m_height;
	sf::Vector2f location(x, y);
	text.setPosition(location);

	return text;
}

//check if click was inside our button
void Button::handle_click_button(sf::Vector2f & location)
{
	if(get_outer_rect().getGlobalBounds().contains(location))
	std::cout << "clicked on " << m_text << std::endl;
}

//check if click was inside our button
bool Button::contain_click_button(sf::Vector2i &location)
{
	if (get_outer_rect().getGlobalBounds().contains(location.x, location.y))
		return true;

	return false;
}
