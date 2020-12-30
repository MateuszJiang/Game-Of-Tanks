#pragma once
#include "pch.h"

#include "../include/game.h"
#include "../include/menu.h"
#include "../include/menu_elements.h"

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
	{
		STATE_CORE_ERROR("Reading of the font failed");
		return EXIT_FAILURE;
	}

	// Initialize the pause message
	sf::Text pauseMessage = GameMenu::GetPauseMessage(font);
	sf::Text mainMessage = GameMenu::GetMainMessage(font);
	sf::Text gameOverMessage = GameMenu::GetGameOverMessage(font);
	sf::Text PlayerOneMsg = GameMenu::GetPlayerOneMsg(font);
	sf::Text PlayerTwoMsg = GameMenu::GetPlayerTwoMsg(font);

	GameElements *the_game;
	the_game = new GameElements();  // initialization so the compiler does not cry
	PLAYERS number_of_players;

	bool is_playing = false;
	// The loop in which the game is happening
	while (main_window.isOpen())
	{
		sf::Event event;
		while (main_window.pollEvent(event) && (!the_game->is_the_game_currently_in_progress()))
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
						STATE_TRACE("Menu Entered!");
					case 0:
						STATE_TRACE("Menu 2 players option chosen!");
						delete the_game;
						number_of_players = TWO_PLAYERS;
						// creating everything the game consists of
						the_game = new GameElements(main_window, PLAYERS(number_of_players));
						// (re)start the game
						GameMenu::restart_game_elements(the_game, is_playing);
						break;
					case 1:
						delete the_game;
						number_of_players = THREE_PLAYERS;
						// creating everything the game consists of
						the_game = new GameElements(main_window, PLAYERS(number_of_players));
						// (re)start the game
						GameMenu::restart_game_elements(the_game, is_playing);
						break;
					case 2:
						delete the_game;
						number_of_players = FOUR_PLAYERS;
						// creating everything the game consists of
						the_game = new GameElements(main_window, PLAYERS(number_of_players));
						// (re)start the game
						GameMenu::restart_game_elements(the_game, is_playing);
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

		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::LControl:
				STATE_CORE_INFO("LControl clicked");
				if (the_game->is_the_game_currently_in_progress())
				{
					STATE_CORE_INFO("LControl used, game into pause/unpause switch");
					switch (is_playing)
					{
					case true:
						STATE_CORE_TRACE("pause/unpause switch result: game paused");
						is_playing = false;
						break;
					case false:
						STATE_CORE_TRACE("pause/unpause switch result: game unpaused");
						is_playing = true;
						break;
					default:
						STATE_WARN("switch (is_playing) went to default for some reason");
						break;
					}
				}
				break;
			case sf::Keyboard::Escape:
				STATE_TRACE("Game Stopped (Esc)");
				the_game->game_turn_off();
				is_playing = false;
				break;
			default:
				break;
			}
		default:
			break;
		}


		main_window.clear(sf::Color::Black);

		if (is_playing && the_game->is_the_game_currently_in_progress())
		{
			STATE_TRACE("Game On, drawing elements");
			the_game->draw_map();
			the_game->draw_tanks();
			the_game->draw_rounds();
			
		}
		if (!is_playing && the_game->is_the_game_currently_in_progress())
		{
			STATE_TRACE("Game Paused, drawing Pause message");
			main_window.draw(pauseMessage);
			main_window.draw(PlayerOneMsg);
			main_window.draw(PlayerTwoMsg);
		}

		if (!the_game->is_the_game_currently_in_progress() && is_playing)
		{
			STATE_TRACE("Game Over, drawing game over message");
			main_window.draw(gameOverMessage);
		}
		if (!is_playing  && !the_game->is_the_game_currently_in_progress())
		{
			STATE_TRACE("Not playing, drawing main menu");
			menu.draw(main_window);
			main_window.draw(mainMessage);
		}
		main_window.display();
	}

	return EXIT_SUCCESS;
}


