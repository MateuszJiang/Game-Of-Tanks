#pragma once
#include <SFML/Graphics.hpp>

#include "universal.h"

#ifndef MAP_H_
#define MAP_H_

class Map
{
private:
	sf::Texture map_texture;
	sf::Sprite map_sprite;
public:
	Map()
	{
		// make sand texture
		if (!map_texture.loadFromFile("used/maps/beach_text.jpg"))
		{
			exit(2);
		}
		map_texture.setSmooth(true);
		map_sprite.setTexture(map_texture);
		map_sprite.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

	}
	Map(const Map *other): map_sprite(other->map_sprite), map_texture(other->map_texture) {}   // copy constructor

	sf::Sprite &get_map() { return map_sprite; }  // map getter
};



#endif // !MAP_H_
