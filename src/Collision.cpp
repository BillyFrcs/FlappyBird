#include "Collision.hpp"

BillyEngine::Collision::Collision()
{
}

BillyEngine::Collision::~Collision()
{
}

/* Didn't using this collision at the moment
bool BillyEngine::Collision::IsCheckSpriteCollision(sf::Sprite spriteParam1, sf::Sprite spriteParam2)
{
     sf::Rect<float> rectangle1 = spriteParam1.getGlobalBounds();
     sf::Rect<float> rectangle2 = spriteParam2.getGlobalBounds();

     if (rectangle1.intersects(rectangle2))
     {
          return true;
     }

     return false;
}
*/

bool BillyEngine::Collision::IsCheckSpriteCollision(sf::Sprite spriteParam1, float scaleParam1, sf::Sprite spriteParam2, float scaleParam2)
{
     spriteParam1.setScale(scaleParam1, scaleParam2);
     spriteParam2.setScale(scaleParam1, scaleParam2);

     sf::Rect<float> rectangle1 = spriteParam1.getGlobalBounds();
     sf::Rect<float> rectangle2 = spriteParam2.getGlobalBounds();

     if (rectangle1.intersects(rectangle2))
     {
          return true;
     }

     return false;
}