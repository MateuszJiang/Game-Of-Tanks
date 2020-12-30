#pragma once

#include <SFML/Graphics.hpp>

#include "../include/game.h"
#include "../include/menu.h"

namespace GameMenu
{
	sf::Text GetPauseMessage(const sf::Font& font);
	sf::Text GetMainMessage(const sf::Font& font);
	sf::Text GetGameOverMessage(const sf::Font& font);
	sf::Text GetPlayerOneMsg(const sf::Font& font);
	sf::Text GetPlayerTwoMsg(const sf::Font& font);

	void restart_game_elements(GameElements* the_game, bool& is_playing);
}