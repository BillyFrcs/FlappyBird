#include "FlashScreen.hpp"

BillyEngine::FlashScreen::FlashScreen(GameDataPtr gameData) : _gameData(gameData)
{
     _shape = sf::RectangleShape(sf::Vector2f(_gameData->window.getSize()));
     _shape.setFillColor(sf::Color(255, 255, 255, 0));

     _isFlashOn = true;
}

BillyEngine::FlashScreen::~FlashScreen()
{
}

void BillyEngine::FlashScreen::ShowFlash(float deltaTime)
{
     if (_isFlashOn)
     {
          int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * deltaTime);

          if (alpha >= 255.0f)
          {
               alpha = 255.0f;
               _isFlashOn = false;
          }

          _shape.setFillColor(sf::Color(255, 255, 255, alpha));
     }
     else
     {
          int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * deltaTime);

          if (alpha <= 0.0f)
          {
               alpha = 0.0f;
               _isFlashOn = false;
          }

          _shape.setFillColor(sf::Color(255, 255, 255, alpha));
     }
}

void BillyEngine::FlashScreen::DrawFlash()
{
     _gameData->window.draw(_shape);
}