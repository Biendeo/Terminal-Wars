#pragma once
#include <functional>
#include <string>
#include <vector>
#include "Constants.h"
#include "MapTile.h"

namespace TerminalWars {
	class Map {
		public:
		Map(std::string customMap);
		~Map();
		MapTile &GetTile(int x, int y, bool silent = false);
		std::string GetName();
		int GetWidth();
		int GetHeight();
		void CaptureBuilding(int x, int y, Team team);
		int GetNumOfBuildings(Team team = Team::NONE);
		int GetNumPlayers();

		private:
		void LoadCustomMap(std::string customMap);
		std::vector<std::vector<std::reference_wrapper<MapTile>>> map;
		std::string name;
		int width;
		int height;
	};
}