#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>

#include <string>

#include "Game.hpp"

namespace BillyEngine
{
    class ScoreGame
    {
    public:
        ScoreGame(GameDataPtr gameDate);
        ~ScoreGame();

        void UpdateScore(int scoreParam);
        void DrawScore();

    private:
        GameDataPtr _gameData;

        sf::Text _scoreText;
    };
}