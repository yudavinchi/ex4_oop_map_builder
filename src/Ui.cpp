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

	m_map.set_textures(m_textures);

	sf::Vector2f starting_location(40, 20);

	std::vector <char > characters;

	characters = { {'H'},{'#'},{'@'}, {'-'}, {'%'}, {'*'}};
	
	for (int index = 0; index < number_of_add_buttons; ++index)
	{
		AddButton button(starting_location, 50, 50);
		button.set_texture(m_textures[index]);
		button.set_action(characters[index]);
		//need to add check for boudries
		m_add_buttons.push_back(button);
		starting_location.x += 100;

		if (starting_location.x + 100 > m_side_pannel.getWidth())
		{
			starting_location.x = 40;
			starting_location.y += 90;
		}
	}
	sf::Texture texture1;

	//build side pannel	
	sf::Vector2f location_remove(40, 300);
	sf::Vector2f location_reset(40, 380);
	m_remove_button = SpriteButton(location_remove, 50, 100);

	m_remove_button.set_texture(m_textures[REMOVE_PRS_TEXTURE], m_textures[REMOVE_NT_PRS_TEXTURE]);

	m_reset_button = SpriteButton(location_reset, 50, 100);

	m_reset_button.set_texture(m_textures[RESET_PRS_TEXTURE], m_textures[RESET_NT_PRS_TEXTURE]);

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
		m_add_buttons[index].Draw(window);
	}

	//draws delete button
	m_remove_button.draw_remove(window);
	m_reset_button.draw_remove(window);
	//draws save button

}



void Ui::hadle_click(sf::Vector2f & location)
{
	//checks add buttons
	for (int i = 0; i < m_num_of_add_buttons; ++i)
	{
		if (m_add_buttons[i].button_pressed(location))
		{
			if (m_pressed == pressed::DELETE)
				m_remove_button.set_pressed();

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
			//m_add_buttons[i].set_pressed();
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
		if (m_pressed != pressed::DELETE)
		{
			if(m_curr_pressed_add != NULL)
			m_curr_pressed_add->set_pressed();
		}
		else
		{
			m_pressed = pressed::NONE;
			m_remove_button.set_pressed();
			return;
		}
			//resets other button
		m_pressed = pressed::DELETE;
		m_remove_button.set_pressed();
		m_curr_pressed_add = NULL;
		return;
	}


	if (m_reset_button.button_pressed(location))
	{
		m_map.reset();
		
		if (m_pressed == pressed::DELETE)
		{
			m_remove_button.set_pressed();
		}
		else 
		{
			if (m_pressed != pressed::NONE)
				m_curr_pressed_add->set_pressed();
		}
		
		//resets other button
		m_pressed = pressed::RESET;
		m_reset_button.set_pressed();
		m_curr_pressed_add = NULL;
		return;
	}
	//if save

	
}


void Ui::handle_mouse_over(sf::Vector2f& location)
{
	m_map.handle_mouse_over(location, m_pressed);
}



//sets curr pressed item
void Ui::set_pressed(enum pressed what_pressed, AddButton & button)
{
	//we pressed new one
	if (m_pressed != what_pressed) {
		if(m_curr_pressed_add != NULL)
			m_curr_pressed_add->set_pressed();

		m_pressed = what_pressed;
		m_curr_pressed_add = &button;
		m_curr_pressed_add->set_pressed();
	}
	else
	{
		m_curr_pressed_add->set_pressed();
		m_curr_pressed_add == NULL;
		m_pressed = pressed::NONE;
	}
}

void Ui::handle_relese(sf::Vector2f& location)
{

	if (m_reset_button.button_pressed(location))
	{
		if (m_pressed == pressed::RESET)
		{
			m_reset_button.set_pressed();
			m_pressed = pressed::NONE;
			return;
		}
	}

}





void Ui::load_textures(std::vector<std::shared_ptr<sf::Texture>>& m_textures)
{
	auto texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("ladder.png");
	m_textures.push_back(texture_ptr);


	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("ground.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("player.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("rope.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("enemy.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("coin.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("wall.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("Remove P.png");
	m_textures.push_back(texture_ptr);


	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("Remove NP.png");
	m_textures.push_back(texture_ptr);

	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("Reset P.png");
	m_textures.push_back(texture_ptr);


	texture_ptr = std::make_shared<sf::Texture>();
	texture_ptr->loadFromFile("Reset NP.png");
	m_textures.push_back(texture_ptr);
};