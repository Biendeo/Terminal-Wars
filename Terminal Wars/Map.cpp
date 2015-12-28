#include <iostream>
#include <stdexcept>
#include "Constants.h"
#include "Data.h"
#include "Map.h"

namespace TerminalWars {
	Map::Map() {
		// TODO
	}


	Map::~Map() {
		// TODO
		for (int i = 0; i < int(map.size()); i++) {
			map.at(i).clear();
		}
		map.clear();
	}


	MapTileType Map::GetTile(int x, int y) {
		if (x >= GetWidth()) {
			return MapTileType::NONE;
		} else if (y >= GetHeight()) {
			return MapTileType::NONE;
		} else {
			return map.at(x).at(y);
		}
	}

	int Map::GetWidth() {
		return width;
	}

	int Map::GetHeight() {
		return height;
	}

	void Map::CaptureBuilding(int x, int y, Team team) {
		// TODO: Fill in all MapTiles.
		try {
			switch (map.at(x).at(y)) {
				case MapTileType::NONE_CITY:
				case MapTileType::RED_CITY:
				case MapTileType::BLUE_CITY:
				case MapTileType::GREEN_CITY:
				case MapTileType::YELLOW_CITY:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_CITY;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_CITY;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_CITY;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_CITY;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_CITY;
							break;
					}
					break;
				default:
					std::cerr << "Map::CaptureBuilding() tried to convert an invalid " << Data::GetMapTileData(map.at(x).at(y)).GetName() << "." << std::endl;
					break;
			}
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Map::CaptureBuilding() was given a bad range (" << x << ", " << y << ")." << std::endl;
			std::cerr << oor.what() << std::endl;
			return;
		}
	}
}

