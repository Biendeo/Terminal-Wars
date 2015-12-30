#pragma once
#include <string>
#include <vector>
#include "rlutil.h"
#include "Constants.h"
#include "Map.h"

namespace TerminalWars {

	/// These can be freely changed depending on the program user's needs.
#ifdef WIN32
	const char upKey = rlutil::KEY_UP;
	const char downKey = rlutil::KEY_DOWN;
	const char confirmKey = rlutil::KEY_ENTER;
	const char cancelKey = rlutil::KEY_ESCAPE;
	const char disabledChar = '\n';
#else
	const char upKey = 'w';
	const char downKey = 's';
	const char confirmKey = rlutil::KEY_ENTER;
	const char cancelKey = 'p';
	const char disabledChar = '\n';
#endif

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

	void DrawMap(Map *m, int width = -1, int height = -1, int xScreen = 0, int yScreen = 0, int xMap = 0, int yMap = 0);
}