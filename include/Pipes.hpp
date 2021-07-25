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
        void SpawnScoringPipes();
        void MovePipes(float deltaTime);
        void RandomPipesOffset();
        void DrawPipes();

        const std::vector<sf::Sprite> &GetSpritePipesVec() const;
        std::vector<sf::Sprite> &GetScoringSpritePipesVec();

    private:
        GameDataPtr _gameData;
        std::vector<sf::Sprite> _pipesSpriteVec;
        std::vector<sf::Sprite> _scoringSpritePipesVec;

        int _landHeight;
        int _pipeSpawnYOffset;
    };
}