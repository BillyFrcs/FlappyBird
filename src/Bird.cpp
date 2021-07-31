#include "Bird.hpp"

constexpr auto VALUE = 0;

BillyEngine::Bird::Bird(GameDataPtr gameData) : _gameData(gameData)
{
     _birdAnimationIterator = VALUE;

     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 1"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 2"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 3"));
     _birdAnimationFrames.push_back(_gameData->assets.GetTexture("Bird Frame 4"));

     // _birdSprite.setTexture(_gameData->assets.GetTexture("Bird Frame 1"));

     _birdSprite.setTexture(_birdAnimationFrames.at(_birdAnimationIterator));

     _birdSprite.setPosition((_gameData->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_gameData->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));

     _birdState = BIRD_STATE_STILL;

     sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);

     _birdSprite.setOrigin(origin);

     _birdRotation = VALUE;
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
     deltaTime = 1;

     if (_clockBird.getElapsedTime().asSeconds() > (BIRD_ANIMATION_FLYING_TIME / _birdAnimationFrames.size()))
     {
          if (_birdAnimationIterator < _birdAnimationFrames.size() - deltaTime)
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

void BillyEngine::Bird::Update(float deltaTime)
{
     if (BIRD_STATE_FALLING == _birdState)
     {
          _birdSprite.move(VALUE, BIRD_GRAVITY * deltaTime);

          _birdRotation += (BIRD_ROTATION_SPEED * deltaTime);

          if (_birdRotation > 25.0f)
          {
               _birdRotation = 25.0f;
          }

          _birdSprite.setRotation(_birdRotation);
     }

     else if (BIRD_STATE_FLYING == _birdState)
     {
          _birdSprite.move(VALUE, -BIRD_FLYING_SPEED * deltaTime);

          _birdRotation -= (BIRD_ROTATION_SPEED * deltaTime);

          if (_birdRotation < -25.f)
          {
               _birdRotation = -25.f;
          }

          _birdSprite.setRotation(_birdRotation);
     }

     if (_movementClockBird.getElapsedTime().asSeconds() > BIRD_FLYING_DURATION)
     {
          _movementClockBird.restart();

          _birdState = BIRD_STATE_FALLING;
     }
}

void BillyEngine::Bird::TapBird()
{
     _movementClockBird.restart();

     _birdState = BIRD_STATE_FLYING;
}

const sf::Sprite &BillyEngine::Bird::GetSpriteBird() const
{
     return _birdSprite;
}