#include "Bird.hpp"

#define VALUE 0

BillyEngine::Bird::Bird(GameDataPtr gameData) : _gameData(gameData)
{
     _birdAnimationIterator = VALUE;

     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 1"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 2"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 3"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 4"));

     //_birdSprite.setTexture(_gameData->assets.GetTexture("Bird Frame 1"));

     _birdSprite.setTexture(_birdAnimationFrames.at(_birdAnimationIterator));
}

BillyEngine::Bird::~Bird()
{
}

void BillyEngine::Bird::DrawBird()
{
     _gameData->window.draw(_birdSprite);
}

void BillyEngine::Bird::BirdAnimation(float deltaTime)
{
     if (_clockBird.getElapsedTime().asSeconds() > BIRD_ANIMATION_FLYING_TIME / _birdAnimationFrames.size())
     {
          if (_birdAnimationIterator < _birdAnimationFrames.size() - 1)
          {
               _birdAnimationIterator++;
          }
          else
          {
               _birdAnimationIterator = VALUE;
          }

          _birdSprite.setTexture(_birdAnimationFrames.at(_birdAnimationIterator));

          _clockBird.restart();
     }
}