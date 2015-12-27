#include <iostream>
#include <map>
#include <stdexcept>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"

namespace TerminalWars {
	std::map<MapTileType, MapTile> Data::mapTiles;
	std::map<UnitType, UnitData> Data::units;
	std::map<WeaponType, Weapon> Data::weapons;

	Data::Data() {
		// TODO: Make this easier to modify.
		// TODO: Add the rest.
		mapTiles.emplace(MapTileType::NONE, MapTile(MapTileType::NONE, "None", '?',  rlutil::GREY, rlutil::BLACK, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace(MapTileType::PLAIN, MapTile(MapTileType::PLAIN, "Plain", '_', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));

		units.emplace(UnitType::NONE, UnitData(UnitType::NONE, "None", '?', rlutil::MAGENTA, 0, MovementType::NONE, 0, 0));
		units.emplace(UnitType::INFANTRY, UnitData(UnitType::INFANTRY, "Infantry", 'I', rlutil::GREY, 1000, MovementType::INFANTRY, 3, 2));

		weapons.emplace(WeaponType::NONE, Weapon(WeaponType::NONE, "None", 0, 0, 0, 0, true));
		weapons.emplace(WeaponType::M_GUN, Weapon(WeaponType::M_GUN, "Machine Gun", 1, 1, -1, 0, true));
	}

	Data::~Data() {
		mapTiles.clear();
	}

	MapTile Data::GetMapTileData(MapTileType type) {
		try {
			return mapTiles.at(type);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetMapTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
		}

		return GetMapTileData(MapTileType::NONE);
	}

	int Data::GetMapTileDataSize() {
		return int(mapTiles.size());
	}


	UnitData Data::GetUnitData(UnitType type) {
		try {
			return units.at(type);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetUnitTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
		}

		return GetUnitData(UnitType::NONE);
	}

	int Data::GetUnitDataSize() {
		return int(units.size());
	}

	Weapon Data::GetWeaponData(WeaponType type) {
		try {
			return weapons.at(type);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetWeaponData() could not find type " << static_cast<int>(type) << "." << std::endl;
		}

		return GetWeaponData(WeaponType::NONE);
	}

	int Data::GetWeaponDataSize() {
		return int(weapons.size());
	}
}
