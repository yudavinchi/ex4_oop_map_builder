#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Button.h"
#include "SidePannel.h"
#include "Ui.h"
#include "Macros.h"
#include "Intro.h"


//shoud it be a class?????
class Executable
{
public:
	Executable() = default;
	void add_run(const char selection, Ui& ui, sf::Font font, sf::RenderWindow& main_window);
	void run();
	void handle_click_non_pressed(sf::Vector2f& location, Ui& ui);
	//void handle_click(sf::Vector2f location, int number_of_buttons);
	std::vector<Button> m_button;
private:
	
};