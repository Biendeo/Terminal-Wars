#include <iostream>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"

namespace TerminalWars {
	vector<MapTile> Data::mapTiles;

	Data::Data() {
		// TODO: Make this easier to modify.
		mapTiles.emplace_back(MapTile(MapTileType::NONE, "None", '?', rlutil::BLACK, rlutil::GREY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace_back(MapTile(MapTileType::PLAIN, "Plain", '_', rlutil::GREEN, rlutil::LIGHTGREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));
		// TODO: Add the rest.
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
}
