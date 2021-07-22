#include "Land.hpp"
#include "FlappyBird.hpp"

#define X_POSITION 0
#define Y_POSITION 0
#define Y_OFFSET 0.0f

BillyEngine::Land::Land(GameDataPtr gameData) : _gameData(gameData)
{
     sf::Sprite firstSprite(_gameData->assets.GetTexture("Land Game"));
     sf::Sprite secondSprite(_gameData->assets.GetTexture("Land Game"));

     firstSprite.setPosition(X_POSITION, _gameData->window.getSize().y - firstSprite.getGlobalBounds().height);
     secondSprite.setPosition(firstSprite.getGlobalBounds().width, _gameData->window.getSize().y - firstSprite.getGlobalBounds().height);

     _landSpritesVec.push_back(firstSprite);
     _landSpritesVec.push_back(secondSprite);
}

BillyEngine::Land::~Land()
{
}

void BillyEngine::Land::MoveLand(float deltaTime)
{
     for (unsigned short int i = 0; i < _landSpritesVec.size(); i++)
     {
          // To calculate the framerate game
          float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

          _landSpritesVec.at(i).move(-movement, Y_OFFSET);

          if (_landSpritesVec.at(i).getPosition().x < Y_POSITION - _landSpritesVec.at(i).getGlobalBounds().width)
          {
               sf::Vector2f position(_gameData->window.getSize().x, _landSpritesVec.at(i).getPosition().y);

               _landSpritesVec.at(i).setPosition(position);
          }
     }
}

void BillyEngine::Land::DrawLand()
{
     for (unsigned short int i = 0; i < _landSpritesVec.size(); i++)
     {
          _gameData->window.draw(_landSpritesVec.at(i));
     }
}