#pragma once

#ifndef MAIN_MENU_STATE_HPP
	#define MAIN_MENU_STATE_HPP

	#include <SFML/Audio.hpp>
	#include <SFML/Graphics.hpp>
	#include <SFML/Graphics/Sprite.hpp>

	#include "Game.hpp"
	#include "State.hpp"

namespace BillyEngine
{
class MainMenuState : public State
{
public:
	MainMenuState(GameDataPtr gameData);
	~MainMenuState();

	void Init() override;
	void HandleInput() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;

private:
	GameDataPtr _gameData;

	sf::Sprite _background;
	sf::Sprite _title;
	sf::Sprite _playButton;

	sf::SoundBuffer _startGameSoundBuffer;
	sf::Sound _startGameSound;
};
}

#endif // MAIN_MENU_STATE_HPP