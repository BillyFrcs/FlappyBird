#include <iostream>

#include "FlappyBird.hpp"
#include "Pipes.hpp"

#define Y_POSITION 0 // Deafault 0
#define COUNT_RAND 1 // Default 1

BillyEngine::Pipes::Pipes(GameDataPtr gameData) : _gameData(gameData)
{
     _landHeight = _gameData->assets.GetTexture("Land Game").getSize().y;

     _pipeSpawnYOffset = Y_POSITION;
}

BillyEngine::Pipes::~Pipes()
{
}

void BillyEngine::Pipes::SpawnBottomPipe()
{
     sf::Sprite spriteBottom(_gameData->assets.GetTexture("Pipe Up"));

     spriteBottom.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - spriteBottom.getLocalBounds().height - _pipeSpawnYOffset);

     _pipesSpriteVec.push_back(spriteBottom);
}

void BillyEngine::Pipes::SpawnTopPipe()
{
     sf::Sprite spriteDown(_gameData->assets.GetTexture("Pipe Down"));

     spriteDown.setPosition(_gameData->window.getSize().x, -_pipeSpawnYOffset);

     _pipesSpriteVec.push_back(spriteDown);
}

void BillyEngine::Pipes::SpawnInvisiblePipe()
{
     sf::Sprite spriteInvisible(_gameData->assets.GetTexture("Pipe Down"));

     spriteInvisible.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - spriteInvisible.getLocalBounds().height);

     // Set the invisible color of pipe
     spriteInvisible.setColor(sf::Color(0, 0, 0, 0));

     _pipesSpriteVec.push_back(spriteInvisible);
}

void BillyEngine::Pipes::SpawnScoringPipes()
{
     sf::Sprite scoringSpritePipes(_gameData->assets.GetTexture("Scoring Pipe"));

     scoringSpritePipes.setPosition(_gameData->window.getSize().x, Y_POSITION);

     _scoringSpritePipesVec.push_back(scoringSpritePipes);
}

void BillyEngine::Pipes::MovePipes(float deltaTime)
{
     // Pipes sprite
     for (uint32_t i = 0; i < _pipesSpriteVec.size(); i++)
     {
          if (_pipesSpriteVec.at(i).getPosition().x < Y_POSITION - _pipesSpriteVec.at(i).getGlobalBounds().width)
          {
               _pipesSpriteVec.erase(_pipesSpriteVec.begin() + i);
          }
          else
          {
               // sf::Vector2f position = _pipeSprites.at(i).getPosition();

               float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

               _pipesSpriteVec.at(i).move(-movement, Y_POSITION);
          }
          //std::cout << _pipeSprites.size() << std::endl;
     }

     // Scoring sprite pipes
     for (uint32_t i = 0; i < _scoringSpritePipesVec.size(); i++)
     {
          if (_scoringSpritePipesVec.at(i).getPosition().x < Y_POSITION - _scoringSpritePipesVec.at(i).getGlobalBounds().width)
          {
               _scoringSpritePipesVec.erase(_scoringSpritePipesVec.begin() + i);
          }
          else
          {
               // sf::Vector2f position = _pipeSprites.at(i).getPosition();

               float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

               _scoringSpritePipesVec.at(i).move(-movement, Y_POSITION);
          }
          //std::cout << _pipeSprites.size() << std::endl;
     }
}

void BillyEngine::Pipes::RandomPipesOffset()
{
     _pipeSpawnYOffset = std::rand() % (_landHeight + COUNT_RAND);
}

// Draw the pipes method
void BillyEngine::Pipes::DrawPipes()
{
     // Get random pipes position
     for (uint32_t i = 0; i < _pipesSpriteVec.size(); i++)
     {
          _gameData->window.draw(_pipesSpriteVec.at(i));
     }
}

const std::vector<sf::Sprite> &BillyEngine::Pipes::GetSpritePipesVec() const
{
     return _pipesSpriteVec;
}

std::vector<sf::Sprite> &BillyEngine::Pipes::GetScoringSpritePipesVec()
{
     return _scoringSpritePipesVec;
}