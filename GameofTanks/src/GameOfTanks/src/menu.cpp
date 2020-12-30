#pragma once
#include "pch.h"

#include "../include/menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("used/fonts/ComicSans.ttf"))
	{
		STATE_CORE_ERROR("Reading of the font failed");
		exit(2);
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("2 Players");
	menu[0].setPosition(MESSAGE_2_PLAYERS);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("3 Players");
	menu[1].setPosition(MESSAGE_3_PLAYERS);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("4 Players");
	menu[2].setPosition(MESSAGE_4_PLAYERS);

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(MESSAGE_EXIT);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		STATE_INFO("Menu Move Up");
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		STATE_INFO("Menu Move Down");
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}