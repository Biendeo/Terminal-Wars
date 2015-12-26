#pragma once
#include <vector>
#include "Constants.h"
#include "Map.h"
#include "MapTile.h"
#include "UI.h"
#include "Unit.h"
#include "UnitData.h"

namespace TerminalWars {
	class Data {
		public:
		Data();
		~Data();
		static MapTile GetMapTileData(MapTileType type);
		static UnitData GetUnitData(UnitType type);

		private:
		static std::vector<MapTile> mapTiles;
		static std::vector<UnitData> units;
	};
}