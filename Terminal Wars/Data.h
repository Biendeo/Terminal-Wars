#pragma once
#include <map>
#include <string>
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
		// TODO: Decide whether to static this again.
		static MapTile GetMapTileData(MapTileType type, bool silent = false);
		static int GetMapTileDataSize();
		static UnitData GetUnitData(UnitType type, bool silent = false);
		static int GetUnitDataSize();
		static Weapon GetWeaponData(WeaponType type, bool silent = false);
		static int GetWeaponDataSize();
		static BaseDamage GetBaseDamage(UnitType attacker, UnitType defender, bool primary, bool silent = false);

		private:
		static std::map<MapTileType, MapTile> mapTiles;
		static std::map<UnitType, UnitData> units;
		static std::map<WeaponType, Weapon> weapons;
		static std::map<DamageKey, BaseDamage> baseDamage;

		static DamageKey MakeDamageKey(UnitType attacker, UnitType defender, bool primary);
		static MapTileType StringToMapTileType(std::string str);
		static UnitType StringToUnitType(std::string str);
		static MovementType StringToMovementType(std::string str);
		static WeaponType StringToWeaponType(std::string str);
		static Color StringToColor(std::string str);
		static std::vector<std::string> SplitLine(std::string line, char delimiter);
	};
}