#pragma once

#include "tank.h"

/*
	THIS CLASS STORES THE TANKS AND ALLOWS THEM TO BE USED IN MAIN
*/

#ifndef GAME_TANKS_H_
#define GAME_TANKS_H_

class Tanks
{
private:
	std::vector<Tank> tanks;      // vector of Tanks

public:
	Tanks() { tanks.reserve(4); }
	Tanks(const Tanks *other) { tanks = other->tanks; }  // copy constructor (maybe useful)
	~Tanks() {}

	void operator=(Tanks* other) { tanks = other->tanks; }

	void add(std::string);			  // adding tanks
	void add();

	sf::Sprite &get_tank(TANK);    // Sprite of tank
	sf::FloatRect get_bounds_of_tank(TANK);

	Tank &operator[](TANK);
};

#endif // !GAME_TANKS

