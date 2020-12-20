#include "Map.h"


//------------------------------C-tors--------------------------
Map::Map(float height, float width, float size_of_sprite):
	m_width(width), m_height(height),m_size_of_sprite(size_of_sprite)
{
	if (height != -1 && width != -1)
	{
		std::vector <std::vector<char> > map;
		map.resize(height);

		//setting sizes
		for (int i = 0; i < height; ++i)
		{
			map[i].resize(width);
			for (int j = 0; j < width; j++) {
				map[i][j] = ' ';
			}
		}
		m_map = map;
	}
	else
	{
		std::vector <std::vector<char>> map;
		std::vector<char> chars;
		std::string line;

		std::fstream file;
		file.open("Board.txt");

		do
		{
			//reads each line from the Board.txt
			getline(file, line);

			for (int j = 0; j < line.size(); j++)
			{
				chars.push_back(line[j]);
			}

			map.push_back(chars);

			chars.clear();
		}
		// Read the next line from File untill it reaches empty row.
		while (!file.eof()); //|| line.size() > 0

		m_width = map[0].size();
		m_height = map.size();

		m_map = map;
	}
}
//---------------------------------------------------------------

Map::Map(std::string path, float size_of_sprite)
	:m_width(0), m_height(0), m_size_of_sprite(size_of_sprite)
{
	std::vector <std::vector<char>> map;

	std::fstream file;

	file.open(path);

	std::vector<char> chars;
	std::string line;

	do
	{
		//reads each line from the Board.txt
		getline(file, line);

		for (int j = 0; j < line.size(); j++)
		{
			chars.push_back(line[j]);
		}

		map.push_back(chars);

		chars.clear();
	}
	// Read the next line from File untill it reaches empty row.
	while (!file.eof());

	m_width = map[0].size();
	m_height = map.size();

	m_map = map;
}


//------------------------------Setters--------------------------
void Map::set_textures(std::vector<std::shared_ptr<sf::Texture>>& textures)
{
	m_textures = textures;
}
//---------------------------------------------------------------

//sets the 0,0 location
void Map::set_location(Window& window)
{
	//calculates position of map
	float width = window.get_width();
	width -= window.get_width() * 0.2; //reducing size of side pannel
	width *= 0.5; // finds center;
	float size_of_spr = 0.5 * m_size_of_sprite * m_width;
	width -= size_of_spr;

	float x = window.get_width() * 0.2 + width;

	float height = window.get_height();
	height *= 0.5; //find center
	size_of_spr = 0.5 * m_size_of_sprite * m_height;
	height -= size_of_spr;

	float y = height;

	m_starting_location = sf::Vector2f(y, x);
}
//---------------------------------------------------------------

void Map::set_transperant(const char game_char)
{
	m_trans_char = game_char;
}
//---------------------------------------------------------------

//gets the transperete sprite when mouse over
sf::Sprite Map::get_transperant()
{
	sf::Sprite sprite;
	switch (m_trans_char)
	{
	case NONE:
		sprite.setTexture(*m_textures[WALL_TEXTURE]);
		break;
	case PLAYER:
		sprite.setTexture(*m_textures[PLAYER_TEXTURE]);
		break;
	case ENEMY:
		sprite.setTexture(*m_textures[ENEMY_TEXTURE]);
		break;
	case WALL:
		sprite.setTexture(*m_textures[GROUND_TEXTURE]);
		break;
	case LADDER:
		sprite.setTexture(*m_textures[LADDER_TEXTURE]);
		break;
	case COIN:
		sprite.setTexture(*m_textures[COIN_TEXTURE]);
		break;
	case POLE:
		sprite.setTexture(*m_textures[POLE_TEXTURE]);
		break;
	}
	sprite.setColor(sf::Color(255, 255, 255, 150));
	sprite.setPosition(get_location(curr_mose_over_x, curr_mose_over_y));
	sprite.scale(m_size_of_sprite / 50, m_size_of_sprite / 50);
	return sprite;
}
//---------------------------------------------------------------

//------------------------------Getters--------------------------
float Map::get_sprite_size()
{
	return m_size_of_sprite;
}
//---------------------------------------------------------------

