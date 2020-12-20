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
	void run();
	void hadle_click(sf::Vector2f& location, Ui& ui);
	void hadle_release(sf::Vector2f& location, Ui& ui);
};