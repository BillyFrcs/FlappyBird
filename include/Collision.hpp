#pragma once

#ifndef COLLISION_HANDLING

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace BillyEngine
{
    class Collision
    {
    public:
        Collision();
        ~Collision();

        // Didn't using this collision at the moment
        // bool IsCheckSpriteCollision(sf::Sprite spriteParam1, sf::Sprite spriteParam2);

        bool IsCheckSpriteCollision(sf::Sprite spriteCollision1, float scaleCollision1, sf::Sprite spriteCollision2, float scaleCollision2);
    };
}

#endif