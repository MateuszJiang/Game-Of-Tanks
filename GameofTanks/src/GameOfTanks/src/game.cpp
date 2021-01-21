#pragma once
#include "pch.h"
#include "../include/game.h"
#include "../include/Collision.h"

GameElements::GameElements(sf::RenderWindow& rw, PLAYERS pl)
{
	STATE_INFO("Game constructor !");

	window = &rw;
	
	switch (pl)
	{
	case TWO_PLAYERS:
		numberOfPlayers = 2;
		tanks.add("One");
		tanks.add("Two");
		tanks.get_tank(ONE).setPosition(TANK_ONE_DEFAULT_POSITION);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(TWO).setPosition(TANK_TWO_DEFAULT_POSITION);
		rounds = Rounds();
		break;
	case THREE_PLAYERS:
		numberOfPlayers = 3;
		tanks.add("One");
		tanks.add("Two");
		tanks.add("Three");
		tanks.get_tank(ONE).setPosition(TANK_ONE_DEFAULT_POSITION);
		tanks.get_tank(TWO).setPosition(TANK_TWO_DEFAULT_POSITION);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(THREE).setPosition(2800.f, 300.f);
		tanks.get_tank(THREE).rotate(90);
		break;
	case FOUR_PLAYERS:
		numberOfPlayers = 4;
		tanks.add("One");
		tanks.add("Two");
		tanks.add("Three");
		tanks.add("Four");
		tanks.get_tank(ONE).setPosition(TANK_ONE_DEFAULT_POSITION);
		tanks.get_tank(TWO).setPosition(TANK_TWO_DEFAULT_POSITION);
		tanks.get_tank(TWO).rotate(180);
		tanks.get_tank(THREE).setPosition(2800.f, 300.f);
		tanks.get_tank(THREE).rotate(90);
		tanks.get_tank(FOUR).setPosition(300.f, 1800.f);
		tanks.get_tank(FOUR).rotate(270);
		break;
	default:
		break;
	}

	game_turn_on();
}

void GameElements::game_turn_off() 
{ 
	STATE_INFO("Game Turned Off");
	game_on = false; 
}
void GameElements::game_turn_on() 
{
	STATE_INFO("Game Turned On");
	game_on = true; 
}

GameElements::GameElements(GameElements* pGameElements)
{
	STATE_CORE_WARN("Copy Constructor evoked!");
	numberOfPlayers = pGameElements->numberOfPlayers;
	Players = pGameElements->Players;
	map = pGameElements->map;
	tanks = pGameElements->tanks;
	window = pGameElements->window;
	rounds = pGameElements->rounds;
}

