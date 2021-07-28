#pragma once

#include <SFML/Graphics.hpp>

#include "FlappyBird.hpp"
#include "Game.hpp"

namespace BillyEngine
{
    // Flash white
    class FlashScreen
    {
    public:
        FlashScreen(GameDataPtr _gameData);
        ~FlashScreen();

        void ShowFlash(float deltaTime);
        void DrawFlash();

    private:
        GameDataPtr _gameData;

        sf::RectangleShape _shape;

        bool _isFlashOn;
    };
}