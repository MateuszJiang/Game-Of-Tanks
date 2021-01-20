#pragma once
#include "pch.h"
#include "../include/game_tanks.h"


void Tanks::add(std::string name)
{
	Tanks::tanks.push_back(Tank(name));
}

sf::Sprite &Tanks::get_tank(TANK x)
{
	switch (x)
	{
		case ONE:
			return *(Tanks::tanks[0].getTank());
			break;
		case TWO:
			return *(Tanks::tanks[1].getTank());
			break;
		case THREE:
			return *(Tanks::tanks[2].getTank());
			break;
		case FOUR:
			return *(Tanks::tanks[3].getTank());
			break;
		default:
			break;
	}
	
}

sf::FloatRect Tanks::get_bounds_of_tank(TANK x)
{
	switch (x)
	{
		case ONE:
			return (Tanks::tanks[0].getBounds());
			break;
		case TWO:
			return (Tanks::tanks[1].getBounds());
			break;
		case THREE:
			return (Tanks::tanks[2].getBounds());
			break;
		case FOUR:
			return (Tanks::tanks[3].getBounds());
			break;
		default:
			break;
	}
}

Tank &Tanks::operator[](TANK x)
{
	switch (x)
	{
		case ONE:
			return tanks[0];
			break;
		case TWO:
			return tanks[1];
			break;
		case THREE:
			return tanks[2];
			break;
		case FOUR:
			return tanks[3];
			break;
		default:
			break;
	}
}
