#include <string>
#include <exception>
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
		whoseTurn = Team::NONE;
		turn = 0;
		
		if (m->GetNumOfBuildings(Team::RED) > 0) {
			players.emplace(Team::RED, Player());
		}
		if (m->GetNumOfBuildings(Team::BLUE) > 0) {
			players.emplace(Team::BLUE, Player());
		}
		if (m->GetNumOfBuildings(Team::GREEN) > 0) {
			players.emplace(Team::GREEN, Player());
		}
		if (m->GetNumOfBuildings(Team::YELLOW) > 0) {
			players.emplace(Team::YELLOW, Player());
		}

		EndTurn();
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
		bool exitingGame = false;
		bool bottomInfoOverDrawn = true;
		bool cursorOnUnit = false;
		
		// TODO: Is there a better way of having a reference wrapper exist?
		Unit dummyUnit(UnitType::NONE, Team::NONE, Data::GetUnitData(UnitType::NONE), -1, -1);
		std::reference_wrapper<Unit> currentSelectedUnit(dummyUnit);

		while (!exitingGame) {
			DrawMainMap();
			if (bottomInfoOverDrawn) {
				DrawTurnInfo(*this);
				bottomInfoOverDrawn = false;
			}
			for (Unit &u : units) {
				if (u.GetX() == cursorX && u.GetY() == cursorY) {
					cursorOnUnit = true;
					currentSelectedUnit = u;
					break;
				} else {
					cursorOnUnit = false;
				}
			}
			keyPress = rlutil::getkey();
			switch (keyPress) {
				case upKey:
				case downKey:
				case rightKey:
				case leftKey:
					PanMap(keyPress);	
					break;
				case cancelKey:
					if (showUnits) {
						showUnits = false;
					} else {
						showUnits = true;
					}
					break;
				case confirmKey:
					// Long part on menu functions.
					std::vector<std::string> options;
					
					
					if (!cursorOnUnit) {
						if (whoseTurn == Team::RED && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::RED_BASE) {
							options.push_back("BUY LAND UNIT");
						} else if (whoseTurn == Team::BLUE && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::BLUE_BASE) {
							options.push_back("BUY LAND UNIT");
						} else if (whoseTurn == Team::GREEN && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::GREEN_BASE) {
							options.push_back("BUY LAND UNIT");
						} else if (whoseTurn == Team::YELLOW && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::YELLOW_BASE) {
							options.push_back("BUY LAND UNIT");
						} else if (whoseTurn == Team::RED && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::RED_PORT) {
							options.push_back("BUY SEA UNIT (TODO)");
						} else if (whoseTurn == Team::BLUE && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::BLUE_PORT) {
							options.push_back("BUY SEA UNIT (TODO)");
						} else if (whoseTurn == Team::GREEN && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::GREEN_PORT) {
							options.push_back("BUY SEA UNIT (TODO)");
						} else if (whoseTurn == Team::YELLOW && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::YELLOW_PORT) {
							options.push_back("BUY SEA UNIT (TODO)");
						} else if (whoseTurn == Team::RED && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::RED_AIRPORT) {
							options.push_back("BUY AIR UNIT (TODO)");
						} else if (whoseTurn == Team::BLUE && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::BLUE_AIRPORT) {
							options.push_back("BUY AIR UNIT (TODO)");
						} else if (whoseTurn == Team::GREEN && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::GREEN_AIRPORT) {
							options.push_back("BUY AIR UNIT (TODO)");
						} else if (whoseTurn == Team::YELLOW && m->GetTile(cursorX, cursorY, true).GetType() == MapTileType::YELLOW_AIRPORT) {
							options.push_back("BUY AIR UNIT (TODO)");
						}

						options.push_back(DisableStringForMenu("FIELD INFO (TODO)"));
					} else {
						if (whoseTurn == currentSelectedUnit.get().GetTeam()) {
							// TODO: Add property for moved.
							options.push_back(DisableStringForMenu("MOVE (TODO)"));
							options.push_back(DisableStringForMenu("ATTACK (TODO)"));
						}
						options.push_back(DisableStringForMenu("UNIT INFO (TODO)"));
					}
					
					options.push_back("END TURN");
					options.push_back(DisableStringForMenu("STATS (TODO)"));
					options.push_back(DisableStringForMenu("SAVE (TODO)"));
					options.push_back(DisableStringForMenu("LOAD (TODO)"));
					options.push_back("EXIT GAME");

					std::string chosenOption = "";
					
					// TODO: Determine whether this is a healthy thing to do.
					try {
						chosenOption = options.at(CreateMenu(0, rlutil::trows() - UIInfoHeight, rlutil::tcols() - 1, UIInfoHeight, options));
					} catch (std::exception &e) {
						
					}
					
					if (chosenOption == "EXIT GAME") {
						exitingGame = true;
					} else if (chosenOption == "BUY LAND UNIT") {
						BuyLandUnit();
					} else if (chosenOption == "END TURN") {
						EndTurn();
					}
					
					bottomInfoOverDrawn = true;
					
					break;
			}
		}
	}

	void Game::DrawMainMap() {
		// TODO: Make this more efficient, such as when the map doesn't pan.
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - UIInfoHeight;

		DrawMap(m, screenWidth, screenHeight, 0, 0, mapX, mapY);
		if (showUnits) {
			DrawMapUnits(m, units, screenWidth, screenHeight, 0, 0, mapX, mapY);
		}
		
		// TODO: Move this into the UI.h.
		// TODO: Draw the cursor on units.
		rlutil::locate(cursorX - mapX + 1, cursorY - mapY + 1);
		rlutil::saveDefaultColor();
		MapTile currentTile = m->GetTile(cursorX, cursorY, true);
		rlutil::setColor(currentTile.GetForegroundColor());
		rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
		std::cout << currentTile.GetDisplayChar();
		rlutil::resetColor();
				
		/*
		if (showUnits && if on top of a unit) {
			drawUnitInfo();
		} else {*/
		DrawFieldInfo(m->GetTile(cursorX, cursorY, true));
		//}
	}

	void Game::CenterCursor() {
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - UIInfoHeight;

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
		int screenWidth = rlutil::tcols();
		int screenHeight = rlutil::trows() - UIInfoHeight;

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
	
	int Game::BuyLandUnit() {
		// TODO: Make a generic unit creation part.
		std::vector<std::string> landUnitsList;
		std::vector<UnitType> landUnits;
		for (int i = 0; i < Data::GetUnitDataSize(); i++) {
			UnitData unit = Data::GetUnitData(static_cast<UnitType>(i));
			std::string repString = "";
			
				// TODO: Decide how pipe and slime are handled.
			switch (unit.GetMovementType()) {
				case MovementType::INFANTRY:
				case MovementType::MECH:
				case MovementType::TIRES:
				case MovementType::TREAD:
					landUnits.push_back(unit.GetType());
					repString += unit.GetName();
					for (int i = unit.GetName().length(); i < 15; i++) {
						repString += " ";
					}
					repString += " - $";
					repString += std::to_string((int)unit.GetCost());
					if (GetCurrentPlayerMoney() < unit.GetCost()) {
						repString = DisableStringForMenu(repString);
					}
					landUnitsList.push_back(repString);
					break;
				default:
					break;
			}
		}
		int choice = CreateMenu(0, rlutil::trows() - UIInfoHeight, rlutil::tcols() - 1, UIInfoHeight, landUnitsList);
		if (choice == -1) {
			// TODO: Handle this.
			return 2;
		} else {
			units.emplace_back(Unit(landUnits.at(choice), whoseTurn, Data::GetUnitData(landUnits.at(choice)), cursorX, cursorY));
			players.at(whoseTurn).money -= Data::GetUnitData(landUnits.at(choice)).GetCost();
		}
		return 0;
	}
	
	Money Game::GetCurrentPlayerMoney() {
		return GetPlayerMoney(whoseTurn);
	}
	
	void Game::EndTurn() {
		bool allPlayersDone = false;
		if (whoseTurn == Team::GREEN) {
			allPlayersDone = true;
		} else if (whoseTurn == Team::YELLOW) {
			if (DoesPlayerExist(Team::GREEN)) {
				whoseTurn = Team::GREEN;
			} else {
				allPlayersDone = true;
			}
		} else if (whoseTurn == Team::BLUE) {
			if (DoesPlayerExist(Team::YELLOW)) {
				whoseTurn = Team::YELLOW;
			} else {
				allPlayersDone = true;
			}
		} else if (whoseTurn == Team::RED) {
			if (DoesPlayerExist(Team::BLUE)) {
				whoseTurn = Team::BLUE;
			} else {
				allPlayersDone = true;
			}
		} else {
			whoseTurn = Team::RED;
		}

		if (allPlayersDone) {
			whoseTurn = Team::RED;
			++turn;
		}
		
		// TODO: Make this easier to change.
		const int cashPerBuilding = 1000;

		players.at(whoseTurn).money += cashPerBuilding * m->GetNumOfBuildings(whoseTurn);

		for (Unit &u : units) {
			if (u.GetTeam() == whoseTurn) {
				// TODO: Get calculation for unit maintenance.
				// TODO: Get calculation for unit repair.
			}
		}
	}
	
	bool Game::DoesPlayerExist(Team team) {
		if (players.count(team) == 0) {
			return false;
		} else {
			return true;
		}
	}
	
	Money Game::GetPlayerMoney(Team team) {
		if (players.count(team) == 0) {
			return 0;
		} else {
			return players.at(team).money;
		}
	}
	
	Team Game::GetWhoseTurn() {
		return whoseTurn;
	}
	
	int Game::GetTurn() {
		return turn;
	}
}
