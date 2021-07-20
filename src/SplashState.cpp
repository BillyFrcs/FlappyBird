#include <iostream>
#include <sstream>

#include "FlappyBird.hpp"
#include "MainMenuState.hpp"
#include "SplashState.hpp"

BillyEngine::SplashState::SplashState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::SplashState::~SplashState()
{
}

void BillyEngine::SplashState::Init()
{
     _gameData->assets.loadTexture("Splash State Background", MAIN_MENU_BACKGROUND_PATH);

     // This method is use for showing the splash background
     _background.setTexture(this->_gameData->assets.getTexture("Splash State Background"));
}

void BillyEngine::SplashState::HandleInput()
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

void BillyEngine::SplashState::Update(float deltaType)
{
     /* Didn't using this splash screen for now.
     if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_TIME)
     {
          // Switch to main menu
          std::cout << "Go To Main Menu\n";
     }
     */
     _gameData->machine.addState(StatePtr(new MainMenuState(_gameData)), true);
}

void BillyEngine::SplashState::Draw(float deltaType)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);

     _gameData->window.display();
}
