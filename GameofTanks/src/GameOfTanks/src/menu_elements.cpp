#include "pch.h"
#include "../include/menu_elements.h"


namespace GameMenu
{
	sf::Text GetPauseMessage(const sf::Font& font)
	{
		sf::Text pauseMessage;
		pauseMessage.setFont(font);
		pauseMessage.setCharacterSize(200);
		pauseMessage.setPosition(MAIN_GAME_MESSAGE);
		pauseMessage.setFillColor(sf::Color::Red);
		pauseMessage.setString("GAME PAUSED");
		pauseMessage.setStyle(sf::Text::Bold | sf::Text::Underlined);
		return pauseMessage;
	}

	sf::Text GetMainMessage(const sf::Font& font)
	{
		sf::Text mainMessage;
		mainMessage.setFont(font);
		mainMessage.setCharacterSize(100);
		mainMessage.setPosition(MAIN_GAME_MESSAGE);
		mainMessage.setFillColor(sf::Color::Red);
		mainMessage.setString("Welcome to Game Of Tanks!\nPress enter to start the game");
		mainMessage.setStyle(sf::Text::Bold | sf::Text::Underlined);
		return mainMessage;
	}

	sf::Text GetGameOverMessage(const sf::Font& font)
	{
		sf::Text gameOverMessage;
		gameOverMessage.setFont(font);
		gameOverMessage.setCharacterSize(100);
		gameOverMessage.setPosition(GAME_OVER_MESSAGE);
		gameOverMessage.setFillColor(sf::Color::Yellow);
		gameOverMessage.setString("           Game over !!! \n Press Enter to Play Again");
		return gameOverMessage;
	}

	sf::Text GetPlayerOneMsg(const sf::Font& font)
	{
		sf::Text PlayerOneMsg;
		PlayerOneMsg.setFont(font);
		PlayerOneMsg.setCharacterSize(50);
		PlayerOneMsg.setPosition(PLAYER_ONE_MESSAGE);
		PlayerOneMsg.setFillColor(sf::Color::White);
		PlayerOneMsg.setString("Player One: \nWSAD + Spacebar");
		return PlayerOneMsg;
	}
	sf::Text GetPlayerTwoMsg(const sf::Font& font)
	{
		sf::Text PlayerTwoMsg;
		PlayerTwoMsg.setFont(font);
		PlayerTwoMsg.setCharacterSize(50);
		PlayerTwoMsg.setPosition(PLAYER_TWO_MESSAGE);
		PlayerTwoMsg.setFillColor(sf::Color::White);
		PlayerTwoMsg.setString("     Player Two:\nArrows + RCtrl");
		return PlayerTwoMsg;
	}

	void restart_game_elements(GameElements* the_game, bool& is_playing)
	{
		// (re)start the game
		if (!is_playing)
		{
			is_playing = true;
		}
		// Restart after the Game Over
		else if (!the_game->is_the_game_currently_in_progress())
		{
			is_playing = true;
			the_game->reset_tanks();
			the_game->reset_rounds();
			the_game->game_turn_on();
		}
	}
}