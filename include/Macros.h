#pragma once

#define LADDER_TEXTURE 0
#define GROUND_TEXTURE 1
#define PLAYER_TEXTURE 2
#define POLE_TEXTURE 3
#define ENEMY_TEXTURE 4
#define COIN_TEXTURE 5
#define WALL_TEXTURE 6
#define REMOVE_PRS_TEXTURE 7
#define REMOVE_NT_PRS_TEXTURE 8
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


const int number_of_add_buttons = 6;

const char PLAYER = char('@');
const char COIN = char('*');
const char ENEMY = char('%');
const char POLE = char('-');
const char WALL = char('#');
const char LADDER = char('H');
const char NONE = char(' ');





