/*
Class for holding the map, drawing it, hadleing the mouse over and mouse click.

*/
#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Window.h"
#include "Macros.h"

class Map
{
public:
	//C-tors
	Map(float m_width, float m_height, float size_of_char);
	Map(std::string path, float size_of_sprite);

	//Setters:
	void set_location(Window& window);
	void set_textures(std::vector<std::shared_ptr<sf::Texture>>& textures);
	void set_transperant(const char game_char);

	//Getters:
	sf::Vector2f get_location(int i, int j);
	char  get_char(int i, int j);
	float get_sprite_size();

	//Handlers:
	bool handle_click(sf::Vector2f& location, pressed& pressed);
	void handle_mouse_over(sf::Vector2f& location, pressed& pressed);

	//Helpers:
	void insert(int x, int y, char character);
	void Draw(sf::RenderWindow &window);
	void add_char_to_map(int i, int j, const char game_char);
	void remove_char_from_map(int i, int j);
	void reset();

private:

	//private getters:
	sf::Sprite get_map(int i, int j);
	sf::Sprite get_transperant();

	Map &operator=(const Map &other);
	
	//members:
	float m_width;
	float m_height;
	float m_size_of_sprite;
	std::vector <std::vector<char>> m_map;
	char m_trans_char = ' ';
	sf::Vector2f m_starting_location;

	//for player control:
	bool m_there_is_player = false;
	sf::Vector2i m_player_location = sf::Vector2i(-1,-1);
	
	
	//for mouse over:
	float curr_mose_over_x =-1;
	float curr_mose_over_y =-1;

	//for textures:
	std::vector<std::shared_ptr<sf::Texture>> m_textures;
};