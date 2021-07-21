#include <iostream>
#include <sstream>

#include "FlappyBird.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

BillyEngine::MainMenuState::MainMenuState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::MainMenuState::~MainMenuState()
{
}

void BillyEngine::MainMenuState::Init()
{
     _gameData->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_GAME_PATH);
     _gameData->assets.LoadTexture("Title Game", GAME_TITLE_PATH);
     _gameData->assets.LoadTexture("Play Button Game", PLAY_BUTTON_GAME_PATH);

     _background.setTexture(this->_gameData->assets.GetTexture("Main Menu Background"));
     _title.setTexture(this->_gameData->assets.GetTexture("Title Game"));
     _playButton.setTexture(this->_gameData->assets.GetTexture("Play Button Game"));

     // Set position menu x and y
     _title.setPosition((SCREEN_WIDTH / 2) - (_title.getLocalBounds().width / 2), _title.getLocalBounds().height / 2);
     _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getLocalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getLocalBounds().height / 2));
}

void BillyEngine::MainMenuState::HandleInput()
{
     sf::Event event;

     while (_gameData->window.pollEvent(event))
     {
          if (sf::Event::Closed == event.type)
          {
               _gameData->window.close();
          }

          if (_gameData->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _gameData->window))
          {
               _gameData->machine.AddState(StatePtr(new GameState(this->_gameData)));

               // std::cout << "Go To Game Screen\n";
          }
     }
}

void BillyEngine::MainMenuState::Update(float deltaTime)
{
}

void BillyEngine::MainMenuState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);
     _gameData->window.draw(_title);
     _gameData->window.draw(_playButton);

     _gameData->window.display();
}