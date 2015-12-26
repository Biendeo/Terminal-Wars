#include <iostream>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"

namespace TerminalWars {
	vector<MapTile> Data::mapTiles;
	vector<UnitData> Data::units;
	vector<Weapon> Data::weapons;

	Data::Data() {
		// TODO: Make this easier to modify.
		// TODO: Add the rest.
		mapTiles.emplace_back(MapTile(MapTileType::NONE, "None", '?',  rlutil::GREY, rlutil::BLACK, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace_back(MapTile(MapTileType::PLAIN, "Plain", '_', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));

		units.emplace_back(UnitData(UnitType::NONE, "None", '?', rlutil::MAGENTA, 0, MovementType::NONE, 0, 0));
		units.emplace_back(UnitData(UnitType::INFANTRY, "Infantry", 'I', rlutil::GREY, 1000, MovementType::INFANTRY, 3, 2));

		weapons.emplace_back(Weapon(WeaponType::NONE, "None", 0, 0, 0, 0, true));
		weapons.emplace_back(Weapon(WeaponType::M_GUN, "Machine Gun", 1, 1, -1, 0, true));
	}

	Data::~Data() {
		mapTiles.clear();
	}

	MapTile Data::GetMapTileData(MapTileType type) {
		for (int i = 0; i < int(mapTiles.size()); i++) {
			if (mapTiles.at(i).GetType() == type) {
				return mapTiles.at(i);
			}
		}

		std::cerr << "GetMapTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
		return GetMapTileData(MapTileType::NONE);
	}

	int Data::GetMapTileDataSize() {
		return int(mapTiles.size());
	}


	UnitData Data::GetUnitData(UnitType type) {
		for (int i = 0; i < int(units.size()); i++) {
			if (units.at(i).GetType() == type) {
				return units.at(i);
			}
		}

		std::cerr << "GetUnitTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
		return GetUnitData(UnitType::NONE);
	}

	int Data::GetUnitDataSize() {
		return int(units.size());
	}

	Weapon Data::GetWeaponData(WeaponType type) {
		for (int i = 0; i < int(weapons.size()); i++) {
			if (weapons.at(i).GetType() == type) {
				return weapons.at(i);
			}
		}

		std::cerr << "GetWeaponData() could not find type " << static_cast<int>(type) << "." << std::endl;
		return GetWeaponData(WeaponType::NONE);
	}

	int Data::GetWeaponDataSize() {
		return int(weapons.size());
	}
}
