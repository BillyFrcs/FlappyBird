#include "Pipe.hpp"

BillyEngine::Pipe::Pipe(GameDataPtr gameData) : _gameData(gameData)
{
}

BillyEngine::Pipe::~Pipe()
{
}

// Draw the pipes method
void BillyEngine::Pipe::DrawPipes()
{
     for (unsigned short int i = 0; i < _pipeSprites.size(); i++)
     {
          _gameData->window.draw(_pipeSprites.at(i));
     }
}