//gets the map sprite in position i,j
sf::Sprite Map::get_map(int i, int j)
{
	sf::Sprite sprite;

	switch (get_char(i, j))
	{
		{
	case NONE:
		sprite.setTexture(*m_textures[WALL_TEXTURE]);
		break;
	case PLAYER:
		sprite.setTexture(*m_textures[PLAYER_TEXTURE]);
		break;
	case ENEMY:
		sprite.setTexture(*m_textures[ENEMY_TEXTURE]);
		break;
	case WALL:
		sprite.setTexture(*m_textures[GROUND_TEXTURE]);
		break;
	case LADDER:
		sprite.setTexture(*m_textures[LADDER_TEXTURE]);
		break;
	case COIN:
		sprite.setTexture(*m_textures[COIN_TEXTURE]);
		break;
	case POLE:
		sprite.setTexture(*m_textures[POLE_TEXTURE]);
		break;
		}
	}
	sprite.scale(m_size_of_sprite / 50, m_size_of_sprite / 50);
	sprite.setPosition(get_location(i, j));
	return sprite;
}
//---------------------------------------------------------------

sf::Vector2f Map::get_location(int i, int j)
{
	return sf::Vector2f(m_starting_location.y + j * m_size_of_sprite,
						m_starting_location.x + i * m_size_of_sprite);
}
//---------------------------------------------------------------

char Map::get_char(int i, int j)
{
	return m_map[i][j];
}
//---------------------------------------------------------------

//------------------------------Handlers-------------------------
bool Map::handle_click(sf::Vector2f& location, pressed& pressed)
{

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
					if (!m_there_is_player) {
						add_char_to_map(i, j, PLAYER);
						m_there_is_player = true;
						m_player_location = sf::Vector2i(i, j);
					}
					else
					{
						remove_char_from_map(m_player_location.x, m_player_location.y);
						add_char_to_map(i, j, PLAYER);
						m_there_is_player = true;
						m_player_location = sf::Vector2i(i, j);
					}
					return true;

				case pressed::LADDER:
					add_char_to_map(i, j, LADDER);
					return true;

				case pressed::COIN:
					add_char_to_map(i, j, COIN);
					return true;


				case pressed::POLE:
					add_char_to_map(i, j, POLE);
					return true;

				case pressed::WALL:
					add_char_to_map(i, j, WALL);
					return true;

				case pressed::ENEMY:
					add_char_to_map(i, j, ENEMY);
					return true;
				case pressed::DELETE:
					remove_char_from_map(i, j);
					if (m_player_location.x == i && m_player_location.y == j)
						m_there_is_player = false;
					return true;
				}
			}
		}
	}
	return false;
}
//---------------------------------------------------------------

void Map::handle_mouse_over(sf::Vector2f& location, pressed& pressed)
{
	if (pressed != pressed::DELETE) {

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
						set_transperant(PLAYER);

						return;
					case pressed::LADDER:
						
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
				}
			}
		}
		curr_mose_over_x = -1;
		curr_mose_over_y = -1;
	}
}
//---------------------------------------------------------------
//------------------------------Helpers--------------------------

void Map::insert(int x, int y, char character) {

	m_map[x][y] == character;
}
//---------------------------------------------------------------

void Map::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; j++)
		{
			window.draw(get_map(i,j));
		}
	}
	
	if (curr_mose_over_x != -1 && curr_mose_over_y != -1)
	{
		window.draw(get_transperant());
	}
}
//---------------------------------------------------------------

void Map::add_char_to_map(int i, int j, const char game_char)
{
	m_map[i][j] = game_char;
}
//---------------------------------------------------------------

void Map::remove_char_from_map(int i, int j)
{
	add_char_to_map(i, j, NONE);
}
//---------------------------------------------------------------

void Map::reset()
{
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_map[i][j] = NONE;
		}
	}
}
//---------------------------------------------------------------

void Map::save()
{
	std::ofstream file;

	file.open("Board.txt", std::ofstream::in | std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; j++)
		{
			file << m_map[i][j];
		}
		if (i != m_height - 1)
			file << '\n';
	}
}
//---------------------------------------------------------------