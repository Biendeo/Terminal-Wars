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
	std::map<DamageKey, BaseDamage> Data::baseDamage;

	Data::Data() {
		// TODO: Make this easier to modify.
		// TODO: Add the rest.
		mapTiles.emplace(MapTileType::NONE, MapTile(MapTileType::NONE, "None", '?',  rlutil::GREY, rlutil::BLACK, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace(MapTileType::PLAIN, MapTile(MapTileType::PLAIN, "Plain", '_', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));

		units.emplace(UnitType::NONE, UnitData(UnitType::NONE, "None", '?', rlutil::MAGENTA, 0, MovementType::NONE, 0, 0));
		units.emplace(UnitType::INFANTRY, UnitData(UnitType::INFANTRY, "Infantry", 'I', rlutil::GREY, 1000, MovementType::INFANTRY, 3, 2));

		weapons.emplace(WeaponType::NONE, Weapon(WeaponType::NONE, "None", 0, 0, 0, 0, true));
		weapons.emplace(WeaponType::M_GUN, Weapon(WeaponType::M_GUN, "Machine Gun", 1, 1, -1, 0, true));

		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::INFANTRY, false), 55);
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
			std::cerr << oor.what() << std::endl;
		}

		return GetMapTileData(MapTileType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetMapTileDataSize() {
		return int(mapTiles.size());
	}

	UnitData Data::GetUnitData(UnitType type) {
		try {
			return units.at(type);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetUnitTileData() could not find type " << static_cast<int>(type) << "." << std::endl;
			std::cerr << oor.what() << std::endl;
		}

		return GetUnitData(UnitType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetUnitDataSize() {
		return int(units.size());
	}

	Weapon Data::GetWeaponData(WeaponType type) {
		try {
			return weapons.at(type);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetWeaponData() could not find type " << static_cast<int>(type) << "." << std::endl;
			std::cerr << oor.what() << std::endl;
		}

		return GetWeaponData(WeaponType::NONE);
	}

	// TODO: When testing is done, remove this.
	int Data::GetWeaponDataSize() {
		return int(weapons.size());
	}

	BaseDamage Data::GetBaseDamage(UnitType attacker, UnitType defender, bool primary) {
		try {
			return baseDamage.at(MakeDamageKey(attacker, defender, primary));
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "GetBaseDamage() could not find " << static_cast<int>(attacker) << " attacking " << static_cast<int>(defender) << " with primary? " << primary << std::endl;
			std::cerr << oor.what() << std::endl;
		}

		return 0;
	}

	DamageKey Data::MakeDamageKey(UnitType attacker, UnitType defender, bool primary) {
		DamageKey key = 0;
		key += (2 * int(units.size()) * int(attacker));
		key += (2 * int(defender));
		if (primary) {
			key += 1;
		}
		return key;
	}
}
