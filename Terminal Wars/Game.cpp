#include <string>
#include "Data.h"
#include "Game.h"
#include "rlutil.h"
#include "UI.h"


namespace TerminalWars {
	Game::Game() {
		d = new Data();
		std::string mapSelection = SelectMap();
		m = new Map(mapSelection);
		cursorX = 0;
		cursorY = 0;
		CenterCursor();
		showUnits = true;
	}

	Game::Game(std::string mapPath) {
		d = new Data();
		m = new Map(mapPath);
		cursorX = 0;
		cursorY = 0;
		CenterCursor();
		showUnits = true;
	}

	Game::~Game() {
		delete d;
		delete m;
	}

	void Game::Play() {
		rlutil::cls();
		char keyPress = -1;
		while (keyPress != cancelKey) {
			DrawMainMap();
			keyPress = rlutil::getkey();
			PanMap(keyPress);
		}
	}

	void Game::DrawMainMap() {
		// TODO: Make this more efficient, such as when the map doesn't pan.
		int uiHeight = 6;
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - uiHeight;

		DrawMap(m, screenWidth, screenHeight, 0, 0, mapX, mapY);
		if (showUnits) {
			DrawMapUnits(m, units, screenWidth, screenHeight, 0, 0, mapX, mapY);
		}
		
		// TODO: Move this into the UI.h.
		// TODO: Draw the cursor on units.
		rlutil::locate(cursorX - mapX + 1, cursorY - mapY + 1);
		rlutil::saveDefaultColor();
		MapTile currentTile = Data::GetMapTileData(m->GetTile(cursorX, cursorY, true), true);
		rlutil::setColor(currentTile.GetForegroundColor());
		rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
		std::cout << currentTile.GetDisplayChar();
		rlutil::resetColor();
	}

	void Game::CenterCursor() {
		// TODO: Decide this.
		int uiHeight = 6;
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - uiHeight;

		if (cursorX < (screenWidth / 2)) {
			mapX = 0;
		} else if (cursorX > m->GetWidth() - (screenWidth / 2)) {
			mapX = m->GetWidth() - (screenWidth / 2);
		} else {
			if (screenWidth % 1 == 1) {
				mapX = cursorX - ((screenWidth - 1) / 2);
			} else {
				mapX = cursorX - (screenWidth / 2);
			}
		}
		if (cursorY < (screenHeight / 2)) {
			mapY = 0;
		} else if (cursorY > m->GetHeight() - (screenHeight / 2)) {
			mapY = m->GetWidth() - (screenHeight / 2);
		} else {
			if (screenHeight % 1 == 1) {
				mapY = cursorY - ((screenHeight - 1) / 2);
			} else {
				mapY = cursorY - (screenHeight / 2);
			}
		}
	}

	int Game::PanMap(char key) {
		float cursorDeadzone = 0.2f;
		int uiHeight = 6;
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - uiHeight;

		switch (key) {
			case upKey:
				if (cursorY > 0) {
					--cursorY;
					if (cursorY - mapY < screenHeight * cursorDeadzone && mapY > 0) {
						--mapY;
						return 2;
					}
					return 1;
				}
				return 0;
			case downKey:
				if (cursorY < m->GetHeight() - 1) {
					++cursorY;
					if (cursorY - mapY > screenHeight * (1 - cursorDeadzone) && mapY < m->GetHeight() - screenHeight + 1) {
						++mapY;
						return 2;
					}
					return 1;
				}
				return 0;
			case leftKey:
				if (cursorX > 0) {
					--cursorX;
					if (cursorX - mapX < screenWidth * cursorDeadzone && mapX > 0) {
						--mapX;
						return 2;
					}
					return 1;
				}
				return 0;
			case rightKey:
				if (cursorX < m->GetWidth() - 1) {
					++cursorX;
					if (cursorX - mapX > screenWidth * (1 - cursorDeadzone) && mapX < m->GetWidth() - screenWidth + 1) {
						++mapX;
						return 2;
					}
					return 1;
				}
				return 0;
			default:
				return 0;
		}
	}
}
