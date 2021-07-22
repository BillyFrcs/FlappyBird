#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include "Game.hpp"
#include "Pipe.hpp"
#include "State.hpp"
#include "Land.hpp"

namespace BillyEngine
{
    class GameState : public State
    {
    public:
        GameState(GameDataPtr gameData);
        ~GameState();

        void Init();
        void HandleInput();
        void Update(float deltaTime);
        void Draw(float deltaTime);

    private:
        GameDataPtr _gameData;

        Pipe *_pipePtr;
        Land *_landPtr;

        sf::Sprite _background;
        sf::Clock _clock;
    };
}