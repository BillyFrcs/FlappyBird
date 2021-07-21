#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"
#include "Pipe.hpp"
#include "State.hpp"

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

        sf::Sprite _background;

        Pipe *_pipePtr;
    };
}