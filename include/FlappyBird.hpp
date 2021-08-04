#pragma once

#include "Game.hpp"

#ifndef FLAPPY__BIRD

/*
 * Didn't using splash time at this moment.
#define SPLASH_STATE_TIME 3.0
*/

// Movements and frequency ////////
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.2f
//////////////////////////////////

// Bird animations //////////////////////
#define BIRD_ANIMATION_FLYING_TIME 0.5f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define BIRD_GRAVITY 260.0f
#define BIRD_FLYING_SPEED 260.0f
#define BIRD_FLYING_DURATION 0.29f

#define BIRD_ROTATION_SPEED 100.0f
/////////////////////////////////////////

// Flash speed ////////////
#define FLASH_SPEED 3000.0f
///////////////////////////

// Time before game over appears ////
#define TIME_GAME_OVER 1.0f
////////////////////////////////////

// Medals score //////////
#define BRONZE_MEDAL 0
#define SILVER_MEDAL 5
#define GOLD_MEDAL 20
#define PLATINUM_MEDAL 50
//////////////////////////

/*Flappy bird definition to load assets directories*/
// Background and main menu filepath //////////////////////////////////////////////
#define SPLASH_BACKGROUND_PATH "assets/textures/game-states/FlappyDay.png"
#define MAIN_MENU_BACKGROUND_GAME_PATH "assets/textures/game-states/FlappyDay.png"
#define GAME_BACKGROUND_PATH "assets/textures/game-states/FlappyNight.png"
#define GAME_OVER_BACKGROUND_FILEPATH "assets/textures/game-states/FlappyNight.png"
//////////////////////////////////////////////////////////////////////////////////

// Game over filepath ///////////////////////////////////////////////////////////
#define GAME_OVER_TITLE_FILEPATH "assets/textures/game-states/GameOverTitle.png"
#define GAME_OVER_FILEPATH "assets/textures/game-states/GameOver.png"
////////////////////////////////////////////////////////////////////////////////

// Title and button filepath /////////////////////////////////////////////////
#define GAME_TITLE_PATH "assets/textures/game-states/TitleGame.png"
#define PLAY_BUTTON_GAME_FILEPATH "assets/textures/game-states/PlayButton.png"
//////////////////////////////////////////////////////////////////////////////

// Pipes ///////////////////////////////////////////////////////////////////////////////
#define PIPE_UP_FILEPATH "assets/textures/pipes/PipeUp.png"
#define PIPE_DOWN_FILEPATH "assets/textures/pipes/PipeDown.png"
#define INVISIBLE_SCORING_PIPE_FILEPATH "assets/textures/pipes/InvisibleScoringPipe.png"
////////////////////////////////////////////////////////////////////////////////////////

// Land filepath /////////////////////////////////////////////////////
constexpr auto LAND_FILEPATH = "assets/textures/game-states/Land.png";
/////////////////////////////////////////////////////////////////////

// Birds filepath //////////////////////////////////////////////////
#define BIRD_FRAME1_FILEPATH "assets/textures/birds/frame-1.png"
#define BIRD_FRAME2_FILEPATH "assets/textures/birds/frame-2.png"
#define BIRD_FRAME3_FILEPATH "assets/textures/birds/frame-3.png"
#define BIRD_FRAME4_FILEPATH "assets/textures/birds/frame-4.png"
////////////////////////////////////////////////////////////////////

// Fonts filepath /////////////////////////////////////////////////
constexpr auto FLAPPY_FONT_FILEPATH = "assets/fonts/FlappyFont.ttf";
///////////////////////////////////////////////////////////////////

// Medals filepath ///////////////////////////////////////////////////////
#define BRONZE_MEDAL_FILEPATH "assets/textures/medals/BronzeMedal.png"
#define SILVER_MEDAL_FILEPATH "assets/textures/medals/SilverMedal.png"
#define GOLD_MEDAL_FILEPATH "assets/textures/medals/GoldMedal.png"
#define PLATINUM_MEDAL_FILEPATH "assets/textures/medals/PlatinumMedal.png"
/////////////////////////////////////////////////////////////////////////

// Sounds effect filepath //////////////////////////////////
#define HIT_SOUND_FILEPATH "assets/sounds/Hit.wav"
#define SCORE_POINT_SOUND_FILEPATH "assets/sounds/Point.wav"
#define WING_SOUND_FILEPATH "assets/sounds/Wing.wav"

#define START_GAME_SOUND_FIlEPATH "assets/sounds/Point.wav"
#define RETRY_GAME_SOUND_FILEPATH "assets/sounds/Point.wav"
////////////////////////////////////////////////////////////

// Window screen size //////
enum WindowScreenSize
{
     E_Screen_Width = 500,
     E_Screen_Height = 680
};
//////////////////////////

// Game states //////
enum GameStates
{
     E_GameReady,
     E_PlayingGame,
     E_GameOver
};
///////////////////

#endif