#include <vector>
#include <string>
#include "UI.h"
#include "rlutil.h"
#include "Constants.h"
#include "Data.h"
#include "Game.h"
#include "MapTile.h"

namespace TerminalWars {
	int UIInfoHeight = 6;
	float cursorDeadzone = 0.2f;
	
	int CreateMenu(int xPos, int yPos, int width, int height, std::vector<std::string> &menuItems, int padding, bool cancelable, int defaultSelect, Color unselectBack, Color unselectFore, Color selectBack, Color selectFore, Color disabledBack, Color disabledFore, Color disabledSelectBack, Color disabledSelectFore) {
		const int size = (int)menuItems.size();
		int currentSelect = defaultSelect;
		int currentTop;
		if (currentSelect < padding) {
			currentTop = 0;
		} else if (currentSelect > size - padding) {
			currentTop = size - height;
		} else if (size > height) {
			if (currentSelect > size - height / 2) {
				currentTop = size - height;
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
				if (currentTop + drawnItems >= size) {
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
				case rightKey:
					if (currentSelect > 0) {
						--currentSelect;
					}
					if (currentSelect - currentTop < padding) {
						if (currentTop > 0) {
							--currentTop;
						}
					}
					break;
				case downKey:
				case leftKey:
					if (currentSelect < size - 1) {
						++currentSelect;
					}
					if (currentTop + height - currentSelect - 1 < padding) {
						if (currentTop + height < size) {
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

	std::string DisableStringForMenu(std::string str) {
		if (str.back() != disabledChar) {
			str += disabledChar;
		}
		return str;
	}

	std::string EnableStringForMenu(std::string str) {
		if (str.back() == disabledChar) {
			str.pop_back();
		}
		return str;
	}

	bool IsStringDisabled(std::string str) {
		if (str.back() == disabledChar) {
			return true;
		} else {
			return false;
		}
	}

	std::string SelectMap() {
		int currentSelect = 0;
		int totalMaps = 2;
		std::string selectedMap = "";
		while (true) {
			rlutil::cls();
			switch (currentSelect) {
				case 0:
				default:
					selectedMap = "../Maps/Spann-Island.twmap";
					break;
				case 1:
					selectedMap = "";
					break;
			}
			if (currentSelect != totalMaps - 1) {
				Map *m = new Map(selectedMap);
				std::cout << m->GetName() << std::endl;
				// TODO: Add a small indicator telling how many of these are left.
				std::cout << currentSelect + 1 << " out of " << totalMaps << std::endl;
				DrawMap(m, rlutil::tcols(), rlutil::trows() - 2, 0, 2, 0, 0);
				delete m;
			} else {
				std::cout << "Custom map!" << std::endl;
				std::cout << currentSelect + 1 << " out of " << totalMaps << std::endl;
				// TODO: Add a small indicator telling how many of these are left.
				std::cout << "    ????    " << std::endl;
				std::cout << "   ??????   " << std::endl;
				std::cout << "   ??  ??   " << std::endl;
				std::cout << "       ??   " << std::endl;
				std::cout << "      ??    " << std::endl;
				std::cout << "     ??     " << std::endl;
				std::cout << "     ??     " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "     ??     " << std::endl;
				std::cout << "     ??     " << std::endl;
			}

			int keyPress = -1;
			while ((keyPress != upKey || currentSelect <= 0) && (keyPress != downKey || currentSelect >= totalMaps - 1) && keyPress != confirmKey && keyPress != cancelKey) {
				keyPress = rlutil::getkey();
			}
			switch (keyPress) {
				case upKey:
					--currentSelect;
					break;
				case downKey:
					++currentSelect;
					break;
				case confirmKey:
					if (currentSelect == totalMaps - 1) {
						rlutil::showcursor();
						std::cout << "Type your custom map path!" << std::endl;
						std::cin >> selectedMap;
						rlutil::hidecursor();
					}
					return selectedMap;
				case cancelKey:
					return "";
			}
		}
		return "";
	}

	void DrawMap(Map *m, int width, int height, int xScreen, int yScreen, int xMap, int yMap) {
		if (width == -1) {
			width = rlutil::tcols();
		}
		if (height == -1) {
			height = rlutil::trows();
		}
		rlutil::saveDefaultColor();
		// TODO: Use iterators rather than ints.
		int y = yMap;
		for (int j = yScreen; j < height + yScreen; j++) {
			if (j + yMap >= m->GetHeight() + yScreen) {
				break;
			}
			rlutil::locate(xScreen + 1, j + 1);
			int x = xMap;
			for (int i = xScreen; i < width + xScreen; i++) {
				if (i + xMap >= m->GetWidth() + xScreen) {
					break;
				}
				MapTile currentTile = Data::GetMapTileData(m->GetTile(x, y, true), true);
				rlutil::setColor(currentTile.GetForegroundColor());
				rlutil::setBackgroundColor(currentTile.GetBackgroundColor());
				std::cout << currentTile.GetDisplayChar();
				++x;
			}
			++y;
		}
		rlutil::resetColor();
	}

	void DrawMapUnits(Map *m, std::vector<Unit> units, int width, int height, int xScreen, int yScreen, int xMap, int yMap) {
		if (width == -1) {
			width = rlutil::tcols();
		}
		if (height == -1) {
			height = rlutil::trows();
		}
		rlutil::saveDefaultColor();

		for (int i = 0; i < (int)units.size(); i++) {
			if (units.at(i).GetX() >= xMap && units.at(i).GetX() < xMap + width && units.at(i).GetY() >= yMap && units.at(i).GetY() < yMap + height && units.at(i).GetCarried() == false) {
				rlutil::locate(units.at(i).GetX() - xMap + xScreen + 1, units.at(i).GetY() - yMap + yScreen + 1);
				rlutil::setColor(units.at(i).GetColor());
				rlutil::setBackgroundColor(Data::GetMapTileData(m->GetTile(units.at(i).GetX(), units.at(i).GetY(), true), true).GetBackgroundColor());
				std::cout << Data::GetUnitData(units.at(i).GetType(), true).GetDisplayChar();
			}
		}

		rlutil::resetColor();
	}
	
	void DrawFieldInfo(MapTile mapTile, int width, int height, int xPos, int yPos) {
		if (width == -1) {
			width = rlutil::tcols() - 20;
		}
		if (height == -1) {
			height = UIInfoHeight;
		}
		CleanRegion(width, height, xPos, yPos);
		
		rlutil::locate(xPos + 1, yPos + 1);
		
		std::cout << mapTile.GetName();
		rlutil::locate(xPos + 1, yPos + 2);
		std::cout << "Defense: ";
		rlutil::saveDefaultColor();
		rlutil::setColor(rlutil::YELLOW);
		for (int i = 0; i < (int)mapTile.GetDefense(); i++) {
			std::cout << "*";
		}
		rlutil::resetColor();
		
		// TODO: Add more info.
	}
	
	void DrawTurnInfo(Game &g, int width, int height, int xPos, int yPos) {
		if (width == -1) {
			// TODO: Move this number into a header const (or make it a float).
			width = 20;
		}
		if (height == -1) {
			height = UIInfoHeight;
		}
		
		// TODO: Figure out why the +1 is required to match with the field info function.
		CleanRegion(width + 1, height, xPos, yPos);
		
		rlutil::saveDefaultColor();
		
		rlutil::locate(xPos + 1, yPos + 1);
		
		std::cout << "Turn " << g.GetTurn();
		int players = 0;
		
		// TODO: Remove repeating parts.
		if (g.DoesPlayerExist(Team::RED)) {
			rlutil::locate(xPos + 1, yPos + 2 + players);
			if (g.GetWhoseTurn() == Team::RED) {
				std::cout << "-> ";
			} else {
				std::cout << "   ";
			}
			
			rlutil::setColor(rlutil::LIGHTRED);
			std::cout << "RED   ";
			rlutil::resetColor();
			std::cout << " - $" << g.GetPlayerMoney(Team::RED);
			
			++players;
		}
		if (g.DoesPlayerExist(Team::BLUE)) {
			rlutil::locate(xPos + 1, yPos + 2 + players);
			if (g.GetWhoseTurn() == Team::BLUE) {
				std::cout << "-> ";
			} else {
				std::cout << "   ";
			}
			
			rlutil::setColor(rlutil::LIGHTBLUE);
			std::cout << "BLUE  ";
			rlutil::resetColor();
			std::cout << " - $" << g.GetPlayerMoney(Team::BLUE);
			
			++players;
		}
		if (g.DoesPlayerExist(Team::GREEN)) {
			rlutil::locate(xPos + 1, yPos + 2 + players);
			if (g.GetWhoseTurn() == Team::GREEN) {
				std::cout << "-> ";
			} else {
				std::cout << "   ";
			}
			
			rlutil::setColor(rlutil::LIGHTGREEN);
			std::cout << "GREEN ";
			rlutil::resetColor();
			std::cout << " - $" << g.GetPlayerMoney(Team::GREEN);
			
			++players;
		}
		if (g.DoesPlayerExist(Team::YELLOW)) {
			rlutil::locate(xPos + 1, yPos + 2 + players);
			if (g.GetWhoseTurn() == Team::YELLOW) {
				std::cout << "-> ";
			} else {
				std::cout << "   ";
			}
			
			rlutil::setColor(rlutil::YELLOW);
			std::cout << "YELLOW";
			rlutil::resetColor();
			std::cout << " - $" << g.GetPlayerMoney(Team::YELLOW);
			
			++players;
		}
		
		
	}
	
	void CleanRegion(int width, int height, int xPos, int yPos) {
		rlutil::locate(xPos + 1, yPos + 1);		
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width - 1; j++) {
				std::cout << " ";
			}
			
			if (i != height - 1) {
				rlutil::locate(xPos + 1, yPos + 2 + i);
			}
		}
	}
}