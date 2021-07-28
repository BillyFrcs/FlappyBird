#include "AssetsManager.hpp"

BillyEngine::AssetsManager::AssetsManager()
{
}

BillyEngine::AssetsManager::~AssetsManager()
{
}

// Load texture
void BillyEngine::AssetsManager::LoadTexture(std::string name, std::string fileName)
{
     sf::Texture texture;

     if (texture.loadFromFile(fileName))
     {
          this->_textures[name] = texture;
     }
}

sf::Texture &BillyEngine::AssetsManager::GetTexture(std::string name)
{
     return this->_textures.at(name);
}

// Load fonts
void BillyEngine::AssetsManager::LoadFont(std::string name, std::string fileName)
{
     sf::Font font;

     if (font.loadFromFile(fileName))
     {
          this->_fonts[name] = font;
     }
}

sf::Font &BillyEngine::AssetsManager::GetFont(std::string name)
{
     return this->_fonts.at(name);
}

/* Still have bugs with this method when load sound buffer
// Load sound
void BillyEngine::AssetsManager::LoadSound(std::string name, std::string fileName)
{
     sf::SoundBuffer soundBuffer;

     if (soundBuffer.loadFromFile(fileName))
     {
          this->_soundBuffers[name] = soundBuffer;
     }
}

sf::SoundBuffer &BillyEngine::AssetsManager::GetSoundBuffer(std::string name)
{
     return this->_soundBuffers.at(name);
}*/