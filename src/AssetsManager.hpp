#pragma once

#ifndef ASSETS_MANAGER_HPP
	#define ASSETS_MANAGER_HPP

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
	sf::Texture& GetTexture(std::string name);

	// Load fonts
	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);

private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
};
}

#endif // ASSETS_MANAGER_HPP