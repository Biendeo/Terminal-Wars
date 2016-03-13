#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include "Constants.h"
#include "Data.h"
#include "MapTile.h"
#include "rlutil.h"

namespace TerminalWars {
	std::map<MapTileType, MapTile> Data::mapTiles;
	std::map<UnitType, UnitData> Data::units;
	std::map<WeaponType, Weapon> Data::weapons;
	std::map<DamageKey, BaseDamage> Data::baseDamage;

	Data::Data() {
		std::string mapTileData = "../DataValues/MapTiles.csv";
		std::string unitData = "../DataValues/Units.csv";
		std::string weaponData = "../DataValues/Weapons.csv";
		std::string damageData = "../DataValues/Damage.csv";
		std::string currentLine;
		std::ifstream file;

		/// Map Tile Data
		file.open(mapTileData, std::ios::in);
		if (!file.is_open()) {
			std::cerr << "There was an error opening " + mapTileData + "." << std::endl;
			exit(4);
		}
		while (std::getline(file, currentLine)) {
			std::vector<std::string> splitLine = SplitLine(currentLine, ',');
			mapTiles.emplace(StringToMapTileType(splitLine.at(0)), MapTile(StringToMapTileType(splitLine.at(0)), splitLine.at(0), splitLine.at(1).at(0), StringToColor(splitLine.at(2)), StringToColor(splitLine.at(3)), std::stoi(splitLine.at(4)), std::stoi(splitLine.at(5)), std::stoi(splitLine.at(6)), std::stoi(splitLine.at(7)), std::stoi(splitLine.at(8)), std::stoi(splitLine.at(9)), std::stoi(splitLine.at(10)), std::stoi(splitLine.at(11)), std::stoi(splitLine.at(12)), std::stoi(splitLine.at(13))));
		}
		file.close();

		/// Weapon Data
		// TODO: Find the ammo cost for weapons.
		file.open(weaponData, std::ios::in);
		if (!file.is_open()) {
			std::cerr << "There was an error opening " + weaponData + "." << std::endl;
			exit(4);
		}
		while (std::getline(file, currentLine)) {
			std::vector<std::string> splitLine = SplitLine(currentLine, ',');
			weapons.emplace(StringToWeaponType(splitLine.at(0)), Weapon(StringToWeaponType(splitLine.at(0)), splitLine.at(1), std::stoi(splitLine.at(2)), std::stoi(splitLine.at(3)), std::stoi(splitLine.at(4)), std::stoi(splitLine.at(5)), (std::stoi(splitLine.at(6)) != 0)));
		}
		file.close();

		/// Unit Data
		file.open(unitData, std::ios::in);
		if (!file.is_open()) {
			std::cerr << "There was an error opening " + unitData + "." << std::endl;
			exit(4);
		}
		while (std::getline(file, currentLine)) {
			std::vector<std::string> splitLine = SplitLine(currentLine, ',');
			units.emplace(StringToUnitType(splitLine.at(0)), UnitData(StringToUnitType(splitLine.at(0)), splitLine.at(0), splitLine.at(1).at(0), std::stoi(splitLine.at(2)), StringToMovementType(splitLine.at(3)), std::stoi(splitLine.at(4)), std::stoi(splitLine.at(5)), std::stoi(splitLine.at(6)), GetWeaponData(StringToWeaponType(splitLine.at(7))), GetWeaponData(StringToWeaponType(splitLine.at(8)))));
		}
		file.close();

		/// Damage Data
		file.open(damageData, std::ios::in);
		if (!file.is_open()) {
			std::cerr << "There was an error opening " + damageData + "." << std::endl;
			exit(4);
		}
		while (std::getline(file, currentLine)) {
			std::vector<std::string> splitLine = SplitLine(currentLine, ',');
			baseDamage.emplace(MakeDamageKey(StringToUnitType(splitLine.at(0)), StringToUnitType(splitLine.at(1)), std::stoi(splitLine.at(2)) != 0), std::stoi(splitLine.at(3)));
		}
		file.close();
	}

	Data::~Data() {
		mapTiles.clear();
	}

	MapTile &Data::GetMapTileData(MapTileType type, bool silent) {
		try {
			return mapTiles.at(type);
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "GetMapTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
				std::cerr << oor.what() << std::endl;
			}
		}

