#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>

#include "FlappyBird.hpp"
#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class Pipes
    {
    public:
        Pipes(GameDataPtr gameData);
        ~Pipes();

        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void MovePipes(float deltaTime);
        void RandomPipesOffset();
        void DrawPipes();

        const std::vector<sf::Sprite> &GetSpritePipesVec() const;

    private:
        GameDataPtr _gameData;
        std::vector<sf::Sprite> _pipeSpritesVec;

        int _landHeight;
        int _pipeSpawnYOffset;
    };
}