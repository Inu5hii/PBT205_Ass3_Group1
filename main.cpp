#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING // Needed with c++17

#include <iostream>
#include <string>
#include "textpixels_enums.h"
#include "textpixels.h"

using namespace std;
using namespace textpixels;

// A collection of screens you would want in game
enum Screen         
{
  MENU = 1,
  CHAT,
  STOCKS,
  CONTACT_TRACING,
  EXIT,
  NONE
};

// The playing area (snake garden) is above the graphic user interface (GUI)
const int LEVEL_WIDTH = 128;
const int LEVEL_HEIGHT = 72;

// Function declarations
int displayMenuScreen();

// Chat functions
void ChatScreen();

// Stock functions
void StockScreen();

// Chess functions
void ChessScreen();

/* ------------------------------------------------------------------------- MAIN */
int main()
{
  // textpixels creates our console window
  textpixels::setupConsole( LEVEL_WIDTH, LEVEL_HEIGHT);

  /// I chose `screen` as a term for part of the program with its own visuals+controls
  int screen = Screen::MENU;    // Start the game at the menu.

  /// Main game loop
  while (screen != Screen::EXIT)
  {
    if (screen == Screen::MENU)
    {
      screen = displayMenuScreen();
    }
    else if (screen == Screen::CHAT)
    {
        ChatScreen();
        screen = Screen::MENU;
    }
    else if (screen == Screen::STOCKS)
    {
        StockScreen();
        screen = Screen::MENU;
    }
    else if (screen == Screen::CONTACT_TRACING)
    {
        ChessScreen();
        screen = Screen::MENU;
    }
  }

  // Show Exit screen?
  textpixels::exit();
  return (0);
}

/* -------------------------------------------------------- FUNCTION DEFINITIONS */
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
    fillRect(0, 0, 30, 5, FG_DARK_BLUE);
    drawString(8, 2, "Project CCS", layerColours(FG_WHITE, BG_DARK_BLUE));
    drawString(9, 15, "(Q) Chat", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    drawString(9, 18, "(W) Stocks", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    drawString(9, 21, "(E) Contact Tracing", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    drawString(9, 60, "(X) Exit", layerColours(FG_WHITE, BG_DARK_MAGENTA));
    

    // Check if any valid keys are down. `else if` makes sure we only take one
    // input at a time. 
    if (keyIsDown('Q'))
    {
        while (keyIsDown('Q'))
        choice = Screen::CHAT;
    }
    else if (keyIsDown('W'))
    {
        while (keyIsDown('W'))
        choice = Screen::STOCKS;
    }
    else if (keyIsDown('E'))
    {
        while (keyIsDown('E'))
        choice = Screen::CONTACT_TRACING;
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


// Chat functions
void ChatScreen()
{

}


// Stock functions
void StockScreen()
{

}


// Chess functions
void ChessScreen()
{

}
