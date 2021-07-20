#include "GameOverState.hpp"
#include "FlappyBird.hpp"
#include "MainMenuState.hpp"

BillyEngine::GameOverState::GameOverState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::GameOverState::~GameOverState()
{
}

void BillyEngine::GameOverState::Init()
{
     _gameData->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_PATH);
     _background.setTexture(this->_gameData->assets.getTexture("Game Over Background"));
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
     }
}

void BillyEngine::GameOverState::Update(float deltaTime)
{
}

void BillyEngine::GameOverState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);

     _gameData->window.display();
}
