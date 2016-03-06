#pragma once
#include <string>
#include <vector>
#include "rlutil.h"
#include "Constants.h"
#include "Map.h"
#include "MapTile.h"
#include "Unit.h"

namespace TerminalWars {
	
	class Game;

	/// These can be freely changed depending on the program user's needs.
#ifdef WIN32
	const char upKey = rlutil::KEY_UP;
	const char downKey = rlutil::KEY_DOWN;
	const char leftKey = rlutil::KEY_LEFT;
	const char rightKey = rlutil::KEY_RIGHT;
	const char confirmKey = rlutil::KEY_ENTER;
	const char cancelKey = rlutil::KEY_ESCAPE;
#else
	const char upKey = 'w';
	const char downKey = 's';
	const char leftKey = 'a';
	const char rightKey = 'd';
	const char confirmKey = rlutil::KEY_SPACE;
	const char cancelKey = 'p';
#endif

	const char disabledChar = '\n';
	
	// TODO: Decide if this is good practice.
	extern int UIInfoHeight; // 6
	extern float cursorDeadzone; // 0.2f

	/// Function: CreateMenu
	/// This function will display a menu at a given position on the screen.
	/// It returns the index of the confirmed item. Disabled items will not be
	/// returned. You can also optionally add a default starting point on the menu,
	/// set whether the user can "cancel" the menu, and change the background and
	/// foreground colours of each of the four states.
	int CreateMenu(int xPos, int yPos, int width, int height, std::vector<std::string> menuItems, int padding = 2, bool cancelable = true, int defaultSelect = 0, Color unselectBack = rlutil::BLACK, Color unselectFore = rlutil::GREY, Color selectBack = rlutil::BLACK, Color selectFore = rlutil::YELLOW, Color disabledBack = rlutil::BLACK, Color disabledFore = rlutil::DARKGREY, Color disabledSelectBack = rlutil::BLACK, Color disabledSelectFore = rlutil::BROWN);

	/// Function: DisableStringForMenu
	/// This function returns the string with the disabledChar added to it.
	/// It returns the input if it already has it.
	std::string DisableStringForMenu(std::string str);

	/// Function: EnableStringForMenu
	/// This function returns the string with the disabledChar removed from it.
	/// It returns the input if it doesn't have it.
	std::string EnableStringForMenu(std::string str);

	/// Function: IsStringDisabled
	/// This function returns true if the string has the disabledChar on the end.
	bool IsStringDisabled(std::string str);

	/// Function: SelectMap
	/// This function prompts the user with a menu and returns the path to the
	/// map file.
	std::string SelectMap();

	/// Function: DrawMap
	/// This function draws the map at a specific position on the screen.
	/// It has optional parameters for the position of the map as well.
	void DrawMap(Map *m, int width = -1, int height = -1, int xScreen = 0, int yScreen = 0, int xMap = 0, int yMap = 0);

	/// Function: DrawMapUnits
	/// This function draws the map units only on the screen.
	/// It has optional parameters for the position of the map as well.
	void DrawMapUnits(Map *m, std::vector<Unit> units, int width = -1, int height = -1, int xScreen = 0, int yScreen = 0, int xMap = 0, int yMap = 0);
	
	/// Function: DrawFieldInfo
	/// This function draws the field description underneath the map for the
	/// user. It has optional parameters for the position of the element, but
	/// it is ideal to set this so that it fits on the user's screen.
	void DrawFieldInfo(MapTile mapTile, int width = -1, int height = -1, int xPos = 20, int yPos = rlutil::trows() - UIInfoHeight);
	
	/// Function: DrawTurnInfo
	/// This function draws the turn details underneath the map for the user.
	/// It has optional parameters for the position of the element, but it is
	/// ideal to set this so that it fits on the user's screen
	void DrawTurnInfo(Game &g, int width = -1, int height = -1, int xPos = 0, int yPos = rlutil::trows() - UIInfoHeight);
	
	/// Function: CleanRegion
	/// This function prints spaces in a given rectangle, effectively cleaning
	/// it on the screen. Remember to move the cursor after using it.
	void CleanRegion(int width, int height, int xPos, int yPos);
}