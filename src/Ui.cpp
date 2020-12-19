//contains all ui elements
#include "Ui.h"


Ui::Ui(Window& window, sf::Font& font, Map& map) :
	m_side_pannel(SidePannel(window.get_height(), window.get_width())),
	m_num_of_add_buttons(number_of_add_buttons), // chage to const
	m_font(font),
	m_map(map),
	m_pressed(pressed::NONE)
{

	load_textures(m_textures);

	sf::Vector2f starting_location(10, 10);

	std::vector <std::string > characters;

	//reamke
	characters.push_back("@");
	characters.push_back("%");
	characters.push_back("H");
	characters.push_back("*");
	characters.push_back("#");
	characters.push_back("-");
	
	
	for (int index = 0; index < number_of_add_buttons; ++index)
	{
		AddButton button(starting_location, 50, 50, font, characters[index]);
		//need to add check for boudries
		m_add_buttons.push_back(button);
		starting_location.x += 60;

		if (starting_location.x + 50 > m_side_pannel.getWidth())
		{
			starting_location.x -= 60;
			starting_location.y += 60;
		}
	}
	sf::Texture texture1;

	

	m_add_buttons[0].set_texture(m_textures[0]);
	m_add_buttons[1].set_texture(m_textures[1]);
	m_add_buttons[2].set_texture(m_textures[2]);
	m_add_buttons[3].set_texture(m_textures[3]);
	m_add_buttons[4].set_texture(m_textures[4]);
	//m_add_buttons[5].set_texture(m_textures[5]);

	//build side pannel	
	sf::Vector2f location_remove(50, 150);
	
	RemoveButton remove = RemoveButton(location_remove, 50, 100, font, "remove");
	m_remove_button = remove;
};

void Ui::load_textures(std::vector<std::unique_ptr<sf::Texture>>& m_textures)
{
	


	auto texture_ptr1 = std::make_unique<sf::Texture>();
	texture_ptr1->loadFromFile("ladder with wall.png");
	m_textures.push_back(std::move(texture_ptr1));


	auto texture_ptr2 = std::make_unique<sf::Texture>();
	texture_ptr2->loadFromFile("ground.png");
	m_textures.push_back(std::move(texture_ptr2));

	auto texture_ptr3 = std::make_unique<sf::Texture>();
	texture_ptr3->loadFromFile("ladder with wall.png");
	m_textures.push_back(std::move(texture_ptr3));

	auto texture_ptr4 = std::make_unique<sf::Texture>();
	texture_ptr4->loadFromFile("rope with wall.png");
	m_textures.push_back(std::move(texture_ptr4));

	auto texture_ptr5 = std::make_unique<sf::Texture>();
	texture_ptr5->loadFromFile("wall.png");
	m_textures.push_back(std::move(texture_ptr5));


};

void Ui::Draw(sf::RenderWindow& window)
{
	//draws side pannel
	m_side_pannel.Draw(window);
	//draws map
	m_map.Draw(window);
	

	//draws add button
	for (int index = 0; index < number_of_add_buttons; ++index)
	{
		m_add_buttons[index].Draw_add(window);
	}

	//draws delete button
	//m_remove_button.Draw(window);
	//draws save button

}



void Ui::hadle_click(sf::Vector2f & location)
{
	//checks add buttons
	for (int i = 0; i < m_num_of_add_buttons; ++i)
	{
		if (m_add_buttons[i].button_pressed(location))
		{
			switch (m_add_buttons[i].get_char())
			{
			case PLAYER:
				set_pressed(pressed::PLAYER, m_add_buttons[i]);
				break;
			case ENEMY:
				set_pressed(pressed::ENEMY, m_add_buttons[i]);
				break;
			case WALL:
				set_pressed(pressed::WALL, m_add_buttons[i]);
				break;
			case LADDER:
				set_pressed(pressed::LADDER, m_add_buttons[i]);
				break;
			case COIN:
				set_pressed(pressed::COIN, m_add_buttons[i]);
				break;
			case POLE:
				set_pressed(pressed::POLE, m_add_buttons[i]);
				break;
			}
			m_add_buttons[i].set_pressed();
			//no nneed to continue
			return;
		}
	}

	//handles click on map
	if (m_map.handle_click(location, m_pressed))
	{
		return;
	}

	//handles click on delete button
	
	if (m_remove_button.button_pressed(location))
	{
		set_pressed(pressed::DELETE, m_remove_button);
		m_remove_button.set_pressed();
		return;
	}
	//if save

	//if reset
}


void Ui::handle_mouse_over(sf::Vector2f& location)
{
	m_map.handle_mouse_over(location, m_pressed);
}


//sets curr pressed item
void Ui::set_pressed(enum pressed what_pressed, Button & button)
{
	//we pressed new one
	if (m_pressed != what_pressed)
		if(m_curr_pressed_add != NULL )
		(*m_curr_pressed_add).reset_pressed();

	m_pressed = what_pressed;
	m_curr_pressed_add = &button;
}