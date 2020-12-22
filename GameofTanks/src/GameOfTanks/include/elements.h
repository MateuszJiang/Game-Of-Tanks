#include "pch.h"
/*
#include "universal.h"
#include "map.h"
#include "game_rounds.h"
#include "game_tanks.h"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


	EVERYTHING THAT I SHOULD IMPLEMENT BUT LIFE IS A BITCH


Rounds rounds;
sf::Clock CLOCK;

void interaction(Tanks&, TANK, Rounds&);		              //taking keyboard input so we can steer the tanks
void shoot(Tank&);										      // handles the rounds shot by the tanks

void draw_map(sf::RenderWindow&, Map&);						  // draws map
void draw_tanks(sf::RenderWindow&, Tanks&, Rounds&);		  // draws tanks
void draw_rounds(sf::RenderWindow&, Rounds&);				  // draws rounds

bool check_if_tank_intersects(Tanks&, TANK);				  // collision of Tanks
bool check_if_round_collides(Round&);						  // collision of Rounds
bool check_if_round_hits(Tank&, Round&);					  // collision of Rounds with Tank

void change_round_rotation(Round&);							  //changing rotation after collision



void draw_map(sf::RenderWindow& main, Map& map)
{
	main.draw(map.get_map());
}

void draw_tanks(sf::RenderWindow& main, Tanks& tanks, Rounds& rounds)
{
	interaction(tanks, ONE, rounds);
	interaction(tanks, TWO, rounds);
	main.draw(tanks.get_tank(ONE));
	main.draw(tanks.get_tank(TWO));
}

void draw_rounds(sf::RenderWindow& main, Rounds& rounds)
{
	for (int i = 0; i < rounds.get_size(); i++)                         // for each existing round
	{
		change_round_rotation( rounds[i] );
		rounds.get_round(i)->move(sf::Vector2f(cos(rounds.get_round(i)->getRotation() * 3.14159 / 180) * SPEED * 5, sin(rounds.get_round(i)->getRotation() * 3.14159 / 180) * SPEED * 5));
		main.draw( *rounds.get_round(i) );
	}
}

void interaction(Tanks& object, TANK tank, Rounds& rounds)
{
	for (int i = 0; i < rounds.get_size(); i++)
	{
		if (check_if_round_hits(object[tank], rounds[i]))
		{
			object[tank].destroyed();
			std::cout << "HIT" << std::endl;
		}
	}

	if (object[tank].get_id() == ONE)
	{
		if (check_if_tank_intersects(object, tank))
		{
			object[tank].set_position(300.f, 300.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ! check_if_tank_intersects(object,tank))
			object[tank].move(FORWARD);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !check_if_tank_intersects(object, tank))
			object[tank].move(BACKWARD);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !check_if_tank_intersects(object, tank))
			object[tank].turn(LEFT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !check_if_tank_intersects(object, tank))
			object[tank].turn(RIGHT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && CLOCK.restart().asSeconds() > 1.f)
			shoot(object[tank]);
	}
	else if (object[tank].get_id() == TWO)
	{
		if (check_if_tank_intersects(object, tank))
		{
			object[tank].set_position(1800.f, 1600.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			object[tank].move(FORWARD);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			object[tank].move(BACKWARD);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			object[tank].turn(LEFT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			object[tank].turn(RIGHT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && CLOCK.restart().asSeconds() > 1.f)
			shoot(object[tank]);
	}
}

void shoot(Tank& tank)
{
	rounds.add(tank.get_id(), tank.get_position(), tank.get_rotation());
}

void change_round_rotation(Round& round)
{
	if (check_if_round_collides(round))                       // check if round collides with walls
	{
		round.set_rotation(round.get_rotation() - 180);   // change the rotation so it bounces off
	}
}

bool check_if_tank_intersects(Tanks& object, TANK tank)
{
	/*if(tank == ONE)
		if ( object[tank].getBounds()->intersects( *object[TWO].getBounds() ))
			return true;

	if(tank == TWO)
		if (object[tank].getBounds()->intersects(*object[ONE].getBounds()))
			return true;

	{
		if (object[tank].get_position_x() <= 0)
			return true;

		else if (object[tank].get_position_y() <= 0)
			return true;

		else if (object[tank].get_position_x()  >= WINDOW_WIDTH)
			return true;

		else if (object[tank].get_position_y()  >= WINDOW_HEIGHT)
			return true;

		else
			return false;
	}
}

bool check_if_round_collides(Round& round)
{
	if (round.get_position_x() <= 0)
		return true;

	else if (round.get_position_x() >= WINDOW_WIDTH)
		return true;

	else if (round.get_position_y() <= 0)
		return true;

	else if (round.get_position_y() >= WINDOW_HEIGHT)
		return true;

	else
		return false;
}

bool check_if_round_hits(Tank& tank, Round& round)
{
	if (round.get_bounds().intersects( *tank.getBounds() ))
	{
		std::cout << "inter" << std::endl;
		return true;
	}

	std::cout << "no inter" << std::endl;
	return false;
}

*/