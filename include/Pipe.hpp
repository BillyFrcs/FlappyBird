#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class Pipe
    {
    public:
        Pipe(GameDataPtr gameData);
        ~Pipe();

        void DrawPipes();

    private:
        GameDataPtr _gameData;
        std::vector<sf::Sprite> _pipeSprites;
    };
}