#include "Bird.hpp"

BillyEngine::Bird::Bird(GameDataPtr gameData) : _gameData(gameData)
{
     _birdSprite.setTexture(_gameData->assets.GetTexture("Bird Frame 1"));
}

BillyEngine::Bird::~Bird()
{
}

void BillyEngine::Bird::DrawBird()
{
     _gameData->window.draw(_birdSprite);
}