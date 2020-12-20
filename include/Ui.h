/*
Hold all ui elements and handels all the ui work.
*/
#pragma once
#include "Button.h"
#include "AddButton.h"
#include "SpriteButton.h"
#include "SidePannel.h"
#include "map.h"
#include "Window.h"
#include "Macros.h"
#include <vector>
#include <string>


class Ui
{
public:

	//C-tors:
	Ui(Window& window, Map & map);

	//Setters:
	void set_pressed(enum pressed what_pressed, AddButton& button);

	//Helpers:
	void Draw(sf::RenderWindow& window);
	void hadle_click(sf::Vector2f & location);
	void handle_relese(sf::Vector2f& location);
	void handle_mouse_over(sf::Vector2f& location);
	
private:

	//Buttons:

	//holds the button that is curr pressed
	AddButton* m_curr_pressed_add = NULL;

	//hold the definition of curr pressed
	enum pressed m_pressed;

	//hold the number of  add buttons
	int	m_num_of_add_buttons;

	//holds the add buttons
	std::vector<AddButton> m_add_buttons;

	SpriteButton m_remove_button;
	SpriteButton m_save_button;
	SpriteButton m_reset_button;

	//--------------------------------------------------

	//Side pannel:
	SidePannel m_side_pannel;

	//--------------------------------------------------

	//Map:
	Map m_map;

	//--------------------------------------------------

	//Textures:
	void load_textures(std::vector<std::shared_ptr<sf::Texture >>& m_textures);
	std::vector<std::shared_ptr<sf::Texture>> m_textures;
	//--------------------------------------------------
};