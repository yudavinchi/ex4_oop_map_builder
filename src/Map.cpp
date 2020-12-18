#include "Map.h"
#include <iostream> //for debugging

Map::Map(float width, float height, float size_of_char,sf::Font& font):
	m_width(width), m_height(height),size_of_char(size_of_char), m_font(font)
{

	std::vector <std::vector<char> > map;
	map.resize(height);

	//setting sizes
	for (int i = 0; i < height; ++i)
	{
		map[i].resize(width);
	}

	m_map = map;

}

void Map::insert(int x, int y, char character) {

	m_map[x][y] == character;
}


void Map::Draw(sf::RenderWindow & window)
{
	
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; j++)
		{
			window.draw(get_map(i,j));
			window.draw(get_text(i, j, m_map[i][j]));
		}
	}
	
	if (curr_mose_over_x != -1 && curr_mose_over_y != -1)
	{
		window.draw(get_transperant());
		window.draw(get_transperant_text());
	}
}

sf::Text Map::get_text(int i, int j, char symbol)
{
	sf::Text text(symbol, m_font);

	text.setColor(sf::Color::White);

	text.setPosition(get_location(i, j));

	return text;
}

sf::Text Map::get_transperant_text()
{
	sf::Text text(m_trans_char, m_font);

	text.setColor(sf::Color::White);

	text.setPosition(get_location(curr_mose_over_x, curr_mose_over_y));

	return text;
}

sf::RectangleShape Map::get_map(int i, int j)
{
	
	auto rectangle = sf::RectangleShape({size_of_char,size_of_char});
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(get_location(i,j));
	return rectangle;
}

sf::RectangleShape Map::get_transperant()
{
	
	auto rectangle = sf::RectangleShape({ size_of_char,size_of_char });
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(get_location(curr_mose_over_x, curr_mose_over_y));
	return rectangle;
}
sf::Vector2f Map::get_location(int i, int j)
{
	return sf::Vector2f(m_location.x + i * size_of_char, m_location.y + j *size_of_char);
}

//sets the 0,0 location
void Map::set_location(Window& window)
{
	//calculates position of map
	float width = window.get_width();
	width -= window.get_width() * 0.3 ; //reducing size of side pannel
	width *= 0.5; // finds center;
	width = width - 0.5 * m_width*size_of_char;

	float x = window.get_width() * 0.3 + width;

	float height = window.get_height();
	height *= 0.4; //find center
	height -= 0.5 * m_height* size_of_char;

	float y = height;

	m_location = sf::Vector2f(x, y);

}



bool Map::handle_click(sf::Vector2f& location, pressed& pressed)
{
	
	std::cout << "handle mouse over" << location.x << " " << location.y << std::endl;
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (get_map(i, j).getGlobalBounds().contains(location))
			{
				switch (pressed)
				{
				case pressed::NONE:
					
					return true;

				case pressed::PLAYER:
					//CHECK THER IS NO ANOTHER PLAYER
					add_char_to_map(i, j, PLAYER);
					return true;
				
				case pressed::LADDER:
					//CHECK THER IS NO ANOTHER PLAYER
					add_char_to_map(i, j, LADDER);
					return true;

				case pressed::COIN:
					add_char_to_map(i, j,COIN);
					return true;


				case pressed::POLE:
					add_char_to_map(i, j,POLE);
					return true;

				case pressed::WALL:
					add_char_to_map(i, j,WALL);
					return true;

				case pressed::ENEMY:
					add_char_to_map(i, j,ENEMY);
					return true;
				case pressed::DELETE:
					remove_char_from_map(i, j);
					return true;
				}
			}
		}
	}

	return false;
}


void Map::add_char_to_map(int i, int j, const char game_char)
{
	m_map[i][j] = game_char;
}

void Map::remove_char_from_map(int i, int j)
{
	add_char_to_map(i, j, NONE);
}

void Map::set_transperant(const char game_char)
{
	m_trans_char  = game_char;
}


void Map::handle_mouse_over(sf::Vector2f& location,pressed& pressed)
{
	if (pressed != pressed::DELETE) {
		//std::cout << "handle mouse over" << location.x << " " << location.y << std::endl;
		for (int i = 0; i < m_height; ++i)
		{
			for (int j = 0; j < m_width; j++)
			{
				if (get_map(i, j).getGlobalBounds().contains(location))
				{
	
					//check if we exited prev one
					if (curr_mose_over_x != i || curr_mose_over_y != j)
					{
						curr_mose_over_x = i;
						curr_mose_over_y = j;
					}

					switch (pressed)
					{
					case pressed::NONE:
						set_transperant(NONE);
						
						return;;

					case pressed::PLAYER:
						//CHECK THER IS NO ANOTHER PLAYER
						set_transperant(PLAYER);
						
						return;
					case pressed::LADDER:
						//CHECK THER IS NO ANOTHER PLAYER
						set_transperant(LADDER);
						
						return;

					case pressed::COIN:
						set_transperant(COIN);
						
						return;


					case pressed::POLE:
						set_transperant(POLE);
					
						return;

					case pressed::WALL:
						set_transperant(WALL);
						
						return;

					case pressed::ENEMY:
						set_transperant(ENEMY);
						return;
					default:
						
						return;
					}
					//we dont want to get to the end if we found
				}
			}
		}
		curr_mose_over_x = -1;
		curr_mose_over_y = -1;
	}
}