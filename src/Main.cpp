#include "FlappyBird.hpp"
#include "Game.hpp"
#include "Platform/Platform.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Billy | Flappy Bird Game" << std::endl;
#endif

	BillyEngine::Game(WindowScreenSize::E_Screen_Width, WindowScreenSize::E_Screen_Height, "Flappy Bird");

	return EXIT_SUCCESS;
}
