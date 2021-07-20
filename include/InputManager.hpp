#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace BillyEngine
{
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        sf::Vector2i getMousePosition(sf::RenderWindow &window);
    };
}