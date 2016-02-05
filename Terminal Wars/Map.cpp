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


	MapTileType Map::GetTile(int x, int y, bool silent) {
		try {
			return map.at(y).at(x);
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "Map::CaptureBuilding() was given a bad range (" << x << ", " << y << ")." << std::endl;
				std::cerr << oor.what() << std::endl;
			}
			return MapTileType::NONE;
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

	int Map::GetNumPlayers() {
		int totalPlayers = 0;
		bool red, blue, green, yellow = false;
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				switch (map.at(i).at(j)) {
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
		int totalBuildings, redBuildings, blueBuildings, greenBuildings, yellowBuildings = 0;
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				switch (map.at(i).at(j)) {
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
		std::vector<MapTileType> temp;

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
					temp.push_back(MapTileType::NONE);
					break;
				case 'L':
					temp.push_back(MapTileType::FOREST);
					break;
				case 'M':
					temp.push_back(MapTileType::MISSILE_SILO);
					break;
				case 'm':
					temp.push_back(MapTileType::MISSILE_SILO_USED);
					break;
				case '<':
					temp.push_back(MapTileType::MOUNTAIN);
					break;
				case 'N':
					temp.push_back(MapTileType::PIPE);
					break;
				case 'n':
					temp.push_back(MapTileType::PIPE_SEAM);
					break;
				case 'P':
					temp.push_back(MapTileType::PLAIN);
					break;
				case 'K':
					temp.push_back(MapTileType::REEF);
					break;
				case 'I':
					temp.push_back(MapTileType::RIVER);
					break;
				case 'U':
					temp.push_back(MapTileType::ROAD);
					break;
				case 'O':
					temp.push_back(MapTileType::SEA);
					break;
				case 'o':
					temp.push_back(MapTileType::SHOAL);
					break;
				case '1':
					temp.push_back(MapTileType::NONE_CITY);
					break;
				case 'Q':
					temp.push_back(MapTileType::RED_CITY);
					break;
				case 'A':
					temp.push_back(MapTileType::BLUE_CITY);
					break;
				case 'q':
					temp.push_back(MapTileType::GREEN_CITY);
					break;
				case 'a':
					temp.push_back(MapTileType::YELLOW_CITY);
					break;
				case '2':
					temp.push_back(MapTileType::NONE_HQ);
					break;
				case 'W':
					temp.push_back(MapTileType::RED_HQ);
					break;
				case 'S':
					temp.push_back(MapTileType::BLUE_HQ);
					break;
				case 'w':
					temp.push_back(MapTileType::GREEN_HQ);
					break;
				case 's':
					temp.push_back(MapTileType::YELLOW_HQ);
					break;
				case '3':
					temp.push_back(MapTileType::NONE_BASE);
					break;
				case 'E':
					temp.push_back(MapTileType::RED_BASE);
					break;
				case 'D':
					temp.push_back(MapTileType::BLUE_BASE);
					break;
				case 'e':
					temp.push_back(MapTileType::GREEN_BASE);
					break;
				case 'd':
					temp.push_back(MapTileType::YELLOW_BASE);
					break;
				case '4':
					temp.push_back(MapTileType::NONE_PORT);
					break;
				case 'R':
					temp.push_back(MapTileType::RED_PORT);
					break;
				case 'F':
					temp.push_back(MapTileType::BLUE_PORT);
					break;
				case 'r':
					temp.push_back(MapTileType::GREEN_PORT);
					break;
				case 'f':
					temp.push_back(MapTileType::YELLOW_PORT);
					break;
				case '5':
					temp.push_back(MapTileType::NONE_AIRPORT);
					break;
				case 'T':
					temp.push_back(MapTileType::RED_AIRPORT);
					break;
				case 'G':
					temp.push_back(MapTileType::BLUE_AIRPORT);
					break;
				case 't':
					temp.push_back(MapTileType::GREEN_AIRPORT);
					break;
				case 'g':
					temp.push_back(MapTileType::YELLOW_AIRPORT);
					break;
				case '6':
					temp.push_back(MapTileType::NONE_TOWER);
					break;
				case 'Y':
					temp.push_back(MapTileType::RED_TOWER);
					break;
				case 'H':
					temp.push_back(MapTileType::BLUE_TOWER);
					break;
				case 'y':
					temp.push_back(MapTileType::GREEN_TOWER);
					break;
				case 'h':
					temp.push_back(MapTileType::YELLOW_TOWER);
					break;
			}
		}

		map.push_back(temp);

		mapFile.close();
		
		height = map.size();
	}

}

