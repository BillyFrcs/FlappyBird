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

bool BillyEngine::Collision::IsCheckSpriteCollision(sf::Sprite spriteCollision1, float scaleCollision1, sf::Sprite spriteCollision2, float scaleCollision2)
{
     spriteCollision1.setScale(scaleCollision1, scaleCollision1);
     spriteCollision2.setScale(scaleCollision2, scaleCollision2);

     sf::Rect<float> rectangle1 = spriteCollision1.getGlobalBounds();
     sf::Rect<float> rectangle2 = spriteCollision2.getGlobalBounds();

     /* A little bit long to use this statements
     if (rectangle1.intersects(rectangle2))
     {
          return true;
     }
     */

     // Just return this to save more time
     return rectangle1.intersects(rectangle2);
}