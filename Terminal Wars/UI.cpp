#include <vector>
#include <string>
#include "UI.h"
#include "rlutil.h"

int TerminalWars::CreateMenu(int yPos, int xPos, int height, int width, vector<string> menuItems, bool cancelable, int defaultSelect, int unselectBack, int unselectFore, int selectBack, int selectFore, int disabledBack, int disabledFore, int disabledSelectBack, int disabledSelectFore) {
	const int paddingItems = 2;
	int currentSelect = defaultSelect;
	int currentTop;
	if (currentSelect < paddingItems) {
		currentTop = 0;
	} else if (currentSelect > (int)menuItems.size() - paddingItems) {
		currentTop = (int)menuItems.size() - height;
	} else if ((int)menuItems.size() > height) {
		if (currentSelect > (int)menuItems.size() - height / 2) {
			currentTop = (int)menuItems.size() - height;
		} else {
			currentTop = currentSelect - height / 2;
		}
	} else {
		currentTop = 0;
	}

	int chosenItem = -1;
	while (chosenItem < 0) {
		int drawnItems = 0;
		rlutil::saveDefaultColor();
		while (drawnItems < height) {
			rlutil::locate(xPos + 1, yPos + 1 + drawnItems);
			if (currentTop + drawnItems >= (int)menuItems.size()) {
				break;
			}
			std::string currentString = menuItems.at(currentTop + drawnItems);
			if (IsStringDisabled(currentString) && currentTop + drawnItems == currentSelect) {
				rlutil::setColor(disabledSelectFore);
				rlutil::setBackgroundColor(disabledSelectBack);
			} else if (IsStringDisabled(currentString)) {
				rlutil::setColor(disabledFore);
				rlutil::setBackgroundColor(disabledBack);
			} else if (currentTop + drawnItems == currentSelect) {
				rlutil::setColor(selectFore);
				rlutil::setBackgroundColor(selectBack);
			} else {
				rlutil::setColor(unselectFore);
				rlutil::setBackgroundColor(unselectBack);
			}
			if (IsStringDisabled(currentString)) {
				currentString = EnableStringForMenu(currentString);
			}
			if ((int)currentString.length() > width) {
				currentString = currentString.substr(0, width - 3) + "...";
			} else if ((int)currentString.length() < width) {
				while ((int)currentString.length() < width) {
					currentString += " ";
				}
			}
			std::cout << currentString;
			++drawnItems;
		}
		rlutil::resetColor();

		int keyPress = -1;
		while (keyPress != upKey && keyPress != downKey && keyPress != confirmKey && keyPress != cancelKey) {
			keyPress = rlutil::getkey();
		}
		switch (keyPress) {
			case upKey:
				if (currentSelect > 0) {
					--currentSelect;
				}
				if (currentSelect - currentTop < paddingItems) {
					if (currentTop > 0) {
						--currentTop;
					}
				}
				break;
			case downKey:
				if (currentSelect < (int)menuItems.size() - 1) {
					++currentSelect;
				}
				if (currentTop + height - currentSelect - 1 < paddingItems) {
					if (currentTop + height < (int)menuItems.size()) {
						++currentTop;
					}
				}
				break;
			case confirmKey:
				if (!IsStringDisabled(menuItems.at(currentSelect))) {
					chosenItem = currentSelect;
				}
				break;
			case cancelKey:
				if (cancelable) {
					return -1;
				} else {
					break;
				}
		}
	}
	return chosenItem;
}

string TerminalWars::DisableStringForMenu(string str) {
	if (str.back() != disabledChar) {
		str += disabledChar;
	}
	return str;
}

string TerminalWars::EnableStringForMenu(string str) {
	if (str.back() == disabledChar) {
		str.pop_back();
	}
	return str;
}

bool TerminalWars::IsStringDisabled(string str) {
	if (str.back() == disabledChar) {
		return true;
	} else {
		return false;
	}
}
