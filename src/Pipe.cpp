#include "Pipe.hpp"
#include "FlappyBird.hpp"

//#define Y 0

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

     _pipeSprites.push_back(sprite);
}

void BillyEngine::Pipe::SpawnTopPipe()
{
     sf::Sprite sprite(_gameData->assets.GetTexture("Pipe Down"));

     sprite.setPosition(_gameData->window.getSize().x, 0);

     _pipeSprites.push_back(sprite);
}

void BillyEngine::Pipe::SpawnInvisiblePipe()
{
     sf::Sprite sprite(_gameData->assets.GetTexture("Pipe Down"));

     sprite.setPosition(_gameData->window.getSize().x, _gameData->window.getSize().y - sprite.getLocalBounds().height);

     // Set the invisible color of pipe
     sprite.setColor(sf::Color(0, 0, 0, 0));

     _pipeSprites.push_back(sprite);
}

void BillyEngine::Pipe::MovePipes(float deltaTime)
{
     for (unsigned short int i = 0; i < _pipeSprites.size(); i++)
     {
          sf::Vector2f position = _pipeSprites.at(i).getPosition();

          float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

          _pipeSprites.at(i).move(-movement, 0);
     }
}

// Draw the pipes method
void BillyEngine::Pipe::DrawPipes()
{
     for (unsigned short int i = 0; i < _pipeSprites.size(); i++)
     {
          _gameData->window.draw(_pipeSprites.at(i));
     }
}