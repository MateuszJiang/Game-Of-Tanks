#pragma once
#include "pch.h"
#include "../include/game.h"
#include "../include/Collision.h"

GameElements::GameElements(sf::RenderWindow& rw, PLAYERS pl)
{
	window = &rw;
	
	switch (pl)
	{
	case TWO_PLAYERS:
		numberOfPlayers = 2;
		tanks.add("One");
		tanks.add("Two");
		//tanks.add();
		tanks.get_tank(ONE).setPosition(500.f, 500.f);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(TWO).setPosition(1800.f, 800.f);
		rounds = Rounds();
		break;
	case THREE_PLAYERS:
		numberOfPlayers = 3;
		tanks.add("One");
		tanks.add("Two");
		tanks.add("Three");
		tanks.get_tank(ONE).setPosition(200.f, 200.f);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(TWO).setPosition(2800.f, 1800.f);
		tanks.get_tank(THREE).setPosition(2800.f, 300.f);
		tanks.get_tank(THREE).rotate(90);
		break;
	case FOUR_PLAYERS:
		numberOfPlayers = 4;
		tanks.add("One");
		tanks.add("Two");
		tanks.add("Three");
		tanks.add("Four");
		tanks.get_tank(ONE).setPosition(200.f, 200.f);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(TWO).setPosition(2800.f, 1800.f);
		tanks.get_tank(THREE).setPosition(2800.f, 300.f);
		tanks.get_tank(THREE).rotate(90);
		tanks.get_tank(FOUR).setPosition(300.f, 1800.f);
		tanks.get_tank(THREE).rotate(270);
		break;
	default:
		break;
	}

	game_turn_on();
}

GameElements::GameElements(GameElements* ref)
{
	numberOfPlayers = ref->numberOfPlayers;
	Players = ref->Players;
	map = ref->map;
	tanks = ref->tanks;
	window = ref->window;
	rounds = ref->rounds;
}

