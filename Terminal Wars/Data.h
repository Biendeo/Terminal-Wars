#pragma once
#include <vector>
#include "Map.h"
#include "MapTile.h"
#include "Constants.h"
#include "UI.h"

namespace TerminalWars {
	using namespace std;
	class Data {
		public:
		Data();
		~Data();
		// TODO: Is it safe to static this?
		static MapTile GetMapTileData(MapTileType type);

		private:
		static vector<MapTile> mapTiles;
	};
}