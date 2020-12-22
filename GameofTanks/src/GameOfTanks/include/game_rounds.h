#pragma once
#include "pch.h"
#include "round.h"



/*
	THIS CLASS STORES THE TANKS AND ALLOWS THEM TO BE USED IN MAIN
*/

#ifndef GAME_ROUNDS_H_
#define GAME_ROUNDS_H_


	class Rounds
	{
	private:
		std::vector<Round> rounds;      // vector of Rounds

	public:
		Rounds() {}
		Rounds(const Rounds &other) { rounds = other.rounds; }  // copy constructor (maybe useful)

		void add(TANK i, sf::Vector2<float> pos, float rot)			// adding rounds
		{
			rounds.push_back(Round(i, pos, rot));
		}

		sf::Sprite *get_round(int i)                              // Sprite of tank
		{
			return rounds[i].get_round();
		}

		int get_size() { return rounds.size(); }                      //Number of rounds active

		Round &operator[](int i)
		{
			return rounds[i];
		}

		void clear()
		{
			rounds.clear();
		}

		void destroy_round(int i)
		{
			rounds.erase(rounds.begin()+i);
		}
	};






#endif // !GAME_ROUNDS

