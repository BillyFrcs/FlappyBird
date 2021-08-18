#pragma once

#ifndef GAME_STATE_HPP
	#define GAME_STATE_HPP

	#include <SFML/Audio.hpp>
	#include <SFML/Graphics.hpp>
	#include <SFML/Graphics/Sprite.hpp>
	#include <SFML/System/Clock.hpp>

	#include "Bird.hpp"
	#include "Collision.hpp"
	#include "FlashScreen.hpp"
	#include "Game.hpp"
	#include "Land.hpp"
	#include "Pipes.hpp"
	#include "ScoreGame.hpp"
	#include "State.hpp"

namespace BillyEngine
{
class GameState : public State
{
public:
	GameState(GameDataPtr gameData);
	~GameState();

	void Init() override;
	void HandleInput() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;

private:
	GameDataPtr _gameData;

	Pipes* _pipePtr;
	Land* _landPtr;
	Bird* _birdPtr;
	FlashScreen* _flashPtr;
	ScoreGame* _scorePtr;

	Collision _collision;

	sf::Sprite _background;
	sf::Clock _clockGame;

	int _gameState;
	int _scoreGame;

	// Set sound buffers
	sf::SoundBuffer _hitSoundBuffer;
	sf::SoundBuffer _scorePointSoundBuffer;
	sf::SoundBuffer _wingSoundBuffer;

	// Playing sound effect
	sf::Sound _hitSound;
	sf::Sound _scorePointSound;
	sf::Sound _wingSound;
};
}

#endif // GAME_STATE_HPP