#pragma once

#include <SFML/System/Time.hpp>

namespace BillyEngine
{
     class State
     {
     public:
          // States game
          virtual void Init() = 0;
          virtual void HandleInput() = 0;
          virtual void Update(float deltaTime) = 0;
          virtual void Draw(float deltaTime) = 0;

          virtual void Pause(){};
          virtual void Resume(){};
     };
}