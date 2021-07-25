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

        // Didn't using this collision at the moment
        // bool IsCheckSpriteCollision(sf::Sprite spriteParam1, sf::Sprite spriteParam2);

        bool IsCheckSpriteCollision(sf::Sprite spriteParam1, float scaleParam1, sf::Sprite spriteParam2, float scaleParam2);
    };
}