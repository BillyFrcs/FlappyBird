#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include <memory>
#include <string>

#include "AssetsManager.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

namespace BillyEngine
{
    //The game loop
    struct GameData
    {
        GameData();
        ~GameData();

        sf::RenderWindow window;

        StateMachine machine;
        InputManager input;
        AssetsManager assets;
    };

    typedef std::shared_ptr<GameData> GameDataPtr;

    class Game : public GameData
    {
    public:
        Game(int width, int height, std::string title);
        ~Game();

    private:
        // Update run 60 per second
        const float _deltaTime = (1.0f / 60.0f);
        sf::Clock _clock;
        GameDataPtr _gameData = std::make_shared<GameData>();

        // Method to run Flappy Bird game
        void RunGame();
    };
}