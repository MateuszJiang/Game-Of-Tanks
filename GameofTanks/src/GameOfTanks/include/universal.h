#pragma once

#ifndef UNIVERSAL
#define UNIVERSAL

// RESOLUTION DEFINES WITH POSITIONS OF TEXT AND TEXTURES
// FOR NOW ONLY 2K MODE AVAILABLE
#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1440

#define MAIN_GAME_MESSAGE	sf::Vector2f((WINDOW_WIDTH / 2) - 700.f, WINDOW_HEIGHT / 2 - 300.f)
#define GAME_OVER_MESSAGE	sf::Vector2f(800.f, 800.f)

#define PLAYER_ONE_MESSAGE	sf::Vector2f(WINDOW_WIDTH - (WINDOW_WIDTH - 100.0f), WINDOW_HEIGHT - 300.0f)
#define PLAYER_TWO_MESSAGE	sf::Vector2f(WINDOW_WIDTH - 500.f, WINDOW_HEIGHT - 300.0f)

#define MESSAGE_2_PLAYERS	sf::Vector2f((WINDOW_WIDTH / 2) - 100.f, 800)
#define MESSAGE_3_PLAYERS	sf::Vector2f((WINDOW_WIDTH / 2) - 100.f, 900)
#define MESSAGE_4_PLAYERS	sf::Vector2f((WINDOW_WIDTH / 2) - 100.f, 1000)
#define MESSAGE_EXIT		sf::Vector2f((WINDOW_WIDTH / 2) - 100.f, 1100)

#define TANK_ONE_DEFAULT_POSITION sf::Vector2f(500.f, 500.f)
#define TANK_TWO_DEFAULT_POSITION sf::Vector2f(1800.f, 800.f)
#define TANK_THREE_DEFAULT_POSITION sf::Vector2f(500.f, 800.f)
#define TANK_FOUR_DEFAULT_POSITION sf::Vector2f(1800.f, 500.f)

enum TURN { LEFT, RIGHT };
enum MOVE { FORWARD, BACKWARD };

enum TANK { ONE, TWO, THREE, FOUR};
enum PLAYERS {TWO_PLAYERS, THREE_PLAYERS, FOUR_PLAYERS};

#define SPEED 2.f
#define ROUND 10.f

#define PI 3.14159
#define TANK_HEALTH 5
#define MAX_NUMBER_OF_ITEMS 4

#endif // !UNIVERSAL
