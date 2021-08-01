#pragma once

#ifndef GAME_OVER_STATE

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "AssetsManager.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "State.hpp"

namespace BillyEngine
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataPtr gameData, int scoreGame);
        ~GameOverState();

        void Init() override;
        void HandleInput() override;
        void Update(float deltaTime) override;
        void Draw(float deltaTime) override;

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

        sf::SoundBuffer _soundRetryGameBuffer;
        sf::Sound _soundRetryGame;
    };
}

#endif