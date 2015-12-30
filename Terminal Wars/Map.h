#pragma once
#include <string>
#include <vector>
#include "Constants.h"

namespace TerminalWars {
	class Map {
		public:
		Map(std::string customMap);
		~Map();
		MapTileType GetTile(int x, int y, bool silent = false);
		std::string GetName();
		int GetWidth();
		int GetHeight();
		void CaptureBuilding(int x, int y, Team team);

		private:
		void LoadCustomMap(std::string customMap);
		std::vector<std::vector<MapTileType>> map;
		std::string name;
		int width;
		int height;
	};
}