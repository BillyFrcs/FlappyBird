#include <iostream>

#include "FlappyBird.hpp"
#include "Pipe.hpp"

#define Y_POSITION 0
#define COUNT_RAND 1

BillyEngine::Pipe::Pipe(GameDataPtr gameData) : _gameData(gameData)
{
     _landHeight = _gameData->assets.GetTexture("Land Game").getSize().y;

     _pipeSpawnYOffset = Y_POSITION;
}

BillyEngine::Pipe::~Pipe()
{
}

void BillyEngine::Pipe::SpawnBottomPipe()
{
     sf::Sprite spriteBottom(_gameData->assets.GetTexture("Pipe Up"));

     spriteBottom.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - spriteBottom.getLocalBounds().height - _pipeSpawnYOffset);

     _pipeSpritesVec.push_back(spriteBottom);
}

void BillyEngine::Pipe::SpawnTopPipe()
{
     sf::Sprite spriteDown(_gameData->assets.GetTexture("Pipe Down"));

     spriteDown.setPosition(_gameData->window.getSize().x, -_pipeSpawnYOffset);

     _pipeSpritesVec.push_back(spriteDown);
}

void BillyEngine::Pipe::SpawnInvisiblePipe()
{
     sf::Sprite spriteInvisible(_gameData->assets.GetTexture("Pipe Down"));

     spriteInvisible.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - spriteInvisible.getLocalBounds().height);

     // Set the invisible color of pipe
     spriteInvisible.setColor(sf::Color(0, 0, 0, 0));

     _pipeSpritesVec.push_back(spriteInvisible);
}

void BillyEngine::Pipe::MovePipes(float deltaTime)
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

void BillyEngine::Pipe::RandomPipesOffset()
{
     _pipeSpawnYOffset = std::rand() % (_landHeight + COUNT_RAND);
}

// Draw the pipes method
void BillyEngine::Pipe::DrawPipes()
{
     for (unsigned int i = 0; i < _pipeSpritesVec.size(); i++)
     {
          _gameData->window.draw(_pipeSpritesVec.at(i));
     }
}