#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include <vector>

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
        void BirdAnimation(float deltaTime);

    private:
        GameDataPtr _gameData;

        sf::Sprite _birdSprite;
        sf::Clock _clockBird;
        std::vector<sf::Texture> _birdAnimationFrames;

        unsigned int _birdAnimationIterator;
    };
}