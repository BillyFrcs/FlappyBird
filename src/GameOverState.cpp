#include <fstream>
#include <iostream>
#include <string>

#include "FlappyBird.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#define CHARACTER_SIZE 55

BillyEngine::GameOverState::GameOverState(GameDataPtr gameData, int scoreParam) : _gameData(gameData), _scoreGame(scoreParam)
{
}

BillyEngine::GameOverState::~GameOverState()
{
}

void BillyEngine::GameOverState::Init()
{
     // Saving the high score into .txt file
     std::ifstream readFileHighScore; // Read the file

     readFileHighScore.open("Your_HighScoreGame.txt"); // Can set the file path or directory location to save it

     if (readFileHighScore.is_open())
     {
          while (!readFileHighScore.eof()) // End of file
          {
               readFileHighScore >> _highScoreGame;
          }
     }

     readFileHighScore.close();

     // Write the file
     std::ofstream writeFileHighScore("Your_HighScoreGame.txt"); // Can set the file path or directory location to save it

     if (writeFileHighScore.is_open())
     {
          if (_scoreGame > _highScoreGame)
          {
               _highScoreGame = _scoreGame;
          }

          writeFileHighScore << _highScoreGame;
     }

     writeFileHighScore.close();

     _gameData->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
     _gameData->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
     _gameData->assets.LoadTexture("Game Over", GAME_OVER_FILEPATH);

     _background.setTexture(this->_gameData->assets.GetTexture("Game Over Background"));
     _gameOverTitle.setTexture(this->_gameData->assets.GetTexture("Game Over Title"));
     _gameOverContainer.setTexture(this->_gameData->assets.GetTexture("Game Over"));
     _retryButtonPlayGame.setTexture(this->_gameData->assets.GetTexture("Play Button Game"));

     // Set position game over
     _gameOverContainer.setPosition((_gameData->window.getSize().x / 2 - _gameOverContainer.getGlobalBounds().width / 2), (_gameData->window.getSize().y / 2 - _gameOverContainer.getGlobalBounds().height / 2));
     _gameOverTitle.setPosition((_gameData->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2));
     _retryButtonPlayGame.setPosition((_gameData->window.getSize().x / 2) - (_retryButtonPlayGame.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButtonPlayGame.getGlobalBounds().height * 0.2));

     // Set style for score game text
     _scoreGameText.setFont(_gameData->assets.GetFont("Flappy Font"));
     _scoreGameText.setString(std::to_string(_scoreGame));
     _scoreGameText.setCharacterSize(CHARACTER_SIZE);
     _scoreGameText.setFillColor(sf::Color::White);
     _scoreGameText.setOrigin(_scoreGameText.getGlobalBounds().width / 2, _scoreGameText.getGlobalBounds().height / 2);
     _scoreGameText.setPosition(_gameData->window.getSize().x / 10 * 7.25, _gameData->window.getSize().y / 2.15);

     // Set style for high score game text
     _highScoreGameText.setFont(_gameData->assets.GetFont("Flappy Font"));
     _highScoreGameText.setString(std::to_string(_highScoreGame));
     _highScoreGameText.setCharacterSize(CHARACTER_SIZE);
     _highScoreGameText.setFillColor(sf::Color::White);
     _highScoreGameText.setOrigin(_highScoreGameText.getGlobalBounds().width / 2, _highScoreGameText.getGlobalBounds().height / 2);
     _highScoreGameText.setPosition(_gameData->window.getSize().x / 10 * 7.25, _gameData->window.getSize().y / 1.78);
}

void BillyEngine::GameOverState::HandleInput()
{
     sf::Event event;

     while (_gameData->window.pollEvent(event))
     {
          if (sf::Event::Closed == event.type)
          {
               _gameData->window.close();
          }

          if (_gameData->input.IsSpriteClicked(_retryButtonPlayGame, sf::Mouse::Left, _gameData->window))
          {
               _gameData->machine.AddState(StatePtr(new GameState(_gameData)), true);
          }
     }
}

void BillyEngine::GameOverState::Update(float deltaTime)
{
}

void BillyEngine::GameOverState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);
     _gameData->window.draw(_gameOverTitle);
     _gameData->window.draw(_gameOverContainer);
     _gameData->window.draw(_retryButtonPlayGame);
     _gameData->window.draw(_scoreGameText);
     _gameData->window.draw(_highScoreGameText);

     _gameData->window.display();
}