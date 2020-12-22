#pragma once

#include "pch.h"
#include "universal.h"


/*
	DATA OF EACH ROUND
*/
#ifndef ROUNDS_H_
#define ROUNDS_H_

class Round
{
private:
	static int counter();
	int ID;
	TANK tank_id;			//which tank shot it ?
	sf::Texture *round_texture;
	sf::Sprite round;
public:
	Round(TANK,sf::Vector2<float>,float);

	//setters
	void set_rotation(float);
	void set_position(sf::Vector2<float>);

	//getters
	sf::Sprite *get_round();
	sf::FloatRect get_bounds();
	float get_position_x();
	float get_position_y();
	float get_rotation();
	TANK get_rounds_tank_id() { return tank_id; }
};


#endif // !ROUNDS_H_
