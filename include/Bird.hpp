#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "FlappyBird.hpp"
#include "Game.hpp"

namespace BillyEngine
{
    class Bird
    {
    public:
        Bird(GameDataPtr gameData);
        ~Bird();

        void DrawBird();

    private:
        GameDataPtr _gameData;

        sf::Sprite _birdSprite;
    };
}