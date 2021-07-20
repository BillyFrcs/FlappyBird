#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>

namespace BillyEngine
{
    class AssetsManager
    {
    public:
        AssetsManager();
        ~AssetsManager();

        // Load textures
        void loadTexture(std::string name, std::string fileName);
        sf::Texture &getTexture(std::string name);

        // Load fonts
        void loadFont(std::string name, std::string fileName);
        sf::Font &getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}