void GameElements::interaction(TANK tank)
{
	for (int i = 0; i < rounds.get_size(); i++)
	{
		if (check_if_round_hits(tank, rounds[i]))
		{
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
	switch (tank)
	{
	case ONE:
		{
			if (check_if_tank_intersects(tank))
			{
				STATE_TRACE("Tank {0} intersected", tank);
				tanks[tank].set_position(TANK_ONE_DEFAULT_POSITION);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !check_if_tank_intersects(tank))
			{
				STATE_INFO("Tank {0} moved {1}", tank, FORWARD);
				tanks[tank].move(FORWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !check_if_tank_intersects(tank))
			{
				STATE_INFO("Tank {0} moved {1}", tank, BACKWARD);
				tanks[tank].move(BACKWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !check_if_tank_intersects(tank))
			{
				STATE_INFO("Tank {0} turning {1}", tank, LEFT);
				tanks[tank].turn(LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !check_if_tank_intersects(tank))
			{ 
				STATE_INFO("Tank {0} turning {1}", tank, RIGHT);
				tanks[tank].turn(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				STATE_INFO("Tank {0} shot a missle}", tank);
				shoot(tank);
				CLOCK.restart();
			}
			break;	
		}
	case TWO:
		{
			if (check_if_tank_intersects(tank))
			{
				STATE_TRACE("Tank {0} intersected", tank);
				tanks[tank].set_position(TANK_TWO_DEFAULT_POSITION);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				STATE_INFO("Tank {0} moved {1}", tank, FORWARD);
				tanks[tank].move(FORWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				STATE_INFO("Tank {0} moved {1}", tank, BACKWARD);
				tanks[tank].move(BACKWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				STATE_INFO("Tank {0} turning {1}", tank, LEFT);
				tanks[tank].turn(LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				STATE_INFO("Tank {0} turning {1}", tank, RIGHT);
				tanks[tank].turn(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				STATE_INFO("Tank {0} shot a missle}", tank);
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	case THREE:
		{
			if (check_if_tank_intersects(tank))
			{
				STATE_TRACE("Tank {0} intersected", tank);
				tanks[tank].set_position(TANK_THREE_DEFAULT_POSITION);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			{
				STATE_INFO("Tank {0} moved {1}", tank, FORWARD);
				tanks[tank].move(FORWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				STATE_INFO("Tank {0} moved {1}", tank, BACKWARD);
				tanks[tank].move(BACKWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				STATE_INFO("Tank {0} turning {1}", tank, LEFT);
				tanks[tank].turn(LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			{
				STATE_INFO("Tank {0} turning {1}", tank, RIGHT);
				tanks[tank].turn(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				STATE_INFO("Tank {0} shot a missle}", tank);
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	case FOUR:
		{
			if (check_if_tank_intersects(tank))
			{
				STATE_TRACE("Tank {0} intersected", tank);
				tanks[tank].set_position(TANK_FOUR_DEFAULT_POSITION);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
			{
				STATE_INFO("Tank {0} moved {1}", tank, FORWARD);
				tanks[tank].move(FORWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
			{
				STATE_INFO("Tank {0} moved {1}", tank, BACKWARD);
				tanks[tank].move(BACKWARD);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
			{
				STATE_INFO("Tank {0} turning {1}", tank, LEFT);
				tanks[tank].turn(LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
			{
				STATE_INFO("Tank {0} turning {1}", tank, RIGHT);
				tanks[tank].turn(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && CLOCK.getElapsedTime().asMilliseconds() > 2500)
			{
				STATE_INFO("Tank {0} shot a missle}", tank);
				shoot(tank);
				CLOCK.restart();
			}
			break;
		}
	}
}

void GameElements::shoot(TANK tank)
{
	STATE_INFO("Round Shot! by tank {0}", tank);
	rounds.add(tanks[tank].get_id(), tanks[tank].get_position(), tanks[tank].get_rotation());
}



bool GameElements::check_if_tank_intersects(TANK tank)
{
	switch (tank)
	{
	case ONE:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, TWO);
			return true;
		}
		if (numberOfPlayers >= 3)
			if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
			{
				STATE_INFO("Tank {} collision with tank {1}.", tank, THREE);
				return true;
			}
		if(numberOfPlayers >= 4)
			if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			{
				STATE_INFO("Tank {} collision with tank {1}.", tank, FOUR);
				return true;
			}
		break;
	case TWO:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, ONE);
			return true;
		}
		if (numberOfPlayers >= 3)
			if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
			{
				STATE_INFO("Tank {} collision with tank {1}.", tank, THREE);
				return true;
			}
		if (numberOfPlayers >= 4)
			if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			{
				STATE_INFO("Tank {} collision with tank {1}.", tank, FOUR);
				return true;
			}
		break;
	case THREE:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, TWO);
			return true;
		}
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, ONE);
			return true;
		}
		if (numberOfPlayers >= 4)
			if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[FOUR].getTank()))
			{
				STATE_INFO("Tank {} collision with tank {1}.", tank, FOUR);
				return true;
			}
		break;
	case FOUR:
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[TWO].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, TWO);
			return true;
		}
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[THREE].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, THREE);
			return true;
		}
		if (Collision::PixelPerfectTest(*tanks[tank].getTank(), *tanks[ONE].getTank()))
		{
			STATE_INFO("Tank {} collision with tank {1}.", tank, FOUR);
			return true;
		}
		break;
	default:
		break;
	}

	{
		if (tanks[tank].get_position_x() <= 0)
		{
			STATE_INFO("Tank {0} outside bounds.", tank);
			return true;
		}
		else if (tanks[tank].get_position_y() <= 0)
		{
			STATE_INFO("Tank {0} outside bounds.", tank);
			return true;
		}
		else if (tanks[tank].get_position_x() >= WINDOW_WIDTH)
		{
			STATE_INFO("Tank {0} outside bounds.", tank);
			return true;
		}
		else if (tanks[tank].get_position_y() >= WINDOW_HEIGHT)
		{
			STATE_INFO("Tank {0} outside bounds.", tank);
			return true;
		}
		else
		{
			return false;
		}
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
	if (numberOfPlayers == 2)
	{
		interaction(ONE);
		interaction(TWO);
	}
	else if (numberOfPlayers == 3)
	{
		interaction(ONE);
		interaction(TWO);
		interaction(THREE);
	}
	else if (numberOfPlayers == 4)
	{
		interaction(ONE);
		interaction(TWO);
		interaction(THREE);
		interaction(FOUR);
	}
	if (numberOfPlayers == 2)
	{
		window->draw(tanks.get_tank(ONE));
		window->draw(tanks.get_tank(TWO));
	}
	else if (numberOfPlayers == 3)
	{
		window->draw(tanks.get_tank(ONE));
		window->draw(tanks.get_tank(TWO));
		window->draw(tanks.get_tank(THREE));
	}
	else if (numberOfPlayers == 4)
	{
		window->draw(tanks.get_tank(ONE));
		window->draw(tanks.get_tank(TWO));
		window->draw(tanks.get_tank(THREE));
		window->draw(tanks.get_tank(FOUR));
	}
}

void GameElements::draw_rounds()
{
	for (int i = 0; i < rounds.get_size(); i++)                         // for each existing round
	{
		if(check_if_round_collides(rounds[i]))
			change_round_rotation(rounds[i]);

		rounds.get_round(i)->move(sf::Vector2f( 
			cos(rounds.get_round(i)->getRotation() * (float)(3.14159 / 180)) * SPEED * 5,
			sin(rounds.get_round(i)->getRotation() * (float)(3.14159 / 180)) * SPEED * 5
			));

		window->draw(*rounds.get_round(i));
	}
}

void GameElements::reset_tanks()
{
	STATE_CORE_INFO("TANKS RESET");
	if (numberOfPlayers == 2)
	{
		tanks[ONE].set_position(TANK_ONE_DEFAULT_POSITION);
		tanks[TWO].set_position(TANK_TWO_DEFAULT_POSITION);
	}
	else if (numberOfPlayers == 3)
	{
		tanks[ONE].set_position(TANK_ONE_DEFAULT_POSITION);
		tanks[TWO].set_position(TANK_TWO_DEFAULT_POSITION);
		tanks[THREE].set_position(TANK_THREE_DEFAULT_POSITION);
	}
	else if (numberOfPlayers == 4)
	{
		tanks[ONE].set_position(TANK_ONE_DEFAULT_POSITION);
		tanks[TWO].set_position(TANK_TWO_DEFAULT_POSITION);
		tanks[THREE].set_position(TANK_THREE_DEFAULT_POSITION);
		tanks[FOUR].set_position(TANK_FOUR_DEFAULT_POSITION);
	}
	if (numberOfPlayers == 2)
	{
		tanks[ONE].reset();
		tanks[TWO].reset();
	}
	else if (numberOfPlayers == 3)
	{
		tanks[ONE].reset();
		tanks[TWO].reset();
		tanks[THREE].reset();
	}
	else if (numberOfPlayers == 4)
	{
		tanks[ONE].reset();
		tanks[TWO].reset();
		tanks[THREE].reset();
		tanks[FOUR].reset();
	}

	switch (Players)
	{
		case TWO_PLAYERS:
		{
			numberOfPlayers = 2;
			STATE_CORE_INFO("GameElements::reset_tanks()  -> {0} players set", numberOfPlayers);
			break;
		}
		
		case THREE_PLAYERS:
		{
			numberOfPlayers = 3;
			STATE_CORE_INFO("GameElements::reset_tanks()  -> {0} players set", numberOfPlayers);
			break;
		}
		case FOUR_PLAYERS:
		{
			numberOfPlayers = 4;
			STATE_CORE_INFO("GameElements::reset_tanks()  -> {0} players set", numberOfPlayers);
			break;
		}
		
		default:
			break;
	}
}

void GameElements::reset_rounds()
{
	rounds.clear();
}
