#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "Game.hpp"
#include "Land.hpp"
#include "Pipes.hpp"
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

        Pipes *_pipePtr;
        Land *_landPtr;
        Bird *_birdPtr;
        Flash *_flashPtr;

        Collision _collision;

        sf::Sprite _background;
        sf::Clock _clock;

        int _gameState;
        int _scoreGame;
    };
}