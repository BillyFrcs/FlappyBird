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
        void Update(float deltaTime);
        void TapBird();

        const sf::Sprite &GetSpriteBird() const;

    private:
        GameDataPtr _gameData;

        sf::Sprite _birdSprite;
        sf::Clock _clockBird;
        sf::Clock _movementClockBird;

        std::vector<sf::Texture> _birdAnimationFrames;

        unsigned int _birdAnimationIterator;
        int _birdState;
        float _birdRotation;
    };
}