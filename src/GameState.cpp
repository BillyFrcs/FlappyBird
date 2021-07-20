#include "GameState.hpp"
#include "FlappyBird.hpp"
#include "MainMenuState.hpp"

BillyEngine::GameState::GameState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::GameState::~GameState()
{
}

void BillyEngine::GameState::Init()
{
     _gameData->assets.loadTexture("Game Background", GAME_BACKGROUND_PATH);
     _background.setTexture(this->_gameData->assets.getTexture("Game Background"));
}

void BillyEngine::GameState::HandleInput()
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

void BillyEngine::GameState::Update(float deltaTime)
{
}

void BillyEngine::GameState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);

     _gameData->window.display();
}