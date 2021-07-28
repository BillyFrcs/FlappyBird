#pragma once

#include <SFML/Audio.hpp>
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
        void LoadTexture(std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);

        // Load fonts
        void LoadFont(std::string name, std::string fileName);
        sf::Font &GetFont(std::string name);

        /* Didn't using this methods cuz there are some bugs with sound buffer
        // Load sound effects
        void LoadSound(std::string name, std::string fileName);
        sf::SoundBuffer &GetSoundBuffer(std::string name);
        */

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        //std::map<std::string, sf::SoundBuffer> _soundBuffers;
    };
}