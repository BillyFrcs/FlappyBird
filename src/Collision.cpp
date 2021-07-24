#include "Collision.hpp"

BillyEngine::Collision::Collision()
{
}

BillyEngine::Collision::~Collision()
{
}

bool BillyEngine::Collision::IsCheckSpriteCollision(sf::Sprite spriteParam1, sf::Sprite spriteParam2)
{
     sf::Rect<float> rectangle1 = spriteParam1.getGlobalBounds();
     sf::Rect<float> rectangle2 = spriteParam2.getGlobalBounds();

     if (rectangle1.intersects(rectangle2))
     {
          return true;
     }
     else
     {
          return false;
     }
}