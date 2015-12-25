#include <iostream>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"

namespace TerminalWars {
	vector<MapTile> Data::mapTiles;

	Data::Data() {
		mapTiles.emplace_back(MapTile(MapTileType::FIELD, "Field"));
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
