#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>

#include "FlappyBird.hpp"
#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class Pipe
    {
    public:
        Pipe(GameDataPtr gameData);
        ~Pipe();

        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void MovePipes(float deltaTime);
        void DrawPipes();

    private:
        GameDataPtr _gameData;
        std::vector<sf::Sprite> _pipeSpritesVec;
    };
}