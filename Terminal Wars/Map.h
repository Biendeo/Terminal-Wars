#pragma once
#include <vector>
#include "Constants.h"

namespace TerminalWars {
	class Map {
		public:
		Map();
		~Map();
		MapTileType GetTile(int x, int y);
		int GetWidth();
		int GetHeight();
		void CaptureBuilding(int x, int y, Team team);

		private:
		std::vector<std::vector<MapTileType>> map;
		int width;
		int height;
	};
}