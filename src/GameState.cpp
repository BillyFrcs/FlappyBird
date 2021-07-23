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
     _gameData->assets.LoadTexture("Game Background", GAME_BACKGROUND_PATH);

     _gameData->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
     _gameData->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

     _gameData->assets.LoadTexture("Land Game", LAND_FILEPATH);

     _gameData->assets.LoadTexture("Bird Frame 1", BIRD_FRAME1_FILEPATH);

     _pipePtr = new Pipe(_gameData); // Pipes
     _landPtr = new Land(_gameData); // Land
     _birdPtr = new Bird(_gameData); // Bird

     _background.setTexture(this->_gameData->assets.GetTexture("Game Background"));
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

          if (_gameData->input.IsSpriteClicked(_background, sf::Mouse::Left, _gameData->window))
          {
               /* Didn't using it at this moment
               _pipePtr->SpawnInvisiblePipe();
               _pipePtr->SpawnBottomPipe();
               _pipePtr->SpawnTopPipe();
               */
          }
     }
}

void BillyEngine::GameState::Update(float deltaTime)
{
     _pipePtr->MovePipes(deltaTime);
     _landPtr->MoveLand(deltaTime);

     if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
     {
          _pipePtr->RandomPipesOffset();
          _pipePtr->SpawnInvisiblePipe();
          _pipePtr->SpawnBottomPipe();
          _pipePtr->SpawnTopPipe();

          _clock.restart();
     }
}

void BillyEngine::GameState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);

     _pipePtr->DrawPipes(); // Draw the pipes up and down on the screen
     _landPtr->DrawLand();  // Draw the land on the screen
     _birdPtr->DrawBird();  // Draw bird

     _gameData->window.display();
}