#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataPtr gameData);
        ~GameOverState();

        void Init();
        void HandleInput();
        void Update(float deltaTime);
        void Draw(float deltaTime);

    private:
        GameDataPtr _gameData;

        sf::Sprite _background;
    };
}