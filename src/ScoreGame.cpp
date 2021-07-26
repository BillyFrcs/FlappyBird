#include "ScoreGame.hpp"

#define CHARACTER_SIZE 100

BillyEngine::ScoreGame::ScoreGame(GameDataPtr gameData) : _gameData(gameData)
{
     _scoreText.setFont(_gameData->assets.GetFont("Flappy Font"));

     _scoreText.setString("0");
     _scoreText.setCharacterSize(CHARACTER_SIZE);
     _scoreText.setFillColor(sf::Color::White);

     // Set position on the screen
     _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
     _scoreText.setPosition(_gameData->window.getSize().x / 2, _gameData->window.getSize().y / 5);
}

BillyEngine::ScoreGame::~ScoreGame()
{
}

void BillyEngine::ScoreGame::UpdateScore(int scoreParam)
{
     // Convert int score to string
     _scoreText.setString(std::to_string(scoreParam));
}

void BillyEngine::ScoreGame::DrawScore()
{
     _gameData->window.draw(_scoreText);
}