#pragma once

#include <SFML/Graphics.hpp>

#include "map.h"
#include "game_rounds.h"
#include "game_tanks.h"


class GameElements
{
private:
	sf::Clock CLOCK;
	sf::RenderWindow *window;
	PLAYERS Players;
	int numberOfPlayers;

	Rounds rounds;
	Tanks tanks;
	Map map;

	bool game_on = false;

public:
	GameElements() {}
	GameElements(sf::RenderWindow&, PLAYERS);
	GameElements(GameElements*);

	inline sf::Time set_up_clock() { return CLOCK.restart(); }
	void game_turn_off();
	void game_turn_on();

	void interaction(TANK);										  //taking keyboard input so we can steer the tanks
	void shoot(TANK);										      // handles the rounds shot by the tanks

	void draw_map();											  // draws map
	void draw_tanks();											  // draws tanks
	void draw_rounds();											  // draws rounds

	bool check_if_tank_intersects(TANK);						  // collision of Tanks
	bool check_if_round_collides(Round&);						  // collision of Rounds
	bool check_if_round_hits(TANK, Round&);						  // collision of Rounds with Tank

	void change_round_rotation(Round&);							  //changing rotation after collision

	void reset_tanks();											  //Tanks go back to initial positions
	void reset_rounds();

	bool is_the_game_currently_in_progress() { return game_on; }					  // False if 1 tank left
};