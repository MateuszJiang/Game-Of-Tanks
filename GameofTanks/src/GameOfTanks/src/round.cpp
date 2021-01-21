#pragma once
#include "pch.h"
#include "../include/round.h"
#include "../include/Collision.h"

int Round::counter()
{
	static int counter = 0;
	return counter++;
}

Round::Round(const TANK i, const sf::Vector2<float> pos, const float rot) : ID(counter())
{
	STATE_INFO("Round Created ! ID: {0}", i);
	round_texture = new sf::Texture();
	switch (i)
	{
	case ONE:
		if (!Collision::CreateTextureAndBitmask(*round_texture, "used/Textures/round_1.png"))
			exit(4);
		break;

	case TWO:
		if (!Collision::CreateTextureAndBitmask(*round_texture, "used/Textures/round_2.png"))
			exit(4);
		break;
	case THREE:
		if (!Collision::CreateTextureAndBitmask(*round_texture, "used/Textures/round_3.png"))
			exit(4);
		break;

	case FOUR:
		if (!Collision::CreateTextureAndBitmask(*round_texture, "used/Textures/round_4.png"))
			exit(4);
		break;

	}

	round.setTexture(*round_texture);

	round.setPosition(pos);
	round.setRotation(rot);
	tank_id = i;
}

sf::Sprite *Round::get_round()
{
	return &round;
}

sf::FloatRect Round::get_bounds()
{
	return round.getGlobalBounds();
}

float Round::get_position_x()
{
	return round.getPosition().x;
}
float Round::get_position_y()
{
	return round.getPosition().y;
}
float Round::get_rotation()
{
	return round.getRotation();
}

void Round::set_rotation(float t)
{
	round.setRotation(t);
}

void Round::set_position(sf::Vector2<float> t)
{
	round.setPosition(t);
}
