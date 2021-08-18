#pragma once

#ifndef SPLASH_STATE_HPP
	#define SPLASH_STATE_HPP

	#include <SFML/Graphics.hpp>
	#include <SFML/Graphics/Sprite.hpp>
	#include <SFML/System/Clock.hpp>

	#include "Game.hpp"
	#include "State.hpp"

namespace BillyEngine
{
class SplashState : public State
{
public:
	SplashState(GameDataPtr gameData);
	~SplashState();

	void Init() override;
	void HandleInput() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;

private:
	GameDataPtr _gameData;

	sf::Clock _clock;
	sf::Sprite _background;
};
}

#endif // PLASH_STATE_HPP