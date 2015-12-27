#pragma once
#include <map>
#include "Constants.h"
#include "Map.h"
#include "MapTile.h"
#include "UI.h"
#include "Unit.h"
#include "UnitData.h"
#include "Weapon.h"

namespace TerminalWars {
	class Data {
		public:
		Data();
		~Data();
		static MapTile GetMapTileData(MapTileType type);
		static int GetMapTileDataSize();
		static UnitData GetUnitData(UnitType type);
		static int GetUnitDataSize();
		static Weapon GetWeaponData(WeaponType type);
		static int GetWeaponDataSize();

		private:
		static std::map<MapTileType, MapTile> mapTiles;
		static std::map<UnitType, UnitData> units;
		static std::map<WeaponType, Weapon> weapons;
	};
}