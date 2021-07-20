#include "InputManager.hpp"

BillyEngine::InputManager::InputManager()
{
}

BillyEngine::InputManager::~InputManager()
{
}

bool BillyEngine::InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
     if (sf::Mouse::isButtonPressed(button))
     {
          sf::IntRect playButtonRectangle(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

          if (playButtonRectangle.contains(sf::Mouse::getPosition(window)))
          {
               return true;
          }
     }
     return false;
}

sf::Vector2i BillyEngine::InputManager::getMousePosition(sf::RenderWindow &window)
{
     return sf::Mouse::getPosition(window);
}
