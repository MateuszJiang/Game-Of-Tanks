#pragma once
#include "pch.h"

#include "../include/game.h"
#include "../include/menu.h"

int main()
{
	GameOfTanks::Log::Init();

	// creating the window displaying the game
	sf::RenderWindow main_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		"Game Of Tanks", sf::Style::Default);
	main_window.setVerticalSyncEnabled(true);
	
	Menu menu;

	sf::Font font;
	if (!font.loadFromFile("used/fonts/ComicSans.ttf"))
		return EXIT_FAILURE;

	// Initialize the pause message
	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(100);
	pauseMessage.setPosition(MAIN_GAME_MESSAGE);
	pauseMessage.setFillColor(sf::Color::Red);
	pauseMessage.setString("Welcome to Game Of Tanks!\nPress enter to start the game");
	pauseMessage.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Text gameOverMessage;
	gameOverMessage.setFont(font);
	gameOverMessage.setCharacterSize(100);
	gameOverMessage.setPosition(GAME_OVER_MESSAGE);
	gameOverMessage.setFillColor(sf::Color::Yellow);
	gameOverMessage.setString("           Game over !!! \n Press Enter to Play Again");

	sf::Text PlayerOneMsg;
	PlayerOneMsg.setFont(font);
	PlayerOneMsg.setCharacterSize(50);
	PlayerOneMsg.setPosition(PLAYER_ONE_MESSAGE);
	PlayerOneMsg.setFillColor(sf::Color::White);
	PlayerOneMsg.setString("Player One: \nWSAD + Spacebar");

	sf::Text PlayerTwoMsg;
	PlayerTwoMsg.setFont(font);
	PlayerTwoMsg.setCharacterSize(50);
	PlayerTwoMsg.setPosition(PLAYER_TWO_MESSAGE);
	PlayerTwoMsg.setFillColor(sf::Color::White);
	PlayerTwoMsg.setString("     Player Two:\nArrows + RCtrl");

	GameElements *the_game;
	the_game = new GameElements();  // initialization so the compiler does not cry
	PLAYERS number_of_players;

	bool is_playing = false;
	// The loop in which the game is happening
	while (main_window.isOpen())
	{
		sf::Event event;
		while (main_window.pollEvent(event) && (!is_playing))
		{
			switch (event.type)
			{
				case sf::Event::KeyReleased:
				{
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							STATE_TRACE("Menu up!");
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							STATE_TRACE("Menu down!");
							menu.MoveDown();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedItem())
							{
								STATE_TRACE("Menu Enter!");
								case 0:
									STATE_TRACE("Menu 2 players option chosen!");
									delete the_game;
									number_of_players = TWO_PLAYERS;
									the_game = new GameElements(main_window, PLAYERS(number_of_players));  // creating everything the game consists of
									// (re)start the game
									if (!is_playing)
									{
										is_playing = true;
									}
									// After Game Over
									else if (!the_game->get_game_state())
									{
										is_playing = true;
										the_game->reset_tanks();
										the_game->reset_rounds();
										the_game->game_turn_on();
									}
									break;
								case 1:
									delete the_game;
									number_of_players = THREE_PLAYERS;
									the_game = new GameElements(main_window, PLAYERS(number_of_players));  // creating everything the game consists of
									// (re)start the game
									if (!is_playing)
									{
										is_playing = true;
									}
									// After Game Over
									else if (!the_game->get_game_state())
									{
										is_playing = true;
										the_game->reset_tanks();
										the_game->reset_rounds();
										the_game->game_turn_on();
									}
									break;
								case 2:
									delete the_game;
									number_of_players = FOUR_PLAYERS;
									the_game = new GameElements(main_window, PLAYERS(number_of_players));  // creating everything the game consists of
									// (re)start the game
									if (!is_playing)
									{
										is_playing = true;
									}
									// After Game Over
									else if (!the_game->get_game_state())
									{
										is_playing = true;
										the_game->reset_tanks();
										the_game->reset_rounds();
										the_game->game_turn_on();
									}
									break;
								case 3:
									main_window.close();
									break;
							}
							break;
						case sf::Keyboard::LControl:
							STATE_TRACE("Game Paused (LCtrl)");
							is_playing = false;
							break;
					default:
						break;
					}
					break;
				}
				case sf::Event::Closed:
					main_window.close();
					break;
			}
		}

		if (event.key.code == sf::Keyboard::LControl)
		{
			STATE_TRACE("Game Paused (LCtrl)");
			is_playing = false;
		}
		main_window.clear(sf::Color::Black);

		if (is_playing)
		{
			//STATE_TRACE("Game On, drawing elements");
			the_game->draw_map();
			the_game->draw_tanks();
			the_game->draw_rounds();
			
		}
		if (!is_playing && the_game->get_game_state())
		{
			//STATE_TRACE("Game Paused, drawing Pause message");
			main_window.draw(pauseMessage);
			main_window.draw(PlayerOneMsg);
			main_window.draw(PlayerTwoMsg);
		}

		if (!the_game->get_game_state())
		{
			//STATE_TRACE("Game Over, drawing game over message");
			main_window.draw(gameOverMessage);
			
		}
		if (!is_playing)
		{
			//STATE_TRACE("Not playing, drawing main menu");
			menu.draw(main_window);
		}
		main_window.display();
	}

	return EXIT_SUCCESS;
}


