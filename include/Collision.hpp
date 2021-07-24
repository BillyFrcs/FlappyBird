#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace BillyEngine
{
    class Collision
    {
    public:
        Collision();
        ~Collision();

        bool IsCheckSpriteCollision(sf::Sprite spriteParam1, sf::Sprite spriteParam2);
    };
}