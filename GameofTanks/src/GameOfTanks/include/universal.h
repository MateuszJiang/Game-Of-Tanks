#pragma once
#include "pch.h"


#ifndef UNIVERSAL
#define UNIVERSAL

#define WINDOW_WIDTH 3000
#define WINDOW_HEIGHT 2000

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
