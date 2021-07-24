#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>

#include "Game.hpp"

namespace BillyEngine
{
    class Land
    {
    public:
        Land(GameDataPtr gameData);
        ~Land();

        void MoveLand(float deltaTime);
        void DrawLand();

        const std::vector<sf::Sprite> &GetSpriteLandVec() const;

    private:
        GameDataPtr _gameData;
        std::vector<sf::Sprite> _landSpriteVec;
    };
}