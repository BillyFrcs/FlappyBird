#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Game.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataPtr gameData, int scoreParam);
        ~GameOverState();

        void Init();
        void HandleInput();
        void Update(float deltaTime);
        void Draw(float deltaTime);

    private:
        GameDataPtr _gameData;

        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer; // Body game over
        sf::Sprite _retryButtonPlayGame;
        sf::Sprite _medalsGame;

        sf::Text _scoreGameText;
        sf::Text _highScoreGameText;

        int _scoreGame;
        int _highScoreGame;
    };
}