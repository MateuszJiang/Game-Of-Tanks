#pragma once
#include "pch.h"
#include "../include/tank.h"
#include "../include/Collision.h"

// constructors
Tank::Tank(std::string name) : tank_name(name), ID(tank_counter()), is_playing(true), health(TANK_HEALTH)
{
	std::cout << "Con1" << std::endl;
	createTank();
}

Tank::Tank() : tank_name("empty_tank"), is_playing(false), health(0), ID(tank_counter())
{
	std::cout << "Con2" << std::endl;
}

void Tank::operator=(Tank* other)
{
	health = other->health;
	*tank_texture = std::move(*other->tank_texture);
	is_playing = other->is_playing;
	ID = other->ID;
	tank_name = other->tank_name;
	tank = other->tank;
	std::cout << "Con=" << std::endl;
}


Tank::Tank(const Tank* other) : ID(other->ID), tank_name(other->tank_name), tank(other->tank), tank_texture(new sf::Texture(*other->tank_texture)), is_playing(other->is_playing), health(other->health) { std::cout << "CopyCon" << std::endl; }


// getters
TANK Tank::get_id()
{
	std::cout << ID << std::endl;
	switch (ID)
	{
	case 0:
		return ONE;
	case 1:
		return TWO;
	case 2:
		return THREE;
	case 3:
		return FOUR;
	default:
		exit(5);
	}
	
}

sf::Sprite *Tank::getTank()
{
	return &tank;
}

const sf::Vector2f Tank::get_position()		// return the middle point of front of the tank (it's purely for shooting purposes)
{
	sf::Vector2f pos = tank.getPosition();
	pos.y = pos.y + 298.3287 * sin(tank.getRotation()  * PI / 180);
	pos.x = pos.x + 298.3287 * cos(tank.getRotation()  * PI / 180);
	return pos;
}

const float Tank::get_rotation()
{
	return tank.getRotation();
}

float Tank::get_position_x()
{
	return tank.getPosition().x;
}
float Tank::get_position_y()
{
	return tank.getPosition().y;
}


sf::FloatRect Tank::getBounds()
{
	return tank.getGlobalBounds();
}

float Tank::get_local_bound_x()
{
	return tank.getLocalBounds().width;
}
float Tank::get_local_bound_y()
{
	return tank.getLocalBounds().height;
}

// setter
void Tank::set_position(float x, float y)
{
	tank.setPosition(x, y);
}

// Used in constructors
void Tank::createTank()
{
	tank_texture = new sf::Texture();
	// take tank texture
	switch (get_id())
	{
	case ONE:
		{
			if ( !Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_1.png") )
			{
				exit(3);
			}
			tank.setTexture(*tank_texture);   // assign texture to the tank
			break;
		}
	case TWO:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_2.png"))
		{
			exit(3);
		}
		tank.setTexture(*tank_texture);   // assign texture to the tank
		break;
	}
	case THREE:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_3.png"))
		{
			exit(3);
		}
		tank.setTexture(*tank_texture);   // assign texture to the tank
		break;
	}
	case FOUR:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_4.png"))
		{
			exit(3);
		}
		tank.setTexture(*tank_texture);   // assign texture to the tank
		break;
	}
	}

	tank.setTextureRect(sf::IntRect(0, 0, 290, 140));
	tank.setOrigin(sf::Vector2f(0.f, 70.f));           // sets the operating point in the middle of back axis
}

int Tank::tank_counter()
{
	static int counter = 0;
	return counter++;
}

void Tank::turn(TURN way)
{
	if (is_playing)
	{
		if (way == LEFT)
		{
			Tank::tank.rotate(-SPEED);
		}
		else if (way == RIGHT)
		{
			Tank::tank.rotate(SPEED);
		}
	}
}

void Tank::move(MOVE way)
{
	if (is_playing)
	{
		if (way == FORWARD)
		{
			Tank::tank.move(sf::Vector2f(cos(tank.getRotation() * PI / 180) * SPEED, sin(tank.getRotation() * PI / 180) * SPEED));
		}

		else if (way == BACKWARD)
		{
			Tank::tank.move(sf::Vector2f(cos(tank.getRotation() * PI / 180) * -SPEED, sin(tank.getRotation() * PI / 180) * -SPEED));
		}
	}
}


void Tank::destroyed()  // if the tank is hit player cannot do anything
{
	is_playing = false;
}

void Tank::reset()
{ 
	is_playing = true; 
}