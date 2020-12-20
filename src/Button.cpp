#include "Button.h"

//------------------------------C-tors--------------------------
Button::Button(sf::Vector2f& vector, int height, int width)
:m_position(vector), m_height(height), m_width(width)
{};
//--------------------------------------------------------------

Button::Button()
:m_position(sf::Vector2f(0,0)), m_height(0), m_width(0)
{};
//--------------------------------------------------------------





