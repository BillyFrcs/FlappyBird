#include <cstdlib>
#include <ctime>

#include "Game.hpp"
#include "SplashState.hpp"

// Game data
BillyEngine::GameData::GameData()
{
}

BillyEngine::GameData::~GameData()
{
}

// Game loop
BillyEngine::Game::Game(const int width, const int height, const std::string title)
{
     std::srand((unsigned int)time(NULL));
     //std::srand(time(NULL));

     _gameData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
     _gameData->machine.AddState(StatePtr(new SplashState(this->_gameData)));

     this->RunGame();
}

BillyEngine::Game::~Game()
{
}

void BillyEngine::Game::RunGame()
{
     float newTime, frameTime, interpolation;

     float currentTime = this->_clock.getElapsedTime().asSeconds();

     float accumulator = 0.0f;

     while (this->_gameData->window.isOpen())
     {
          this->_gameData->machine.ProcessStateChanges();

          newTime = this->_clock.getElapsedTime().asSeconds();

          frameTime = (newTime - currentTime);

          if (frameTime > 0.25f)
          {
               frameTime = 0.25f;
          }

          currentTime = newTime;
          accumulator += frameTime;

          while (accumulator >= _deltaTime)
          {
               this->_gameData->machine.GetActiveState()->HandleInput();
               this->_gameData->machine.GetActiveState()->Update(_deltaTime);

               accumulator -= _deltaTime;
          }

          interpolation = (accumulator / _deltaTime);
          this->_gameData->machine.GetActiveState()->Draw(interpolation);
     }
}