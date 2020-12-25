#pragma once
#include "universal.h"

/*
	THIS CLASS HAS DATA OF EACH TANK AND DRAWS IT
*/

#ifndef TANK_DRAWER_H_
#define TANK_DRAWER_H_

class Tank
{
private:

	static int tank_counter();
	int ID;

	int health;
	std::string tank_name;
	sf::Texture * tank_texture;
	sf::Sprite tank;					//the tank itself
	
	bool is_playing = true;

public:
	TANK get_id();

	Tank();
	Tank(std::string);
	Tank(const Tank*);
	void operator=(Tank*);
	~Tank() { ID = 0; }

	void createTank();						 // Creation of the tank
	void set_position(float,float);
	void set_position(sf::Vector2f);

	// getters
	sf::Sprite  *getTank();				// Sprite of Tank
	const float get_rotation();

	sf::FloatRect getBounds();				// bounds of Tank
	float get_local_bound_x();
	float get_local_bound_y();

	const sf::Vector2f get_position();    // return the middle point of front of the tank (it's purely for shooting purposes)
	float get_position_x();
	float get_position_y();

	void decrease_health() { --health; }
	int get_health() { return health; }

	// interactions with the tank
	void turn(TURN);
	void move(MOVE);

	void destroyed();
	void reset();
};


#endif // !TANK_DRAWER
