#pragma once

#ifndef COLLISION_HPP
#define COLLISION_HPP

	#include <SFML/Graphics.hpp>
	#include <SFML/Graphics/Sprite.hpp>

namespace BillyEngine
{
class Collision
{
public:
	Collision();
	~Collision();

	bool IsCheckSpriteCollision(sf::Sprite spriteCollision1, float scaleCollision1, sf::Sprite spriteCollision2, float scaleCollision2);
};
}

#endif // COLLISION_HPP