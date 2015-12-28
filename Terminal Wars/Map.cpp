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
		// TODO: Error checking?
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
		// TODO: Make this not as repetitive.
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
				case MapTileType::NONE_HQ:
				case MapTileType::RED_HQ:
				case MapTileType::BLUE_HQ:
				case MapTileType::GREEN_HQ:
				case MapTileType::YELLOW_HQ:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_HQ;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_HQ;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_HQ;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_HQ;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_HQ;
							break;
					}
					break;
				case MapTileType::NONE_BASE:
				case MapTileType::RED_BASE:
				case MapTileType::BLUE_BASE:
				case MapTileType::GREEN_BASE:
				case MapTileType::YELLOW_BASE:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_BASE;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_BASE;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_BASE;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_BASE;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_BASE;
							break;
					}
					break;
				case MapTileType::NONE_PORT:
				case MapTileType::RED_PORT:
				case MapTileType::BLUE_PORT:
				case MapTileType::GREEN_PORT:
				case MapTileType::YELLOW_PORT:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_PORT;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_PORT;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_PORT;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_PORT;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_PORT;
							break;
					}
					break;
				case MapTileType::NONE_AIRPORT:
				case MapTileType::RED_AIRPORT:
				case MapTileType::BLUE_AIRPORT:
				case MapTileType::GREEN_AIRPORT:
				case MapTileType::YELLOW_AIRPORT:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_AIRPORT;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_AIRPORT;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_AIRPORT;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_AIRPORT;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_AIRPORT;
							break;
					}
					break;
				case MapTileType::NONE_TOWER:
				case MapTileType::RED_TOWER:
				case MapTileType::BLUE_TOWER:
				case MapTileType::GREEN_TOWER:
				case MapTileType::YELLOW_TOWER:
					switch (team) {
						case Team::NONE:
							map.at(x).at(y) = MapTileType::NONE_TOWER;
							break;
						case Team::RED:
							map.at(x).at(y) = MapTileType::RED_TOWER;
							break;
						case Team::BLUE:
							map.at(x).at(y) = MapTileType::BLUE_TOWER;
							break;
						case Team::GREEN:
							map.at(x).at(y) = MapTileType::GREEN_TOWER;
							break;
						case Team::YELLOW:
							map.at(x).at(y) = MapTileType::YELLOW_TOWER;
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

