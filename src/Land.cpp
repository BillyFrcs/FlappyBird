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

     _landSpriteVec.push_back(firstSprite);
     _landSpriteVec.push_back(secondSprite);
}

BillyEngine::Land::~Land()
{
}

void BillyEngine::Land::MoveLand(float deltaTime)
{
     for (unsigned int i = 0; i < _landSpriteVec.size(); i++)
     {
          // To calculate the framerate game
          float movement = (PIPE_MOVEMENT_SPEED * deltaTime);

          _landSpriteVec.at(i).move(-movement, Y_OFFSET);

          if (_landSpriteVec.at(i).getPosition().x < Y_POSITION - _landSpriteVec.at(i).getGlobalBounds().width)
          {
               sf::Vector2f position(_gameData->window.getSize().x, _landSpriteVec.at(i).getPosition().y);

               _landSpriteVec.at(i).setPosition(position);
          }
     }
}

void BillyEngine::Land::DrawLand()
{
     for (unsigned int i = 0; i < _landSpriteVec.size(); i++)
     {
          _gameData->window.draw(_landSpriteVec.at(i));
     }
}

const std::vector<sf::Sprite> &BillyEngine::Land::GetSpriteLandVec() const
{
     return _landSpriteVec;
}