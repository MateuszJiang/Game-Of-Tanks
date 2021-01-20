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

	static int tank_counter;
	int ID;

	int health;
	std::string tank_name;
	sf::Texture * tank_texture;
	sf::Sprite tank_sprite;					//the tank itself
	
	bool is_playing = true;

public:
	TANK get_id();
	Tank(std::string);
	~Tank();
	Tank(const Tank&);
	Tank(const Tank&&);
	Tank& operator=(Tank&);
	Tank& operator=(Tank&&);

	Tank() = delete;
	Tank(const Tank*) = delete;

	void createTank();						 // Creation of the tank
	void set_position(float,float);
	void set_position(sf::Vector2f);

	// getters
	sf::Sprite *getTank();				// Sprite of Tank
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

	inline static int get_counter() { return tank_counter; }
};


#endif // !TANK_DRAWER
