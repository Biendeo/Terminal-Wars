#pragma once
#include <map>
#include <string>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "Map.h"
#include "MapTile.h"
#include "UI.h"
#include "Unit.h"
#include "UnitData.h"
#include "Weapon.h"

namespace TerminalWars {
	class Player {
		public:
		Team team;
		Money money;
		Player() {
			team = Team::NONE;
			money = 0;
		}
	};

	class Game {
		public:
		Game();
		Game(std::string mapPath);
		~Game();
		void Play();
		void DrawMainMap();
		void CenterCursor();
		int BuyLandUnit();
		void EndTurn();
		bool DoesPlayerExist(Team team);
		Money GetPlayerMoney(Team team);
		Team GetWhoseTurn();
		int GetTurn();

		/// Function: PanMap
		/// This function takes in a key press, and if it's a valid key, moves the
		/// cursor and the map if it needs to. It returns 0 if the cursor didn't
		/// move, 1 if it did, and 2 if the map also moved.
		int PanMap(char key);
		Data *d;
		Map *m;

		private:
		int turn;
		Team whoseTurn;
		std::map<Team, Player> players;
		std::vector<Unit> units;
		int cursorX;
		int cursorY;
		int mapX;
		int mapY;
		bool showUnits;
		Money GetCurrentPlayerMoney();
	};
}