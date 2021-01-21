#pragma once
#include "pch.h"
#include "../include/tank.h"
#include "../include/Collision.h"

int Tank::tank_counter = 0;

// constructors
Tank::Tank(std::string name) : tank_name(name), ID(tank_counter++), is_playing(true), health(TANK_HEALTH)
{
	STATE_INFO("Tank constructor !");
	STATE_CORE_INFO("Tank counter: {0}", tank_counter);
	createTank();
}

Tank::~Tank()
{
	tank_counter--;
	STATE_INFO("Tank Destructor !");
	STATE_CORE_INFO("Tank counter: {0}", tank_counter);
}

Tank::Tank(const Tank& copyTank)
{
	tank_counter++;
	STATE_WARN("Copy constructor !!!");

	ID = copyTank.ID;

	health = copyTank.health;
	tank_name = copyTank.tank_name;

	tank_texture = new sf::Texture();
	tank_texture = std::move(copyTank.tank_texture);

	tank_sprite = copyTank.tank_sprite;

	is_playing = copyTank.is_playing;
}

Tank::Tank(const Tank&& copyTank)
{
	tank_counter++;
	STATE_WARN("Move constructor !!!");

	ID = copyTank.ID;

	health = copyTank.health;
	tank_name = copyTank.tank_name;

	tank_texture = new sf::Texture();
	tank_texture = std::move(copyTank.tank_texture);

	tank_sprite = copyTank.tank_sprite;

	is_playing = copyTank.is_playing;
}


Tank& Tank::operator=(Tank& copyTank)
{
	tank_counter++;
	STATE_WARN("Copy assignent constructor !");
	ID = copyTank.ID;

	health = copyTank.health;
	tank_name = copyTank.tank_name;

	tank_texture = new sf::Texture();
	tank_texture = std::move(copyTank.tank_texture);

	tank_sprite = copyTank.tank_sprite;

	is_playing = copyTank.is_playing;

	return *this;
}

Tank& Tank::operator=(Tank&& copyTank)
{
	STATE_WARN("Move assignent constructor !");
	ID = copyTank.ID;

	health = copyTank.health;
	tank_name = copyTank.tank_name;

	tank_texture = new sf::Texture();
	tank_texture = std::move(copyTank.tank_texture);

	tank_sprite = copyTank.tank_sprite;

	is_playing = copyTank.is_playing;

	return *this;
}

// getters
TANK Tank::get_id()
{
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
	return &tank_sprite;
}

const sf::Vector2f Tank::get_position()		// return the middle point of front of the tank (it's purely for shooting purposes)
{
	sf::Vector2f pos = tank_sprite.getPosition();
	pos.y = pos.y + (float)298.3287 * sin(tank_sprite.getRotation()  * (float)(PI / 180));
	pos.x = pos.x + (float)298.3287 * cos(tank_sprite.getRotation()  * (float)(PI / 180));
	return pos;
}

const float Tank::get_rotation()
{
	return tank_sprite.getRotation();
}

float Tank::get_position_x()
{
	return tank_sprite.getPosition().x;
}
float Tank::get_position_y()
{
	return tank_sprite.getPosition().y;
}


sf::FloatRect Tank::getBounds()
{
	return tank_sprite.getGlobalBounds();
}
float Tank::get_local_bound_x()
{
	return tank_sprite.getLocalBounds().width;
}
float Tank::get_local_bound_y()
{
	return tank_sprite.getLocalBounds().height;
}

// setter
void Tank::set_position(float x, float y)
{
	tank_sprite.setPosition(x, y);
}

void Tank::set_position(sf::Vector2f xy)
{
	tank_sprite.setPosition(xy);
}

// Used in constructors
void Tank::createTank()
{
	STATE_INFO("createTank method");
	tank_texture = new sf::Texture();
	// take tank texture
	switch (get_id())
	{
	case ONE:
	{
		if ( !Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_1.png") )
		{
			STATE_CORE_ERROR("Problem with reading texture for tank {0}", get_id());
			exit(3);
		}
		tank_sprite.setTexture(*tank_texture);
		break;
	}
	case TWO:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_2.png"))
		{
			STATE_CORE_ERROR("Problem with reading texture for tank {0}", get_id());
			exit(3);
		}
		tank_sprite.setTexture(*tank_texture);
		break;
	}
	case THREE:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_3.png"))
		{
			STATE_CORE_ERROR("Problem with reading texture for tank {0}", get_id());
			exit(3);
		}
		tank_sprite.setTexture(*tank_texture);
		break;
	}
	case FOUR:
	{
		if (!Collision::CreateTextureAndBitmask(*tank_texture, "used/Textures/tank_4.png"))
		{
			STATE_CORE_ERROR("Problem with reading texture for tank {0}", get_id());
			exit(3);
		}
		tank_sprite.setTexture(*tank_texture);
		break;
	}
	}

	tank_sprite.setTextureRect(sf::IntRect(0, 0, 290, 140));
	tank_sprite.setOrigin(sf::Vector2f(0.f, 70.f));// sets the operating point in the middle of back axis
}

void Tank::turn(TURN way)
{
	if (is_playing)
	{
		if (way == LEFT)
		{
			Tank::tank_sprite.rotate(-SPEED);
		}
		else if (way == RIGHT)
		{
			Tank::tank_sprite.rotate(SPEED);
		}
	}
}

void Tank::move(MOVE way)
{
	if (is_playing)
	{
		if (way == FORWARD)
		{
			Tank::tank_sprite.move(sf::Vector2f(
				cos( tank_sprite.getRotation() * (float)(PI / 180)) * SPEED, 
				sin( tank_sprite.getRotation() * (float)(PI / 180)) * SPEED
			));
		}
		else if (way == BACKWARD)
		{
			Tank::tank_sprite.move(sf::Vector2f(
				cos(tank_sprite.getRotation() * (float)(PI / 180)) * -SPEED,
				sin(tank_sprite.getRotation() * (float)(PI / 180)) * -SPEED
			));
		}
	}
}

void Tank::destroyed()  // if the tank is destroyed player cannot do anything
{
	STATE_INFO("TANK destroyed");
	is_playing = false;
}

void Tank::reset()
{ 
	STATE_INFO("TANK reset");
	is_playing = true; 
}