void GameElements::interaction(TANK tank)
{
	std::cout << "HELLO" << std::endl;
	for (int i = 0; i < rounds.get_size(); i++)
	{
		std::cout << "HELLO" << std::endl;
		if (check_if_round_hits(tank, rounds[i]))
		{
			std::cout << "HELLO" << std::endl;
			tanks[tank].decrease_health();
			rounds.destroy_round(i);
			if(! tanks[tank].get_health())
			{
				numberOfPlayers--;
				if (numberOfPlayers == 1)
				{
					tanks[tank].destroyed();
					game_turn_off();			// if tank destroyed turns the game off
				}
			}
		}
	}
	std::cout << "HELLO1" << std::endl;
	switch (tank)
	{
	case ONE:
		{
			std::cout << "HELLO1" << std::endl;
			if (check_if_tank_intersects(tank))
			{
				std::cout << "HELLO1" << std::endl;
				tanks[tank].set_position(300.f, 300.f);
				std::cout << "HELLO1" << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !check_if_tank_intersects(tank))
				tanks[tank].move(FORWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !check_if_tank_intersects(tank))
				tanks[tank].move(BACKWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !check_if_tank_intersects(tank))
				tanks[tank].turn(LEFT);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !check_if_tank_intersects(tank))
				tanks[tank].turn(RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				shoot(tank);
				CLOCK.restart();
			}
			break;	
		}
	case TWO:
		{
			if (check_if_tank_intersects(tank))
			{
				tanks[tank].set_position(2800.f, 1800.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				tanks[tank].move(FORWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				tanks[tank].move(BACKWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				tanks[tank].turn(LEFT);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				tanks[tank].turn(RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	case THREE:
		{
			if (check_if_tank_intersects(tank))
			{
				tanks[tank].set_position(2800.f, 300.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				tanks[tank].move(FORWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				tanks[tank].move(BACKWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
				tanks[tank].turn(LEFT);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				tanks[tank].turn(RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	case FOUR:
		{
			if (check_if_tank_intersects(tank))
			{
				tanks[tank].set_position(300.f, 1800.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
				tanks[tank].move(FORWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
				tanks[tank].move(BACKWARD);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
				tanks[tank].turn(LEFT);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
				tanks[tank].turn(RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	}
}

void GameElements::shoot(TANK tank)
{
	rounds.add(tanks[tank].get_id(), tanks[tank].get_position(), tanks[tank].get_rotation());
}



bool GameElements::check_if_tank_intersects(TANK tank)
{
	// THIS CHECKS IF ONE TANKS TOUCHES ANOTHER BUT CREATES A LOT OF BUGS
	switch (tank)
	{
	case ONE:
		std::cout << "HELLO2" << std::endl;
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
			return true;
		//if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
			//return true;
		//if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			//return true;
		break;
	case TWO:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
			return true;
		//if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
			//return true;
		//if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			//return true;
		break;
	case THREE:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
			return true;
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
			return true;
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			return true;
		break;
	case FOUR:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
			return true;
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
			return true;
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
			return true;
		break;
	default:
		break;
	}

	{
		if (tanks[tank].get_position_x() <= 0)
			return true;

		else if (tanks[tank].get_position_y() <= 0)
			return true;

		else if (tanks[tank].get_position_x() >= WINDOW_WIDTH)
			return true;

		else if (tanks[tank].get_position_y() >= WINDOW_HEIGHT)
			return true;

		else
			return false;
	}
}

bool GameElements::check_if_round_collides(Round& round)  // if collides with any wall
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

bool GameElements::check_if_round_hits(TANK tank, Round& round)
{
	if (Collision::PixelPerfectTest(*round.get_round(), *tanks[tank].getTank()) && round.get_rounds_tank_id() != tanks[tank].get_id())
	{
		return true;
	}
	return false;
}

void GameElements::change_round_rotation(Round& round)  // super complicated algebra to make round bounce from walls properly
{
	if (round.get_position_x() <= 0)
	{
		if (round.get_rotation() <= 180)
			round.set_rotation(180 - round.get_rotation());   
		else if (round.get_rotation() > 180)
			round.set_rotation(540 - round.get_rotation());
	}
	else if (round.get_position_x() >= WINDOW_WIDTH)
	{
		if (round.get_rotation() > 270)
			round.set_rotation(round.get_rotation() - 90);
		else if (round.get_rotation() < 90 && round.get_rotation() > 0)
			round.set_rotation(180- round.get_rotation());
		else if (round.get_rotation() == 90)
			round.set_rotation(180);
	}
	else if (round.get_position_y() <= 0)
			round.set_rotation(360 - round.get_rotation());
	else if (round.get_position_y() >= WINDOW_HEIGHT)
		round.set_rotation(360 - round.get_rotation());   
}


void GameElements::draw_map()
{
	window->draw(map.get_map());
}

void GameElements::draw_tanks()
{
	interaction(ONE);
	interaction(TWO);
	//interaction(THREE);
	//interaction(FOUR);
	window->draw(tanks.get_tank(ONE));
	window->draw(tanks.get_tank(TWO));
	//window->draw(tanks.get_tank(THREE));
	//window->draw(tanks.get_tank(FOUR));
}

void GameElements::draw_rounds()
{
	for (int i = 0; i < rounds.get_size(); i++)                         // for each existing round
	{
		if(check_if_round_collides(rounds[i]))
			change_round_rotation(rounds[i]);
		rounds.get_round(i)->move(sf::Vector2f(cos(rounds.get_round(i)->getRotation() * 3.14159 / 180) * SPEED * 5, sin(rounds.get_round(i)->getRotation() * 3.14159 / 180) * SPEED * 5));
		window->draw(*rounds.get_round(i));
	}
}


void GameElements::reset_tanks()
{
	tanks[ONE].set_position(300.f, 300.f);
	tanks[TWO].set_position(2800.f, 1800.f);
	tanks[THREE].set_position(2800.f, 300.f);
	tanks[FOUR].set_position(300.f, 1800.f);
	tanks[ONE].reset();
	tanks[TWO].reset();
	tanks[THREE].reset();
	tanks[FOUR].reset();

	switch (Players)
	{
	case TWO_PLAYERS:
		numberOfPlayers = 2;
		break;
	case THREE_PLAYERS:
		numberOfPlayers = 3;
		break;
	case FOUR_PLAYERS:
		numberOfPlayers = 4;
		break;
	default:
		break;
	}
}

void GameElements::reset_rounds()
{
	rounds.clear();
}
