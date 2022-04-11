#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING // Needed with c++17

#include <iostream>
#include <string>
#include "textpixels_enums.h"
#include "textpixels.h"
#include "ContactTracing.h"

using namespace std;
using namespace textpixels;

// A collection of screens you would want in game
enum Screen         
{
  MENU = 1,
  PLAY,
  PAUSE,
  GAMEOVER,
  EXIT,
  NONE
};

// The playing area (snake garden) is above the graphic user interface (GUI)
const int LEVEL_WIDTH = 40;
const int LEVEL_HEIGHT = 20;
const int GUI_HEIGHT = 10;

// Function declarations
void drawLevelAndGui(int score);
int displayMenuScreen();

/* ------------------------------------------------------------------------- MAIN */
int main()
{
  // textpixels creates our console window
  textpixels::setupConsole( LEVEL_WIDTH, LEVEL_HEIGHT+GUI_HEIGHT);

  /// I chose `screen` as a term for part of the program with its own visuals+controls
  int screen = Screen::MENU;    // Start the game at the menu.

  /// Main game loop
  while (screen != Screen::EXIT)
  {
    if (screen == Screen::MENU)
    {
      screen = displayMenuScreen();
    }
    else if (screen == Screen::PLAY)
    {
      screen = Screen::MENU;      // When game is done, we want to go to menu
    }
  }

  // Show Exit screen?
  textpixels::exit();
  return (0);
}

/* -------------------------------------------------------- FUNCTION DEFINITIONS */

// Draw the Level's ground and border wall to top of window,
// draw gui with score and any other info at bottom.
void drawLevelAndGui(int score)
{
  // Draw the background and a wall.
  fillWindow(GREY);
  fillRect(1, 1, LEVEL_WIDTH - 2, LEVEL_HEIGHT - 2, DARK_MAGENTA);

  // Draw extra controls the player has whilst playing
  /*drawString(3, LEVEL_HEIGHT + 1, "(Q) ", FG_CYAN);
  drawString(9, LEVEL_HEIGHT + 1, "quit", FG_GREY);
  drawString(3, LEVEL_HEIGHT + 3, "(R) ", FG_CYAN);
  drawString(9, LEVEL_HEIGHT + 3, "retry", FG_GREY);
  drawString(3, LEVEL_HEIGHT + 5, "(P) ", FG_CYAN);
  drawString(9, LEVEL_HEIGHT + 5, "pause", FG_GREY);*/
}

// Draws the menu screen, waits for user input.
// Returns the player's choice using a constant from enum Screen.
int displayMenuScreen()
{
  textpixels::setFps(60);
  int choice = Screen::NONE;

  do                            // Keeps looping, waiting for input
  {
    textpixels::startFrame();   // Needed always at start of game loop

    fillWindow(FG_WHITE);
    drawString(3, 5, "(P) Play Portal Snake", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    drawString(3, 8, "(O) Play Solid Snake", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    drawString(3, 11, "(X) Exit", layerColours(FG_WHITE, BG_DARK_GREY));
    
    drawString(3, windowHeight()-2, "v0.3 The fruitening", layerColours(FG_DARK_GREY, BG_WHITE));

    // Check if any valid keys are down. `else if` makes sure we only take one
    // input at a time. 
    if (retryWasPressed)
    {
        choice = Screen::PLAY;
    }
    else if (keyIsDown('P'))
    {
        while (keyIsDown('P'))
        choice = Screen::PLAY;
    }
    else if (keyIsDown('O'))
    {
        while (keyIsDown('O'))
        choice = Screen::PLAY;
    }
    else if (keyIsDown('X'))
    {
        while (keyIsDown('X'))
        choice = Screen::EXIT;
    }

    textpixels::endFrame();     // Needed always at end of game loop.

  } while (choice == Screen::NONE);     // Only stop when playerHasQuit  

  return(choice);
}
