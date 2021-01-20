#pragma once
#include "round.h"

#ifndef GAME_ROUNDS_H_
#define GAME_ROUNDS_H_

	class Rounds
	{
	private:
		std::vector<Round> rounds;

	public:
		Rounds() {}
		Rounds(const Rounds &other) { rounds = other.rounds; } 

		void add(TANK i, sf::Vector2<float> pos, float rot)			// adding rounds
		{
			rounds.push_back(Round(i, pos, rot));
		}

		inline sf::Sprite *get_round(int i) 
		{
			return rounds[i].get_round();
		}

		inline int get_size() { return (int) rounds.size(); } //Number of rounds active

		inline Round &operator[](int i)
		{
			return rounds[i];
		}

		inline void clear()
		{
			rounds.clear();
		}

		inline void destroy_round(int i)
		{
			rounds.erase(rounds.begin()+i);
		}
	};
#endif // !GAME_ROUNDS
