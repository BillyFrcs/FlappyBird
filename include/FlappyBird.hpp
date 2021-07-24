#pragma once

#include "Game.hpp"

#ifndef FLAPPYBIRD

// Window screen size ////////////////////////////////
enum WindowScreenSize
{
     // Default width = 768, height 1024 for this game
     SCREEN_WIDTH = 768,
     SCREEN_HEIGHT = 1024
};
/////////////////////////////////////////////////////

/*
 * Didn't using splash time at this moment.
#define SPLASH_STATE_TIME 3.0
*/

// Movements and frequency ///////
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f
//////////////////////////////////

// Bird Animation /////////////////////
#define BIRD_ANIMATION_FLYING_TIME 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define BIRD_GRAVITY 350.0f
#define BIRD_FLYING_SPEED 350.0f
#define BIRD_FLYING_DURATION 0.25f

#define BIRD_ROTATION_SPEED 100.f
///////////////////////////////////////

/*Flappy bird definition to load assets from file path*/
// Background and main menu /////////////////////////////////////////////////////
#define SPLASH_BACKGROUND_PATH "assets/textures/game-states/FlappySky.png"
#define MAIN_MENU_BACKGROUND_GAME_PATH "assets/textures/game-states/FlappySky.png"
#define GAME_BACKGROUND_PATH "assets/textures/game-states/FlappySky.png"
#define GAME_OVER_BACKGROUND_PATH "assets/textures/game-states/FlappySky.png"
//////////////////////////////////////////////////////////////////////////////////

// Title and button //////////////////////////////////////////////////////
#define GAME_TITLE_PATH "assets/textures/game-states/title.png"
#define PLAY_BUTTON_GAME_PATH "assets/textures/game-states/PlayButton.png"
//////////////////////////////////////////////////////////////////////////

// Pipes /////////////////////////////////////////////////////
#define PIPE_UP_FILEPATH "assets/textures/pipes/PipeUp.png"
#define PIPE_DOWN_FILEPATH "assets/textures/pipes/PipeDown.png"
//////////////////////////////////////////////////////////////

// Land /////////////////////////////////////////////////////
#define LAND_FILEPATH "assets/textures/game-states/land.png"
///////////////////////////////////////////////////////////

// Birds ///////////////////////////////////////////////////////////
#define BIRD_FRAME1_FILEPATH "assets/textures/birds/frameBird-1.png"
#define BIRD_FRAME2_FILEPATH "assets/textures/birds/frameBird-2.png"
#define BIRD_FRAME3_FILEPATH "assets/textures/birds/frameBird-3.png"
#define BIRD_FRAME4_FILEPATH "assets/textures/birds/frameBird-4.png"
////////////////////////////////////////////////////////////////////

#endif