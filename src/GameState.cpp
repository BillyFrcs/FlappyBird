#include "GameState.hpp"
#include "FlappyBird.hpp"
#include "MainMenuState.hpp"

#include <iostream>

/* Didn't using this definition 
#define SCALE_LAND1 0.7f
#define SCALE_LAND2 1.0f

#define SCALE_PIPE1 0.62f
#define SCALE_PIPE2 0.90f
*/

BillyEngine::GameState::GameState(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::GameState::~GameState()
{
}

void BillyEngine::GameState::Init()
{
     // Load background
     _gameData->assets.LoadTexture("Game Background", GAME_BACKGROUND_PATH);

     // Load pipes and invisible scoring
     _gameData->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
     _gameData->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
     _gameData->assets.LoadTexture("Scoring Pipe", INVISIBLE_SCORING_PIPE_FILEPATH);

     // Load land
     _gameData->assets.LoadTexture("Land Game", LAND_FILEPATH);

     // Load frames birds
     _gameData->assets.LoadTexture("Bird Frame 1", BIRD_FRAME1_FILEPATH);
     _gameData->assets.LoadTexture("Bird Frame 2", BIRD_FRAME2_FILEPATH);
     _gameData->assets.LoadTexture("Bird Frame 3", BIRD_FRAME3_FILEPATH);
     _gameData->assets.LoadTexture("Bird Frame 4", BIRD_FRAME4_FILEPATH);

     // Load fonts
     _gameData->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

     _pipePtr = new Pipes(_gameData);      // Pipes
     _landPtr = new Land(_gameData);       // Land
     _birdPtr = new Bird(_gameData);       // Bird frames
     _flashPtr = new Flash(_gameData);     // Flash
     _scorePtr = new ScoreGame(_gameData); // Score game

     _background.setTexture(this->_gameData->assets.GetTexture("Game Background"));

     _scoreGame = 0;
     _scorePtr->UpdateScore(_scoreGame);

     _gameState = GameStates::E_GameReady;
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
               /* Didn't using it at the moment
               _pipePtr->SpawnInvisiblePipe();
               _pipePtr->SpawnBottomPipe();
               _pipePtr->SpawnTopPipe();
               */

               if (GameStates::E_GameOver != _gameState)
               {
                    _gameState = GameStates::E_PlayingGame;
                    _birdPtr->TapBird();
               }
          }
     }
}

void BillyEngine::GameState::Update(float deltaTime)
{
     if (GameStates::E_GameOver != _gameState)
     {
          _birdPtr->BirdAnimation(deltaTime);
          _landPtr->MoveLand(deltaTime);
     }

     if (GameStates::E_PlayingGame == _gameState)
     {
          _pipePtr->MovePipes(deltaTime);

          if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
          {
               _pipePtr->RandomPipesOffset();
               _pipePtr->SpawnInvisiblePipe();
               _pipePtr->SpawnBottomPipe();
               _pipePtr->SpawnTopPipe();
               _pipePtr->SpawnScoringPipes();

               _clock.restart();
          }

          _birdPtr->Update(deltaTime);

          // Land sprite collision detected
          std::vector<sf::Sprite> landSpriteVec = _landPtr->GetSpriteLandVec();

          for (unsigned int i = 0; i < landSpriteVec.size(); i++)
          {
               if (_collision.IsCheckSpriteCollision(_birdPtr->GetSpriteBird(), 0.7f, landSpriteVec.at(i), 1.0f))
               {
                    _gameState = GameStates::E_GameOver;
               }
          }

          // Pipes sprite collision detected
          std::vector<sf::Sprite> pipeSpriteVec = _pipePtr->GetSpritePipesVec();

          for (unsigned int i = 0; i < pipeSpriteVec.size(); i++)
          {
               if (_collision.IsCheckSpriteCollision(_birdPtr->GetSpriteBird(), 0.625f, pipeSpriteVec.at(i), 1.0f))
               {
                    _gameState = GameStates::E_GameOver;
               }
          }

          if (GameStates::E_PlayingGame == _gameState)
          {
               // Pipe invisible sprite collision detection
               std::vector<sf::Sprite> &pipeScoringSpriteVec = _pipePtr->GetScoringSpritePipesVec();

               for (unsigned int i = 0; i < pipeScoringSpriteVec.size(); i++)
               {
                    if (_collision.IsCheckSpriteCollision(_birdPtr->GetSpriteBird(), 0.600f, pipeScoringSpriteVec.at(i), 1.0f))
                    {
                         _scoreGame++;
                         _scorePtr->UpdateScore(_scoreGame); // Update the score

                         // Check if the score is count or not in the console
                         //std::cout << _scoreGame << std::endl;

                         pipeScoringSpriteVec.erase(pipeScoringSpriteVec.begin() + i);
                    }
               }
          }
     }

     if (GameStates::E_GameOver == _gameState)
     {
          _flashPtr->ShowFlash(deltaTime);
     }
}

void BillyEngine::GameState::Draw(float deltaTime)
{
     _gameData->window.clear();

     _gameData->window.draw(_background);

     _pipePtr->DrawPipes();  // Draw the pipes up and down on the screen
     _landPtr->DrawLand();   // Draw the land on the screen
     _birdPtr->DrawBird();   // Draw bird
     _flashPtr->DrawFlash(); // Draw the flash
     _scorePtr->DrawScore(); // Draw the score

     _gameData->window.display();
}