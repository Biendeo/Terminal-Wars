#include <iostream>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"

namespace TerminalWars {
	vector<MapTile> Data::mapTiles;
	vector<UnitData> Data::units;

	Data::Data() {
		// TODO: Make this easier to modify.
		mapTiles.emplace_back(MapTile(MapTileType::NONE, "None", '?', rlutil::BLACK, rlutil::GREY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace_back(MapTile(MapTileType::PLAIN, "Plain", '_', rlutil::GREEN, rlutil::LIGHTGREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));
		// TODO: Add the rest.
		units.emplace_back(UnitData(UnitType::NONE, "None", '?', rlutil::MAGENTA, 0, MovementType::NONE));
		units.emplace_back(UnitData(UnitType::INFANTRY, "Infantry", 'I', rlutil::GREY, 1000, MovementType::INFANTRY));
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

	UnitData Data::GetUnitData(UnitType type) {
		for (int i = 0; i < int(units.size()); i++) {
			if (units.at(i).GetType() == type) {
				return units.at(i);
			}
		}

		std::cerr << "GetUnitTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
		return GetUnitData(UnitType::NONE);
	}
}
