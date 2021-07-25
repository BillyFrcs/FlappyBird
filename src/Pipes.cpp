#include <iostream>

#include "FlappyBird.hpp"
#include "Pipes.hpp"

#define Y_POSITION 0
#define COUNT_RAND 5 // Default 1

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

     _pipeSpritesVec.push_back(spriteBottom);
}

void BillyEngine::Pipes::SpawnTopPipe()
{
     sf::Sprite spriteDown(_gameData->assets.GetTexture("Pipe Down"));

     spriteDown.setPosition(_gameData->window.getSize().x, -_pipeSpawnYOffset);

     _pipeSpritesVec.push_back(spriteDown);
}

void BillyEngine::Pipes::SpawnInvisiblePipe()
{
     sf::Sprite spriteInvisible(_gameData->assets.GetTexture("Pipe Down"));

     spriteInvisible.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - spriteInvisible.getLocalBounds().height);

     // Set the invisible color of pipe
     spriteInvisible.setColor(sf::Color(0, 0, 0, 0));

     _pipeSpritesVec.push_back(spriteInvisible);
}

void BillyEngine::Pipes::MovePipes(float deltaTime)
{
     for (unsigned short int i = 0; i < _pipeSpritesVec.size(); i++)
     {
          if (_pipeSpritesVec.at(i).getPosition().x < Y_POSITION - _pipeSpritesVec.at(i).getGlobalBounds().width)
          {
               _pipeSpritesVec.erase(_pipeSpritesVec.begin() + i);
          }
          else
          {
               // sf::Vector2f position = _pipeSprites.at(i).getPosition();

               float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

               _pipeSpritesVec.at(i).move(-movement, Y_POSITION);
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
     for (unsigned int i = 0; i < _pipeSpritesVec.size(); i++)
     {
          _gameData->window.draw(_pipeSpritesVec.at(i));
     }
}

const std::vector<sf::Sprite> &BillyEngine::Pipes::GetSpritePipesVec() const
{
     return _pipeSpritesVec;
}