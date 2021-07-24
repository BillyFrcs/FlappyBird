#include "FlappyBird.hpp"
#include "Game.hpp"

int main()
{
    BillyEngine::Game(WindowScreenSize::E_Screen_Width, WindowScreenSize::E_Screen_Height, "Flappy Bird");

    return EXIT_SUCCESS;
}