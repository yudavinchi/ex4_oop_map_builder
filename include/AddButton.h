#pragma once
#include <Button.h>

#include <SFML/Graphics.hpp>


class AddButton :public Button
{
public:
	using Button::Button;

	char get_char();
	
private:
	
};