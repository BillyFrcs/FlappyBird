#pragma once

#include "Game.hpp"

// Window screen size
enum Screen
{
     SCREEN_WIDTH = 768,
     SCREEN_HEIGHT = 1024
};

/*
 * Didn't using splash time at this moment.
#define SPLASH_STATE_TIME 3.0
*/

// Flappy bird definition to load assets from file path
#define SPLASH_BACKGROUND_PATH "assets/SplashState/res/FlappySky.png"
#define MAIN_MENU_BACKGROUND_GAME_PATH "assets/SplashState/res/FlappySky.png"
#define GAME_BACKGROUND_PATH "assets/SplashState/res/FlappySky.png"
#define GAME_OVER_BACKGROUND_PATH "assets/SplashState/res/FlappySky.png"

#define GAME_TITLE_PATH "assets/SplashState/res/title.png"
#define PLAY_BUTTON_GAME_PATH "assets/SplashState/res/PlayButton.png"

#define PIPE_UP_FILEPATH "assets/SplashState/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "assets/SplashState/res/PipeDown.png"