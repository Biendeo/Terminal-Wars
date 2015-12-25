#pragma once
#include <vector>
#include <string>
#include "rlutil.h"

using namespace std;
using namespace rlutil;
namespace TerminalWars {
	
	/// These can be freely changed depending on the program user's needs.
	const int upKey = KEY_UP;
	const int downKey = KEY_DOWN;
	const int confirmKey = KEY_ENTER;
	const int cancelKey = KEY_ESCAPE;
	const int disabledChar = '\n';

	/// Function: CreateMenu
	/// This function will display a menu at a given position on the screen.
	/// It returns the index of the confirmed item. Disabled items will not be
	/// returned. You can also optionally add a default starting point on the menu,
	/// set whether the user can "cancel" the menu, and change the background and
	/// foreground colours of each of the four states.
	int CreateMenu(int yPos, int xPos, int height, int width, vector<string> menuItems, int padding = 2, bool cancelable = true, int defaultSelect = 0, int unselectBack = BLACK, int unselectFore = GREY, int selectBack = BLACK, int selectFore = YELLOW, int disabledBack = BLACK, int disabledFore = DARKGREY, int disabledSelectBack = BLACK, int disabledSelectFore = BROWN);

	/// Function: DisableStringForMenu
	/// This function returns the string with the disabledChar added to it.
	/// It returns the input if it already has it.
	string DisableStringForMenu(string str);


	/// Function: EnableStringForMenu
	/// This function returns the string with the disabledChar removed from it.
	/// It returns the input if it doesn't have it.
	string EnableStringForMenu(string str);

	/// Function: IsStringDisabled
	/// This function returns true if the string has the disabledChar on the end.
	bool IsStringDisabled(string str);
}