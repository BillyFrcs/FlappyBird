#pragma once

#ifndef INPUT_MANAGER

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

        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}

#endif