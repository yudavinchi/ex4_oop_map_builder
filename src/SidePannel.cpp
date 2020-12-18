#include "SidePannel.h"


SidePannel::SidePannel(float height_of_window, float widht_of_window)
{
	m_height = height_of_window;
	//setting the 30% of window as side pannel;
	m_width = 0.3 * widht_of_window;
}

int SidePannel::getWidth()
{
	return m_width;
}

void SidePannel::Draw(sf::RenderWindow& window)
{
	window.draw(get_outer_rect());
	window.draw(get_inner_rect());
}
sf::RectangleShape SidePannel::get_inner_rect()
{
	sf::RectangleShape rect({ m_width - 5,m_height - 5 });
	rect.setFillColor(m_inside_color);
	return rect;
}
sf::RectangleShape SidePannel::get_outer_rect()
{
	sf::RectangleShape rect({ m_width , m_height});
	rect.setFillColor(m_outside_color);
	return rect;
}