#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Button.h"
#include "SidePannel.h"
#include "Intro.h"

//shoud it be a class?????
class Executable
{
public:
	Executable() = default;
	void run();
	void handle_click(sf::Vector2f location, int number_of_buttons);
	std::vector<Button> m_button;
private:
	
};