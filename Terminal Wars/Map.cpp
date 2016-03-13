#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Constants.h"
#include "Data.h"
#include "Map.h"
#include "rlutil.h"

namespace TerminalWars {
	Map::Map(std::string customMap) {
		LoadCustomMap(customMap);
		int i = customMap.size() - 1;
		while (true) {
			if (customMap.at(i) == '.') {
				customMap = customMap.substr(0, i);
				--i;
			} else if (customMap.at(i) == '\\' || customMap.at(i) == '/') {
				customMap = customMap.substr(i + 1, customMap.size() - 1);
				break;
			} else if (i == 0) {
				break;
			}
			--i;
		}
		name = customMap;
	}


	Map::~Map() {
		// TODO
		for (int i = 0; i < int(map.size()); i++) {
			map.at(i).clear();
		}
		map.clear();
	}


	MapTile &Map::GetTile(int x, int y, bool silent) {
		try {
			return map.at(y).at(x).get();
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "Map::GetTile() was given a bad range (" << x << ", " << y << ")." << std::endl;
				std::cerr << oor.what() << std::endl;
			}
			return Data::GetMapTileData(MapTileType::NONE);
		}
	}

	std::string Map::GetName() {
		return name;
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
			switch (map.at(y).at(x).get().GetType()) {
				case MapTileType::NONE_CITY:
				case MapTileType::RED_CITY:
				case MapTileType::BLUE_CITY:
				case MapTileType::GREEN_CITY:
				case MapTileType::YELLOW_CITY:
					switch (team) {
						case Team::NONE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_CITY);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_CITY);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_CITY);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_CITY);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_CITY);
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
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_HQ);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_HQ);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_HQ);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_HQ);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_HQ);
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
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_BASE);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_BASE);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_BASE);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_BASE);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_BASE);
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
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_PORT);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_PORT);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_PORT);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_PORT);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_PORT);
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
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_AIRPORT);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_AIRPORT);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_AIRPORT);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_AIRPORT);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_AIRPORT);
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
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::NONE_TOWER);
							break;
						case Team::RED:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::RED_TOWER);
							break;
						case Team::BLUE:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::BLUE_TOWER);
							break;
						case Team::GREEN:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::GREEN_TOWER);
							break;
						case Team::YELLOW:
							map.at(y).at(x).get() = Data::GetMapTileData(MapTileType::YELLOW_TOWER);
							break;
					}
					break;
				default:
					std::cerr << "Map::CaptureBuilding() tried to convert an invalid " << map.at(y).at(x).get().GetName() << "." << std::endl;
					break;
			}
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Map::CaptureBuilding() was given a bad range (" << x << ", " << y << ")." << std::endl;
			std::cerr << oor.what() << std::endl;
			return;
		}
	}

	int Map::GetNumPlayers() {
		int totalPlayers = 0;
		bool red, blue, green, yellow = false;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				switch (map.at(y).at(x).get().GetType()) {
					case MapTileType::RED_HQ:
						if (!red) {
							red = true;
							++totalPlayers;
						}
						break;
					case MapTileType::BLUE_HQ:
						if (!blue) {
							blue = true;
							++totalPlayers;
						}
						break;
					case MapTileType::GREEN_HQ:
						if (!green) {
							green = true;
							++totalPlayers;
						}
						break;
					case MapTileType::YELLOW_HQ:
						if (!yellow) {
							yellow = true;
							++totalPlayers;
						}
						break;
					default:
						break;
				}
			}
		}

		return totalPlayers;
	}

	int Map::GetNumOfBuildings(Team team) {
		int totalBuildings = 0, redBuildings = 0, blueBuildings = 0, greenBuildings = 0, yellowBuildings = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				switch (map.at(y).at(x).get().GetType()) {
					case MapTileType::NONE_CITY:
					case MapTileType::NONE_HQ:
					case MapTileType::NONE_BASE:
					case MapTileType::NONE_PORT:
					case MapTileType::NONE_AIRPORT:
					case MapTileType::NONE_TOWER:
						++totalBuildings;
						break;
					case MapTileType::RED_CITY:
					case MapTileType::RED_HQ:
					case MapTileType::RED_BASE:
					case MapTileType::RED_PORT:
					case MapTileType::RED_AIRPORT:
					case MapTileType::RED_TOWER:
						++redBuildings;
						++totalBuildings;
						break;
					case MapTileType::BLUE_CITY:
					case MapTileType::BLUE_HQ:
					case MapTileType::BLUE_BASE:
					case MapTileType::BLUE_PORT:
					case MapTileType::BLUE_AIRPORT:
					case MapTileType::BLUE_TOWER:
						++blueBuildings;
						++totalBuildings;
						break;
					case MapTileType::GREEN_CITY:
					case MapTileType::GREEN_HQ:
					case MapTileType::GREEN_BASE:
					case MapTileType::GREEN_PORT:
					case MapTileType::GREEN_AIRPORT:
					case MapTileType::GREEN_TOWER:
						++greenBuildings;
						++totalBuildings;
						break;
					case MapTileType::YELLOW_CITY:
					case MapTileType::YELLOW_HQ:
					case MapTileType::YELLOW_BASE:
					case MapTileType::YELLOW_PORT:
					case MapTileType::YELLOW_AIRPORT:
					case MapTileType::YELLOW_TOWER:
						++yellowBuildings;
						++totalBuildings;
						break;
					default:
						break;
				}
			}
		}

		switch (team) {
			case Team::NONE:
			default:
				return totalBuildings;
			case Team::RED:
				return redBuildings;
			case Team::BLUE:
				return blueBuildings;
			case Team::GREEN:
				return greenBuildings;
			case Team::YELLOW:
				return yellowBuildings;
		}
	}
	
	void Map::LoadCustomMap(std::string customMap) {
		/**

		To create a custom map, create an empty text file, and use the following
		characters to indicate the map tiles. Do not include any unknown or
		extra characters, or the program might have unexpected behaviour.

		  - NONE (DO NOT INTENTIONALLY USE THIS ONE)
		L - FOREST
		M - MISSILE_SILO
		m - MISSILE_SILO_USED
		< - MOUNTAIN
		N - PIPE
		n - PIPE_SEAM
		P - PLAIN
		K - REEF
		I - RIVER
		U - ROAD
		O - SEA
		o - SHOAL
		1 - NONE_CITY
		Q - RED_CITY
		A - BLUE_CITY
		q - GREEN_CITY
		a - YELLOW_CITY
		2 - NONE_HQ
		W - RED_HQ
		S - BLUE_HQ
		w - GREEN_HQ
		s - YELLOW_HQ
		3 - NONE_BASE
		E - RED_BASE
		D - BLUE_BASE
		e - GREEN_BASE
		d - YELLOW_BASE
		4 - NONE_PORT
		R - RED_PORT
		F - BLUE_PORT
		r - GREEN_PORT
		f - YELLOW_PORT
		5 - NONE_AIRPORT
		T - RED_AIRPORT
		G - BLUE_AIRPORT
		t - GREEN_AIRPORT
		g - YELLOW_AIRPORT
		6 - NONE_TOWER
		Y - RED_TOWER
		H - BLUE_TOWER
		y - GREEN_TOWER
		h - YELLOW_TOWER

		*/

		std::ifstream mapFile;
		mapFile.open(customMap, std::ios::in);
		if (!mapFile.is_open()) {
			std::cerr << "There was an error opening " + customMap + "." << std::endl;
			exit(4);
		}

		// TODO: Clean up this process a little.
		std::vector<std::reference_wrapper<MapTile>> temp;

		char c;
		while (mapFile >> std::noskipws >> c) {
			switch (c) {
				case '\n':
					map.push_back(temp);
					width = int(temp.size());
					temp.clear();
					break;
				case ' ':
				default:
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE)));
					break;
				case 'L':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::FOREST)));
					break;
				case 'M':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::MISSILE_SILO)));
					break;
				case 'm':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::MISSILE_SILO_USED)));
					break;
				case '<':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::MOUNTAIN)));
					break;
				case 'N':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::PIPE)));
					break;
				case 'n':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::PIPE_SEAM)));
					break;
				case 'P':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::PLAIN)));
					break;
				case 'K':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::REEF)));
					break;
				case 'I':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RIVER)));
					break;
				case 'U':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::ROAD)));
					break;
				case 'O':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::SEA)));
					break;
				case 'o':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::SHOAL)));
					break;
				case '1':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_CITY)));
					break;
				case 'Q':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_CITY)));
					break;
				case 'A':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_CITY)));
					break;
				case 'q':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_CITY)));
					break;
				case 'a':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_CITY)));
					break;
				case '2':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_HQ)));
					break;
				case 'W':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_HQ)));
					break;
				case 'S':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_HQ)));
					break;
				case 'w':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_HQ)));
					break;
				case 's':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_HQ)));
					break;
				case '3':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_BASE)));
					break;
				case 'E':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_BASE)));
					break;
				case 'D':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_BASE)));
					break;
				case 'e':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_BASE)));
					break;
				case 'd':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_BASE)));
					break;
				case '4':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_PORT)));
					break;
				case 'R':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_PORT)));
					break;
				case 'F':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_PORT)));
					break;
				case 'r':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_PORT)));
					break;
				case 'f':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_PORT)));
					break;
				case '5':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_AIRPORT)));
					break;
				case 'T':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_AIRPORT)));
					break;
				case 'G':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_AIRPORT)));
					break;
				case 't':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_AIRPORT)));
					break;
				case 'g':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_AIRPORT)));
					break;
				case '6':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::NONE_TOWER)));
					break;
				case 'Y':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::RED_TOWER)));
					break;
				case 'H':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::BLUE_TOWER)));
					break;
				case 'y':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::GREEN_TOWER)));
					break;
				case 'h':
					temp.emplace_back(std::reference_wrapper<MapTile>(Data::GetMapTileData(MapTileType::YELLOW_TOWER)));
					break;
			}
		}

		map.push_back(temp);

		mapFile.close();
		
		height = map.size();
	}

}

