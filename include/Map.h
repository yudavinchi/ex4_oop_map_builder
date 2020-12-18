#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Macros.h"

class Map
{

public:
	Map(float m_width, float m_height, float size_of_char, sf::Font& font);

	void insert(int x, int y, char character);
	void Draw(sf::RenderWindow& window);
	void set_location(Window& window);
	bool handle_click(pressed& pressed, sf::Vector2f& location);
	sf::Vector2f get_location(int i, int j);
	void add_char_to_map(int i, int j, const char game_char);
	void set_transperant(const char game_char);
	bool handle_click(sf::Vector2f& location ,pressed& pressed);
	void handle_mouse_over(sf::Vector2f& location, pressed& pressed);
	void remove_char_from_map(int i, int j);

private:
	//for now
	sf::Font m_font;

	//for now
	sf::Text get_text(int i, int j, char symbol);
	sf::Text get_transperant_text();
	
	sf::RectangleShape get_map(int i, int j);
	sf::RectangleShape get_transperant();
	//hold the map
	//will hold the size of each char (the font) - so we can calcualte the size of the map 
	float size_of_char;
	//vector of vectors
	std::vector <std::vector<char>> m_map;

	float m_width;
	float m_height;

	sf::Vector2f m_location;

	float curr_mose_over_x =-1;
	float curr_mose_over_y =-1;
	char m_trans_char = ' ';

};