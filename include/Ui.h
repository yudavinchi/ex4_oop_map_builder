#pragma once
#include "Button.h"
#include "AddButton.h"
#include "RemoveButton.h"
#include "SidePannel.h"
#include "map.h"
#include "Window.h"
#include "Macros.h"
#include <vector>
#include <string>


class Ui
{
public:

	Ui(Window& window,sf::Font& font, Map & map);
	void Draw(sf::RenderWindow& window);
	void hadle_click(sf::Vector2f & location);
	void set_pressed(enum pressed what_pressed, Button &button);
	void handle_mouse_over(sf::Vector2f& location);
	
private:
	void load_textures(std::vector<std::shared_ptr<sf::Texture >>& m_textures);

	//holds the button that is curr pressed
	Button* m_curr_pressed_add = NULL;
	
	//hold the definition of curr pressed
	enum pressed m_pressed;

	//hold the nuber of buttons
	int	m_num_of_add_buttons;

	//holds the add buttons
	std::vector<AddButton> m_add_buttons;

	RemoveButton m_remove_button;

	//holds the map
	Map m_map;
	
	//holds the side pannel
	SidePannel m_side_pannel;

	std::vector<std::shared_ptr<sf::Texture>> m_textures;
	//holds the font
	sf::Font m_font;
};