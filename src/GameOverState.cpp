#include <fstream>
#include <iostream>
#include <string>

#include "FlappyBird.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#define CHARACTER_SIZE 30
#define MEDAL_X_CORDINATE 382
#define MEDAL_Y_CORDINATE 314

BillyEngine::GameOverState::GameOverState(GameDataPtr gameData, int scoreGame) : _gameData(gameData), _scoreGame(scoreGame)
{
}

BillyEngine::GameOverState::~GameOverState()
{
}

void BillyEngine::GameOverState::Init()
{
     // Saving the high score into .txt file
     std::ifstream readFileHighScore; // Read the file

     readFileHighScore.open("Your_HighScoreGame_FlappyBird.txt"); // Can set the file path or directory location to save it

     if (readFileHighScore.is_open())
     {
          while (!readFileHighScore.eof()) // End of file
          {
               readFileHighScore >> _highScoreGame;
          }
     }

     readFileHighScore.close();

     // Write the file
     std::ofstream writeFileHighScore("Your_HighScoreGame_FlappyBird.txt"); // Can set the file path or directory location to save it

     if (writeFileHighScore.is_open())
     {
          if (_scoreGame > _highScoreGame)
          {
               _highScoreGame = _scoreGame;
          }
          writeFileHighScore << _highScoreGame;
     }

     writeFileHighScore.close();

     // Load texture
     _gameData->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
     _gameData->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
     _gameData->assets.LoadTexture("Game Over", GAME_OVER_FILEPATH);
     _gameData->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
     _gameData->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
     _gameData->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
     _gameData->assets.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);

     // Load sound retry game
     //_gameData->assets.LoadSound("Sound Retry Game", RETRY_GAME_SOUND_FILEPATH);

     if (!_soundRetryGameBuffer.loadFromFile(RETRY_GAME_SOUND_FILEPATH))
     {
          std::cout << "Error loading sound game over \n";
     }

     _soundRetryGame.setBuffer(_soundRetryGameBuffer);

     // Set texture
     _background.setTexture(this->_gameData->assets.GetTexture("Game Over Background"));
     _gameOverTitle.setTexture(this->_gameData->assets.GetTexture("Game Over Title"));
     _gameOverContainer.setTexture(this->_gameData->assets.GetTexture("Game Over"));
     _retryButtonPlayGame.setTexture(this->_gameData->assets.GetTexture("Play Button Game"));

     // Set sound buffer retry game
     //_soundRetryGame.setBuffer(this->_gameData->assets.GetSoundBuffer("Sound Retry Game"));

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

     // Get the medal statement
     if (_scoreGame >= PLATINUM_MEDAL)
     {
          _medalsGame.setTexture(_gameData->assets.GetTexture("Platinum Medal"));
     }
     else if (_scoreGame >= GOLD_MEDAL)
     {
          _medalsGame.setTexture(_gameData->assets.GetTexture("Gold Medal"));
     }
     else if (_scoreGame >= SILVER_MEDAL)
     {
          _medalsGame.setTexture(_gameData->assets.GetTexture("Silver Medal"));
     }
     else
     {
          _medalsGame.setTexture(_gameData->assets.GetTexture("Bronze Medal"));
     }

     // Set medal position
     _medalsGame.setPosition(_gameData->window.getSize().x - MEDAL_X_CORDINATE, MEDAL_Y_CORDINATE);
}

void BillyEngine::GameOverState::HandleInput()
{
     sf::Event event;

     while (this->_gameData->window.pollEvent(event))
     {
          if (sf::Event::Closed == event.type)
          {
               this->_gameData->window.close();
          }

          if (this->_gameData->input.IsSpriteClicked(this->_retryButtonPlayGame, sf::Mouse::Left, this->_gameData->window))
          {
               this->_gameData->machine.AddState(StatePtr(new GameState(this->_gameData)), true);

               _soundRetryGame.play(); // Play the sound
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
     _gameData->window.draw(_medalsGame);

     _gameData->window.display();
}