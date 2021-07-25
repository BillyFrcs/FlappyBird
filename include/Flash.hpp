#pragma once

#include <SFML/Graphics.hpp>

#include "FlappyBird.hpp"
#include "Game.hpp"

namespace BillyEngine
{
    // Flash white
    class Flash
    {
    public:
        Flash(GameDataPtr _gameData);
        ~Flash();

        void ShowFlash(float deltaTime);
        void DrawFlash();

    private:
        GameDataPtr _gameData;

        sf::RectangleShape _shape;

        bool _isFlashOn;
    };
}