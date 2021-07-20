#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataPtr gameData);
        ~SplashState();

        void Init();
        void HandleInput();
        void Update(float deltaType);
        void Draw(float deltaType);

    private:
        GameDataPtr _gameData;

        sf::Clock _clock;
        sf::Sprite _background;
    };
}