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
     // Load textures
     _gameData->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_GAME_PATH);
     _gameData->assets.LoadTexture("Title Game", GAME_TITLE_PATH);
     _gameData->assets.LoadTexture("Play Button Game", PLAY_BUTTON_GAME_FILEPATH);

     // Load sound
     if (!_startGameSoundBuffer.loadFromFile(START_GAME_SOUND_FIlEPATH))
     {
          std::cout << "Error loading start sound file" << std::endl;
     }

     _startGameSound.setBuffer(_startGameSoundBuffer);

     // _gameData->assets.LoadSound("Start Game Sound", START_GAME_SOUND_FIlEPATH);

     _background.setTexture(this->_gameData->assets.GetTexture("Main Menu Background"));
     _title.setTexture(this->_gameData->assets.GetTexture("Title Game"));
     _playButton.setTexture(this->_gameData->assets.GetTexture("Play Button Game"));

     // Set sound buffer
     // _startGameSound.setBuffer(this->_gameData->assets.GetSoundBuffer("Start Game Sound"));

     // Set position main menu x and y
     _title.setPosition((E_Screen_Width / 2) - (_title.getLocalBounds().width / 2), _title.getLocalBounds().height / 2);
     _playButton.setPosition((E_Screen_Width / 2) - (_playButton.getLocalBounds().width / 2), (E_Screen_Height / 2) - (_playButton.getLocalBounds().height / 2));
}

void BillyEngine::MainMenuState::HandleInput()
{
     sf::Event event;

     while (this->_gameData->window.pollEvent(event))
     {
          if (sf::Event::Closed == event.type)
          {
               this->_gameData->window.close();
          }

          if (this->_gameData->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_gameData->window))
          {
               this->_gameData->machine.AddState(StatePtr(new GameState(this->_gameData)));

               _startGameSound.play(); // Play the sound
               // std::cout << "Go To Game Screen \n";
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