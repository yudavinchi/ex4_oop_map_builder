#pragma once

#define ENEMY_TEXTURE 0
#define GROUND_TEXTURE 1
#define LADDER_TEXTURE 2
#define ROPE_TEXTURE 3
#define WALL_TEXTURE 4

enum class pressed
{
	NONE,
	PLAYER,
	ENEMY,
	LADDER,
	COIN,
	WALL,
	POLE,
	DELETE,
	SAVE
};


const int number_of_add_buttons = 5;

const char PLAYER = char('@');
const char COIN = char('*');
const char ENEMY = char('%');
const char POLE = char('-');
const char WALL = char('#');
const char LADDER = char('H');
const char NONE = char(' ');





