#include "GameOverState.hpp"
#include "FlappyBird.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

BillyEngine::GameOverState::GameOverState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::GameOverState::~GameOverState()
{
}

void BillyEngine::GameOverState::Init()
{
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

     _gameData->window.display();
}