		return GetMapTileData(MapTileType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetMapTileDataSize() {
		return int(mapTiles.size());
	}

	UnitData &Data::GetUnitData(UnitType type, bool silent) {
		try {
			return units.at(type);
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "GetUnitTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
				std::cerr << oor.what() << std::endl;
			}
		}

		return GetUnitData(UnitType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetUnitDataSize() {
		return int(units.size());
	}

	Weapon &Data::GetWeaponData(WeaponType type, bool silent) {
		try {
			return weapons.at(type);
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "GetWeaponData() could not find type " << static_cast<int>(type) << "." << std::endl;
				std::cerr << oor.what() << std::endl;
			}
		}

		return GetWeaponData(WeaponType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetWeaponDataSize() {
		return int(weapons.size());
	}

	BaseDamage Data::GetBaseDamage(UnitType attacker, UnitType defender, bool primary, bool silent) {
		try {
			return baseDamage.at(MakeDamageKey(attacker, defender, primary));
		}
		catch (const std::out_of_range& oor) {
			if (!silent) {
				std::cerr << "GetBaseDamage() could not find " << static_cast<int>(attacker) << " attacking " << static_cast<int>(defender) << " with primary? " << primary << std::endl;
				std::cerr << oor.what() << std::endl;
			}
		}

		return 0;
	}

	DamageKey Data::MakeDamageKey(UnitType attacker, UnitType defender, bool primary) {
		DamageKey key = 0;
		key += (2 * int(units.size()) * static_cast<int>(attacker));
		key += (2 * static_cast<int>(defender));
		if (primary) {
			key += 1;
		}
		return key;
	}

	MapTileType Data::StringToMapTileType(std::string str) {
		if (str == "None") {
			return MapTileType::NONE;
		} else if (str == "Forest") {
			return MapTileType::FOREST;
		} else if (str == "Missile Silo") {
			return MapTileType::MISSILE_SILO;
		} else if (str == "Used Missile Silo") {
			return MapTileType::MISSILE_SILO_USED;
		} else if (str == "Mountain") {
			return MapTileType::MOUNTAIN;
		} else if (str == "Pipe") {
			return MapTileType::PIPE;
		} else if (str == "Pipe Seam") {
			return MapTileType::PIPE_SEAM;
		} else if (str == "Plain") {
			return MapTileType::PLAIN;
		} else if (str == "Reef") {
			return MapTileType::REEF;
		} else if (str == "River") {
			return MapTileType::RIVER;
		} else if (str == "Road") {
			return MapTileType::ROAD;
		} else if (str == "Sea") {
			return MapTileType::SEA;
		} else if (str == "Shoal") {
			return MapTileType::SHOAL;
		} else if (str == "Unoccupied City") {
			return MapTileType::NONE_CITY;
		} else if (str == "Red City") {
			return MapTileType::RED_CITY;
		} else if (str == "Blue City") {
			return MapTileType::BLUE_CITY;
		} else if (str == "Green City") {
			return MapTileType::GREEN_CITY;
		} else if (str == "Yellow City") {
			return MapTileType::YELLOW_CITY;
		} else if (str == "Unoccupied HQ") {
			return MapTileType::NONE_HQ;
		} else if (str == "Red HQ") {
			return MapTileType::RED_HQ;
		} else if (str == "Blue HQ") {
			return MapTileType::BLUE_HQ;
		} else if (str == "Green HQ") {
			return MapTileType::GREEN_HQ;
		} else if (str == "Yellow HQ") {
			return MapTileType::YELLOW_HQ;
		} else if (str == "Unoccupied Base") {
			return MapTileType::NONE_BASE;
		} else if (str == "Red Base") {
			return MapTileType::RED_BASE;
		} else if (str == "Blue Base") {
			return MapTileType::BLUE_BASE;
		} else if (str == "Green Base") {
			return MapTileType::GREEN_BASE;
		} else if (str == "Yellow Base") {
			return MapTileType::YELLOW_BASE;
		} else if (str == "Unoccupied Port") {
			return MapTileType::NONE_PORT;
		} else if (str == "Red Port") {
			return MapTileType::RED_PORT;
		} else if (str == "Blue Port") {
			return MapTileType::BLUE_PORT;
		} else if (str == "Green Port") {
			return MapTileType::GREEN_PORT;
		} else if (str == "Yellow Port") {
			return MapTileType::YELLOW_PORT;
		} else if (str == "Unoccupied Airport") {
			return MapTileType::NONE_AIRPORT;
		} else if (str == "Red Airport") {
			return MapTileType::RED_AIRPORT;
		} else if (str == "Blue Airport") {
			return MapTileType::BLUE_AIRPORT;
		} else if (str == "Green Airport") {
			return MapTileType::GREEN_AIRPORT;
		} else if (str == "Yellow Airport") {
			return MapTileType::YELLOW_AIRPORT;
		} else if (str == "Unoccupied Tower") {
			return MapTileType::NONE_TOWER;
		} else if (str == "Red Tower") {
			return MapTileType::RED_TOWER;
		} else if (str == "Blue Tower") {
			return MapTileType::BLUE_TOWER;
		} else if (str == "Green Tower") {
			return MapTileType::GREEN_TOWER;
		} else if (str == "Yellow Tower") {
			return MapTileType::YELLOW_TOWER;
		}
		return MapTileType::NONE;
	}

	UnitType Data::StringToUnitType(std::string str) {
		if (str == "None") {
			return UnitType::NONE;
		} else if (str == "Infantry") {
			return UnitType::INFANTRY;
		} else if (str == "Mech") {
			return UnitType::MECH;
		} else if (str == "Recon") {
			return UnitType::RECON;
		} else if (str == "Tank") {
			return UnitType::TANK;
		} else if (str == "MD Tank") {
			return UnitType::MD_TANK;
		} else if (str == "Neotank") {
			return UnitType::NEOTANK;
		} else if (str == "Megatank") {
			return UnitType::MEGATANK;
		} else if (str == "APC") {
			return UnitType::APC;
		} else if (str == "Artillery") {
			return UnitType::ARTILLERY;
		} else if (str == "Rockets") {
			return UnitType::ROCKETS;
		} else if (str == "Anti-Air") {
			return UnitType::ANTI_AIR;
		} else if (str == "Missiles") {
			return UnitType::MISSILES;
		} else if (str == "Piperunner") {
			return UnitType::PIPERUNNER;
		} else if (str == "Oozium") {
			return UnitType::OOZIUM;
		} else if (str == "Battleship") {
			return UnitType::BATTLESHIP;
		} else if (str == "Cruiser") {
			return UnitType::CRUISER;
		} else if (str == "Lander") {
			return UnitType::LANDER;
		} else if (str == "Submarine") {
			return UnitType::SUB;
		} else if (str == "Black Boat") {
			return UnitType::BLACK_BOAT;
		} else if (str == "Carrier") {
			return UnitType::CARRIER;
		} else if (str == "Fighter") {
			return UnitType::FIGHTER;
		} else if (str == "Bomber") {
			return UnitType::BOMBER;
		} else if (str == "Battle Copter") {
			return UnitType::B_COPTER;
		} else if (str == "Transport Copter") {
			return UnitType::T_COPTER;
		} else if (str == "Stealth") {
			return UnitType::STEALTH;
		} else if (str == "Black Bomb") {
			return UnitType::BLACK_BOMB;
		}
		return UnitType::NONE;
	}

	MovementType Data::StringToMovementType(std::string str) {
		if (str == "NONE") {
			return MovementType::NONE;
		} else if (str == "INFANTRY") {
			return MovementType::INFANTRY;
		} else if (str == "MECH") {
			return MovementType::MECH;
		} else if (str == "TIRES") {
			return MovementType::TIRES;
		} else if (str == "TREAD") {
			return MovementType::TREAD;
		} else if (str == "PIPE") {
			return MovementType::PIPE;
		} else if (str == "SLIME") {
			return MovementType::SLIME;
		} else if (str == "SHIP") {
			return MovementType::SHIP;
		} else if (str == "TRANSPORT") {
			return MovementType::TRANSPORT;
		} else if (str == "AIR") {
			return MovementType::AIR;
		}
		return MovementType::NONE;
	}

	WeaponType Data::StringToWeaponType(std::string str) {
		if (str == "NONE") {
			return WeaponType::NONE;
		} else if (str == "M_GUN") {
			return WeaponType::M_GUN;
		} else if (str == "BAZOOKA") {
			return WeaponType::BAZOOKA;
		} else if (str == "T_CANNON") {
			return WeaponType::T_CANNON;
		} else if (str == "MD_CANNON") {
			return WeaponType::MD_CANNON;
		} else if (str == "NEO_CANNON") {
			return WeaponType::NEO_CANNON;
		} else if (str == "MEGA_CANNON") {
			return WeaponType::MEGA_CANNON;
		} else if (str == "ART_CANNON") {
			return WeaponType::ART_CANNON;
		} else if (str == "ROCKETS") {
			return WeaponType::ROCKETS;
		} else if (str == "VULCAN") {
			return WeaponType::VULCAN;
		} else if (str == "G_MISSILES") {
			return WeaponType::G_MISSILES;
		} else if (str == "PIPE") {
			return WeaponType::PIPE;
		} else if (str == "F_MISSILES") {
			return WeaponType::F_MISSILES;
		} else if (str == "BOMBS") {
			return WeaponType::BOMBS;
		} else if (str == "COP_MISSILES") {
			return WeaponType::COP_MISSILES;
		} else if (str == "OMNIMISSILES") {
			return WeaponType::OMNIMISSILES;
		} else if (str == "BSHIP_CANNON") {
			return WeaponType::BSHIP_CANNON;
		} else if (str == "CRU_MISSILES") {
			return WeaponType::CRU_MISSILES;
		} else if (str == "CRU_AA") {
			return WeaponType::CRU_AA;
		} else if (str == "TORPEDOS") {
			return WeaponType::TORPEDOS;
		} else if (str == "CAR_MISSILES") {
			return WeaponType::CAR_MISSILES;
		}
		return WeaponType::NONE;
	}

	Color Data::StringToColor(std::string str) {
		if (str == "BLACK") {
			return rlutil::BLACK;
		} else if (str == "BLUE") {
			return rlutil::BLUE;
		} else if (str == "GREEN") {
			return rlutil::GREEN;
		} else if (str == "CYAN") {
			return rlutil::CYAN;
		} else if (str == "RED") {
			return rlutil::RED;
		} else if (str == "MAGENTA") {
			return rlutil::MAGENTA;
		} else if (str == "BROWN") {
			return rlutil::BROWN;
		} else if (str == "GREY") {
			return rlutil::GREY;
		} else if (str == "DARKGREY") {
			return rlutil::DARKGREY;
		} else if (str == "LIGHTBLUE") {
			return rlutil::LIGHTBLUE;
		} else if (str == "LIGHTGREEN") {
			return rlutil::LIGHTGREEN;
		} else if (str == "LIGHTCYAN") {
			return rlutil::LIGHTCYAN;
		} else if (str == "LIGHTRED") {
			return rlutil::LIGHTRED;
		} else if (str == "LIGHTMAGENTA") {
			return rlutil::LIGHTMAGENTA;
		} else if (str == "YELLOW") {
			return rlutil::YELLOW;
		} else if (str == "WHITE") {
			return rlutil::WHITE;
		}
		return rlutil::GREY;
	}

	std::vector<std::string> Data::SplitLine(std::string line, char delimiter) {
		std::vector<std::string> returnVec;
		int i = 0;
		int lastDelimiter = -1;
		bool inQuotes = false;
		// TODO: Work in double double quotes (not required, but it'll make this code reusable).
		for (char c : line) {
			if (c == delimiter && !inQuotes) {
				std::string subLine = line.substr(lastDelimiter + 1, i - lastDelimiter - 1);
				if (subLine.front() == '"' && subLine.back() == '"') {
					subLine.erase(0, 1);
					subLine.erase(subLine.size() - 1, 1);
				}
				returnVec.push_back(subLine);
				lastDelimiter = i;
			} else if (c == '"') {
				if (inQuotes) {
					inQuotes = false;
				} else {
					inQuotes = true;
				}
			}
			++i;
		}
		if (lastDelimiter != i - 1) {
			returnVec.push_back(line.substr(lastDelimiter + 1, i - lastDelimiter - 1));
		}
		return returnVec;
	}
}
