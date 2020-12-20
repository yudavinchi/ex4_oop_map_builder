#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <filesystem>
#include "Window.h"
#include "Button.h"
#include "SidePannel.h"
#include "Ui.h"
#include "Macros.h"
#include "Intro.h"


namespace Executable
{
	void run();
	void hadle_click(sf::Vector2f& location, Ui& ui);
	void hadle_release(sf::Vector2f& location, Ui& ui);
};