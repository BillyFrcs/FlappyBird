#include <iostream>

#include "FlappyBird.hpp"
#include "Pipe.hpp"

#define Y_POSITION 0

BillyEngine::Pipe::Pipe(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::Pipe::~Pipe()
{
}

void BillyEngine::Pipe::SpawnBottomPipe()
{
     sf::Sprite sprite(_gameData->assets.GetTexture("Pipe Up"));

     sprite.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - sprite.getLocalBounds().height);

     _pipeSpritesVec.push_back(sprite);
}

void BillyEngine::Pipe::SpawnTopPipe()
{
     sf::Sprite sprite(_gameData->assets.GetTexture("Pipe Down"));

     sprite.setPosition(_gameData->window.getSize().x, Y_POSITION);

     _pipeSpritesVec.push_back(sprite);
}

void BillyEngine::Pipe::SpawnInvisiblePipe()
{
     sf::Sprite sprite(_gameData->assets.GetTexture("Pipe Down"));

     sprite.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - sprite.getLocalBounds().height);

     // Set the invisible color of pipe
     sprite.setColor(sf::Color(0, 0, 0, 0));

     _pipeSpritesVec.push_back(sprite);
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

// Draw the pipes method
void BillyEngine::Pipe::DrawPipes()
{
     for (unsigned short int i = 0; i < _pipeSpritesVec.size(); i++)
     {
          _gameData->window.draw(_pipeSpritesVec.at(i));
     }
}