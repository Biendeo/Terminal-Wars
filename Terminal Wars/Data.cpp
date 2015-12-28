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
		mapTiles.emplace(MapTileType::NONE, MapTile(MapTileType::NONE, "None", '?', rlutil::GREY, rlutil::BLACK, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
		mapTiles.emplace(MapTileType::FOREST, MapTile(MapTileType::FOREST, "Forest", '+', rlutil::BROWN, rlutil::GREEN, 1, 1, 3, 2, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::MISSILE_SILO, MapTile(MapTileType::MISSILE_SILO, "Missile Silo", '|', rlutil::WHITE, rlutil::DARKGREY, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::MISSILE_SILO_USED, MapTile(MapTileType::MISSILE_SILO_USED, "Used Missile Silo", '.', rlutil::WHITE, rlutil::DARKGREY, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::MOUNTAIN, MapTile(MapTileType::MOUNTAIN, "Mountain", '^', rlutil::GREY, rlutil::DARKGREY, 2, 1, 0, 0, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::PIPE, MapTile(MapTileType::PIPE, "Pipe", '=', rlutil::GREY, rlutil::GREEN, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0));
		mapTiles.emplace(MapTileType::PIPE_SEAM, MapTile(MapTileType::PIPE_SEAM, "Pipe Seam", '-', rlutil::GREY, rlutil::GREEN, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0));
		mapTiles.emplace(MapTileType::PLAIN, MapTile(MapTileType::PLAIN, "Plain", ' ', rlutil::GREEN, rlutil::GREEN, 1, 1, 2, 1, 0, 1, 0, 0, 1, 1));
		mapTiles.emplace(MapTileType::REEF, MapTile(MapTileType::REEF, "Reef", ',', rlutil::GREY, rlutil::BLUE, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1));
		mapTiles.emplace(MapTileType::RIVER, MapTile(MapTileType::RIVER, "River", '_', rlutil::GREEN, rlutil::BLUE, 2, 1, 0, 0, 0, 1, 0, 0, 1, 0));
		mapTiles.emplace(MapTileType::ROAD, MapTile(MapTileType::ROAD, "Road", '=', rlutil::WHITE, rlutil::GREY, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0));
		mapTiles.emplace(MapTileType::SEA, MapTile(MapTileType::SEA, "Sea", ' ', rlutil::BLUE, rlutil::BLUE, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0));
		mapTiles.emplace(MapTileType::SHOAL, MapTile(MapTileType::SHOAL, "Shoal", '_', rlutil::BLUE, rlutil::BROWN, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0));
		mapTiles.emplace(MapTileType::NONE_CITY, MapTile(MapTileType::NONE_CITY, "Unoccupied City", '$', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::RED_CITY, MapTile(MapTileType::RED_CITY, "Red City", '$', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::BLUE_CITY, MapTile(MapTileType::BLUE_CITY, "Blue City", '$', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::GREEN_CITY, MapTile(MapTileType::GREEN_CITY, "Green City", '$', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::YELLOW_CITY, MapTile(MapTileType::YELLOW_CITY, "Yellow City", '$', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::NONE_HQ, MapTile(MapTileType::NONE_HQ, "Unoccupied HQ", '@', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::RED_HQ, MapTile(MapTileType::RED_HQ, "Red HQ", '@', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::BLUE_HQ, MapTile(MapTileType::BLUE_HQ, "Blue HQ", '@', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::GREEN_HQ, MapTile(MapTileType::GREEN_HQ, "Green HQ", '@', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::YELLOW_HQ, MapTile(MapTileType::YELLOW_HQ, "Yellow HQ", '@', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 4));
		mapTiles.emplace(MapTileType::NONE_BASE, MapTile(MapTileType::NONE_BASE, "Unoccupied Base", '&', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::RED_BASE, MapTile(MapTileType::RED_BASE, "Red Base", '&', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::BLUE_BASE, MapTile(MapTileType::BLUE_BASE, "Blue Base", '&', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::GREEN_BASE, MapTile(MapTileType::GREEN_BASE, "Green Base", '&', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::YELLOW_BASE, MapTile(MapTileType::YELLOW_BASE, "Yellow Base", '&', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::NONE_PORT, MapTile(MapTileType::NONE_PORT, "Unoccupied Port", '%', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::RED_PORT, MapTile(MapTileType::RED_PORT, "Red Port", '%', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::BLUE_PORT, MapTile(MapTileType::BLUE_PORT, "Blue Port", '%', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::GREEN_PORT, MapTile(MapTileType::GREEN_PORT, "Green Port", '%', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::YELLOW_PORT, MapTile(MapTileType::YELLOW_PORT, "Yellow Port", '%', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::NONE_AIRPORT, MapTile(MapTileType::NONE_AIRPORT, "Unoccupied Airport", 'A', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::RED_AIRPORT, MapTile(MapTileType::RED_AIRPORT, "Red Airport", 'A', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::BLUE_AIRPORT, MapTile(MapTileType::BLUE_AIRPORT, "Blue Airport", 'A', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::GREEN_AIRPORT, MapTile(MapTileType::GREEN_AIRPORT, "Green Airport", 'A', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::YELLOW_AIRPORT, MapTile(MapTileType::YELLOW_AIRPORT, "Yellow Airport", 'A', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::NONE_TOWER, MapTile(MapTileType::NONE_TOWER, "Unoccupied Tower", '!', rlutil::WHITE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::RED_TOWER, MapTile(MapTileType::RED_TOWER, "Red Tower", '!', rlutil::LIGHTRED, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::BLUE_TOWER, MapTile(MapTileType::BLUE_TOWER, "Blue Tower", '!', rlutil::LIGHTBLUE, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::GREEN_TOWER, MapTile(MapTileType::GREEN_TOWER, "Green Tower", '!', rlutil::LIGHTGREEN, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));
		mapTiles.emplace(MapTileType::YELLOW_TOWER, MapTile(MapTileType::YELLOW_TOWER, "Yellow Tower", '!', rlutil::YELLOW, rlutil::GREEN, 1, 1, 1, 1, 0, 1, 0, 0, 1, 3));

		// TODO: Find the ammo cost for all of these.
		weapons.emplace(WeaponType::NONE, Weapon(WeaponType::NONE, "None", 0, 0, 0, 0, true));
		weapons.emplace(WeaponType::M_GUN, Weapon(WeaponType::M_GUN, "Machine Gun", 1, 1, -1, 0, true));
		weapons.emplace(WeaponType::BAZOOKA, Weapon(WeaponType::BAZOOKA, "Bazooka", 1, 1, 3, 5, true));
		weapons.emplace(WeaponType::T_CANNON, Weapon(WeaponType::T_CANNON, "Cannon", 1, 1, 9, 5, true));
		weapons.emplace(WeaponType::MD_CANNON, Weapon(WeaponType::MD_CANNON, "Cannon", 1, 1, 8, 5, true));
		weapons.emplace(WeaponType::NEO_CANNON, Weapon(WeaponType::NEO_CANNON, "New Cannon", 1, 1, 9, 5, true));
		weapons.emplace(WeaponType::MEGA_CANNON, Weapon(WeaponType::MEGA_CANNON, "Mega Cannon", 1, 1, 3, 10, true));
		weapons.emplace(WeaponType::ART_CANNON, Weapon(WeaponType::ART_CANNON, "Cannon", 2, 3, 9, 5, false));
		weapons.emplace(WeaponType::ROCKETS, Weapon(WeaponType::ROCKETS, "Rockets", 3, 5, 6, 5, false));
		weapons.emplace(WeaponType::VULCAN, Weapon(WeaponType::VULCAN, "Vulcan", 1, 1, 9, 5, true));
		weapons.emplace(WeaponType::G_MISSILES, Weapon(WeaponType::G_MISSILES, "Missiles", 3, 5, 6, 5, true));
		weapons.emplace(WeaponType::PIPE, Weapon(WeaponType::PIPE, "Pipe Gun", 2, 5, 9, 5, false));
		weapons.emplace(WeaponType::F_MISSILES, Weapon(WeaponType::F_MISSILES, "Missiles", 1, 1, 9, 5, true));
		weapons.emplace(WeaponType::BOMBS, Weapon(WeaponType::BOMBS, "Bombs", 1, 1, 9, 5, true));
		weapons.emplace(WeaponType::COP_MISSILES, Weapon(WeaponType::COP_MISSILES, "Missiles", 1, 1, 6, 5, true));
		weapons.emplace(WeaponType::OMNIMISSILES, Weapon(WeaponType::OMNIMISSILES, "Omnimissiles", 1, 1, 6, 5, true));
		weapons.emplace(WeaponType::BSHIP_CANNON, Weapon(WeaponType::BSHIP_CANNON, "Cannon", 2, 6, 6, 5, false));
		weapons.emplace(WeaponType::CRU_MISSILES, Weapon(WeaponType::CRU_MISSILES, "Missiles", 1, 1, 6, 5, true));
		weapons.emplace(WeaponType::CRU_AA, Weapon(WeaponType::CRU_AA, "Anti-Air Gun", 1, 1, -1, 0, true));
		weapons.emplace(WeaponType::TORPEDOS, Weapon(WeaponType::TORPEDOS, "Torpedoes", 1, 1, 6, 5, true));
		weapons.emplace(WeaponType::CAR_MISSILES, Weapon(WeaponType::CAR_MISSILES, "Anti-Air Missiles", 3, 8, 9, 5, false));

		units.emplace(UnitType::NONE, UnitData(UnitType::NONE, "None", '?', 0, MovementType::NONE, 0, 0, 0, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::INFANTRY, UnitData(UnitType::INFANTRY, "Infantry", 'i', 1000, MovementType::INFANTRY, 3, 99, 2, WeaponType::M_GUN, WeaponType::NONE));
		units.emplace(UnitType::MECH, UnitData(UnitType::MECH, "Mech", 'm', 3000, MovementType::MECH, 2, 70, 2, WeaponType::BAZOOKA, WeaponType::M_GUN));
		units.emplace(UnitType::RECON, UnitData(UnitType::RECON, "Recon", 'r', 8000, MovementType::TIRES, 8, 80, 5, WeaponType::M_GUN, WeaponType::NONE));
		units.emplace(UnitType::TANK, UnitData(UnitType::TANK, "Tank", 'T', 7000, MovementType::TREAD, 6, 70, 3, WeaponType::T_CANNON, WeaponType::M_GUN));
		units.emplace(UnitType::MD_TANK, UnitData(UnitType::MD_TANK, "MD Tank", 'D', 16000, MovementType::TREAD, 5, 50, 1, WeaponType::MD_CANNON, WeaponType::M_GUN));
		units.emplace(UnitType::NEOTANK, UnitData(UnitType::NEOTANK, "Neotank", 'N', 22000, MovementType::TREAD, 6, 99, 1, WeaponType::NEO_CANNON, WeaponType::M_GUN));
		units.emplace(UnitType::MEGATANK, UnitData(UnitType::MEGATANK, "Megatank", 'M', 28000, MovementType::TREAD, 4, 70, 1, WeaponType::MEGA_CANNON, WeaponType::M_GUN));
		units.emplace(UnitType::APC, UnitData(UnitType::APC, "APC", 'P', 5000, MovementType::TREAD, 6, 70, 1, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::ARTILLERY, UnitData(UnitType::ARTILLERY, "Artillery", 't', 6000, MovementType::TREAD, 5, 50, 1, WeaponType::ART_CANNON, WeaponType::NONE));
		units.emplace(UnitType::ROCKETS, UnitData(UnitType::ROCKETS, "Rockets", 'R', 15000, MovementType::TIRES, 5, 50, 1, WeaponType::ROCKETS, WeaponType::NONE));
		units.emplace(UnitType::ANTI_AIR, UnitData(UnitType::ANTI_AIR, "Anti-Air", 'a', 8000, MovementType::TREAD, 6, 60, 2, WeaponType::VULCAN, WeaponType::NONE));
		units.emplace(UnitType::MISSILES, UnitData(UnitType::MISSILES, "Missiles", 's', 8000, MovementType::TIRES, 4, 50, 5, WeaponType::G_MISSILES, WeaponType::NONE));
		units.emplace(UnitType::PIPERUNNER, UnitData(UnitType::PIPERUNNER, "Piperunner", 'p', 8000, MovementType::PIPE, 9, 99, 4, WeaponType::PIPE, WeaponType::NONE));
		units.emplace(UnitType::OOZIUM, UnitData(UnitType::OOZIUM, "Oozium", 'o', 0, MovementType::SLIME, 1, -1, 1, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::BATTLESHIP, UnitData(UnitType::BATTLESHIP, "Battleship", 'B', 28000, MovementType::SHIP, 5, 99, 2, WeaponType::BSHIP_CANNON, WeaponType::NONE));
		units.emplace(UnitType::CRUISER, UnitData(UnitType::CRUISER, "Cruiser", 'C', 18000, MovementType::SHIP, 6, 99, 3, WeaponType::CRU_MISSILES, WeaponType::CRU_AA));
		units.emplace(UnitType::LANDER, UnitData(UnitType::LANDER, "Lander", 'L', 12000, MovementType::TRANSPORT, 6, 99, 1, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::SUB, UnitData(UnitType::SUB, "Submarine", 'S', 20000, MovementType::SHIP, 5, 60, 5, WeaponType::TORPEDOS, WeaponType::NONE));
		units.emplace(UnitType::BLACK_BOAT, UnitData(UnitType::BLACK_BOAT, "Black Boat", 'b', 7500, MovementType::TRANSPORT, 7, 60, 1, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::CARRIER, UnitData(UnitType::CARRIER, "Carrier", 'c', 30000, MovementType::SHIP, 5, 99, 4, WeaponType::CAR_MISSILES, WeaponType::NONE));
		units.emplace(UnitType::FIGHTER, UnitData(UnitType::FIGHTER, "Fighter", 'F', 20000, MovementType::AIR, 9, 99, 2, WeaponType::F_MISSILES, WeaponType::NONE));
		units.emplace(UnitType::BOMBER, UnitData(UnitType::BOMBER, "Bomber", 'B', 22000, MovementType::AIR, 7, 99, 2, WeaponType::BOMBS, WeaponType::NONE));
		units.emplace(UnitType::B_COPTER, UnitData(UnitType::B_COPTER, "Battle Copter", 'l', 9000, MovementType::AIR, 6, 99, 3, WeaponType::COP_MISSILES, WeaponType::NONE));
		units.emplace(UnitType::T_COPTER, UnitData(UnitType::T_COPTER, "Transport Copter", 'n', 5000, MovementType::AIR, 6, 99, 2, WeaponType::NONE, WeaponType::NONE));
		units.emplace(UnitType::STEALTH, UnitData(UnitType::STEALTH, "Stealth", 'E', 5000, MovementType::AIR, 6, 60, 4, WeaponType::OMNIMISSILES, WeaponType::NONE));
		units.emplace(UnitType::BLACK_BOMB, UnitData(UnitType::BLACK_BOMB, "Black Bomb", 'B', 25000, MovementType::AIR, 9, 45, 1, WeaponType::NONE, WeaponType::NONE));

		// TODO: Damage.
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::INFANTRY, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::MECH, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::RECON, true), 12);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::TANK, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::MD_TANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::NEOTANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::MEGATANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::ANTI_AIR, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::ARTILLERY, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::ROCKETS, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::PIPERUNNER, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::MISSILES, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::APC, true), 14);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::OOZIUM, true), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::B_COPTER, true), 7);
		baseDamage.emplace(MakeDamageKey(UnitType::INFANTRY, UnitType::T_COPTER, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::INFANTRY, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MECH, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::RECON, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::RECON, false), 18);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::TANK, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MD_TANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::NEOTANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MEGATANK, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ANTI_AIR, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ANTI_AIR, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ARTILLERY, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ARTILLERY, false), 32);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::ROCKETS, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::PIPERUNNER, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::PIPERUNNER, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MISSILES, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::MISSILES, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::APC, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::APC, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::OOZIUM, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::OOZIUM, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::B_COPTER, false), 9);
		baseDamage.emplace(MakeDamageKey(UnitType::MECH, UnitType::T_COPTER, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::INFANTRY, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::MECH, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::RECON, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::TANK, true), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::MD_TANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::NEOTANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::MEGATANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::ANTI_AIR, true), 4);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::ARTILLERY, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::ROCKETS, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::PIPERUNNER, true), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::MISSILES, true), 28);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::APC, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::OOZIUM, true), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::B_COPTER, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::RECON, UnitType::T_COPTER, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::INFANTRY, false), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MECH, false), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::RECON, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::RECON, false), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::TANK, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MD_TANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::NEOTANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MEGATANK, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ANTI_AIR, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ANTI_AIR, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ARTILLERY, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ARTILLERY, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::ROCKETS, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::PIPERUNNER, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::PIPERUNNER, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MISSILES, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::MISSILES, false), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::APC, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::APC, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::OOZIUM, true), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::OOZIUM, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::B_COPTER, false), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::T_COPTER, false), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::CRUISER, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::SUB, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::BATTLESHIP, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::CARRIER, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::LANDER, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::TANK, UnitType::BLACK_BOAT, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::INFANTRY, false), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MECH, false), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::RECON, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::RECON, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::TANK, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::TANK, false), 8);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MD_TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::NEOTANK, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MEGATANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ANTI_AIR, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ANTI_AIR, false), 7);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ARTILLERY, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ARTILLERY, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ROCKETS, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::ROCKETS, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::PIPERUNNER, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::PIPERUNNER, false), 8);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MISSILES, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::MISSILES, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::APC, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::APC, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::OOZIUM, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::OOZIUM, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::B_COPTER, false), 12);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::T_COPTER, false), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::CRUISER, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::SUB, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::BATTLESHIP, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::CARRIER, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::LANDER, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::MD_TANK, UnitType::BLACK_BOAT, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::INFANTRY, false), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MECH, false), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::RECON, true), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::RECON, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::TANK, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::TANK, false), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MD_TANK, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::NEOTANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MEGATANK, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ANTI_AIR, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ANTI_AIR, false), 17);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ARTILLERY, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ARTILLERY, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ROCKETS, true), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::ROCKETS, false), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::PIPERUNNER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::PIPERUNNER, false), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MISSILES, true), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::MISSILES, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::APC, true), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::APC, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::OOZIUM, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::OOZIUM, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::B_COPTER, false), 22);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::T_COPTER, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::CRUISER, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::SUB, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::BATTLESHIP, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::CARRIER, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::LANDER, true), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::NEOTANK, UnitType::BLACK_BOAT, true), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::INFANTRY, false), 135);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MECH, false), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::RECON, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::RECON, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::TANK, true), 180);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::TANK, false), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MD_TANK, true), 125);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::NEOTANK, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MEGATANK, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ANTI_AIR, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ANTI_AIR, false), 17);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ARTILLERY, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ARTILLERY, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ROCKETS, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::ROCKETS, false), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::PIPERUNNER, true), 180);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::PIPERUNNER, false), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MISSILES, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::MISSILES, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::APC, true), 195);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::APC, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::OOZIUM, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::OOZIUM, false), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::B_COPTER, false), 22);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::T_COPTER, false), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::CRUISER, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::SUB, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::BATTLESHIP, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::CARRIER, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::LANDER, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::MEGATANK, UnitType::BLACK_BOAT, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::INFANTRY, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::MECH, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::RECON, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::TANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::MD_TANK, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::NEOTANK, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::MEGATANK, true), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::ANTI_AIR, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::ARTILLERY, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::ROCKETS, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::PIPERUNNER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::MISSILES, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::APC, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::OOZIUM, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::FIGHTER, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::BOMBER, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::STEALTH, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::B_COPTER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::T_COPTER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::ANTI_AIR, UnitType::BLACK_BOMB, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::INFANTRY, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::MECH, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::RECON, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::TANK, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::MD_TANK, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::NEOTANK, true), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::MEGATANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::ANTI_AIR, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::ARTILLERY, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::ROCKETS, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::PIPERUNNER, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::MISSILES, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::APC, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::OOZIUM, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::CRUISER, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::SUB, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::BATTLESHIP, true), 40);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::CARRIER, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::LANDER, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ARTILLERY, UnitType::BLACK_BOAT, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::INFANTRY, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::MECH, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::RECON, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::TANK, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::MD_TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::NEOTANK, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::MEGATANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::ANTI_AIR, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::ARTILLERY, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::PIPERUNNER, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::MISSILES, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::APC, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::OOZIUM, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::CRUISER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::SUB, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::BATTLESHIP, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::CARRIER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::LANDER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::ROCKETS, UnitType::BLACK_BOAT, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::INFANTRY, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::MECH, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::RECON, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::TANK, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::MD_TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::NEOTANK, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::MEGATANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::ANTI_AIR, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::ARTILLERY, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::PIPERUNNER, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::MISSILES, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::APC, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::OOZIUM, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::FIGHTER, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::BOMBER, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::STEALTH, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::B_COPTER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::T_COPTER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::BLACK_BOMB, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::CRUISER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::SUB, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::BATTLESHIP, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::CARRIER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::LANDER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::PIPERUNNER, UnitType::BLACK_BOAT, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::FIGHTER, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::BOMBER, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::STEALTH, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::B_COPTER, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::T_COPTER, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::MISSILES, UnitType::BLACK_BOMB, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::FIGHTER, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::BOMBER, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::STEALTH, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::B_COPTER, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::T_COPTER, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::FIGHTER, UnitType::BLACK_BOMB, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::INFANTRY, true), 110);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::MECH, true), 110);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::RECON, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::TANK, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::MD_TANK, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::NEOTANK, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::MEGATANK, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::ANTI_AIR, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::ARTILLERY, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::ROCKETS, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::PIPERUNNER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::MISSILES, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::APC, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::OOZIUM, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::CRUISER, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::SUB, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::BATTLESHIP, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::CARRIER, true), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::LANDER, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BOMBER, UnitType::BLACK_BOAT, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::INFANTRY, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::MECH, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::RECON, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::TANK, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::MD_TANK, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::NEOTANK, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::MEGATANK, true), 15);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::ANTI_AIR, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::ARTILLERY, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::PIPERUNNER, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::MISSILES, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::APC, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::OOZIUM, true), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::FIGHTER, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::BOMBER, true), 70);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::STEALTH, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::B_COPTER, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::T_COPTER, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::BLACK_BOMB, true), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::CRUISER, true), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::SUB, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::BATTLESHIP, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::CARRIER, true), 45);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::LANDER, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::STEALTH, UnitType::BLACK_BOAT, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::INFANTRY, false), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MECH, false), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::RECON, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::RECON, false), 30);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::TANK, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::TANK, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MD_TANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MD_TANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::NEOTANK, true), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::NEOTANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MEGATANK, true), 10);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MEGATANK, false), 1);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ANTI_AIR, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ANTI_AIR, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ARTILLERY, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ARTILLERY, false), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ROCKETS, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::ROCKETS, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::PIPERUNNER, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::PIPERUNNER, false), 6);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MISSILES, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::MISSILES, false), 35);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::APC, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::APC, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::OOZIUM, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::OOZIUM, false), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::B_COPTER, false), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::T_COPTER, false), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::CRUISER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::SUB, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::BATTLESHIP, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::CARRIER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::LANDER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::B_COPTER, UnitType::BLACK_BOAT, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::FIGHTER, false), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::BOMBER, false), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::STEALTH, false), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::B_COPTER, false), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::T_COPTER, false), 105);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::BLACK_BOMB, false), 120);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::CRUISER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::SUB, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::BATTLESHIP, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::CARRIER, true), 5);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::LANDER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::CRUISER, UnitType::BLACK_BOAT, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::CRUISER, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::SUB, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::BATTLESHIP, true), 65);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::CARRIER, true), 75);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::LANDER, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::SUB, UnitType::BLACK_BOAT, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::INFANTRY, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::MECH, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::RECON, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::TANK, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::MD_TANK, true), 55);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::NEOTANK, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::MEGATANK, true), 25);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::ANTI_AIR, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::ARTILLERY, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::ROCKETS, true), 85);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::PIPERUNNER, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::MISSILES, true), 90);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::APC, true), 80);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::OOZIUM, true), 20);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::CRUISER, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::SUB, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::BATTLESHIP, true), 50);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::CARRIER, true), 60);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::LANDER, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::BATTLESHIP, UnitType::BLACK_BOAT, true), 95);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::FIGHTER, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::BOMBER, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::STEALTH, true), 100);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::B_COPTER, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::T_COPTER, true), 115);
		baseDamage.emplace(MakeDamageKey(UnitType::CARRIER, UnitType::BLACK_BOMB, true), 120);
	}

	Data::~Data() {
		mapTiles.clear();
	}

	MapTile Data::GetMapTileData(MapTileType type, bool silent) {
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

	UnitData Data::GetUnitData(UnitType type, bool silent) {
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

	Weapon Data::GetWeaponData(WeaponType type, bool silent) {
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
}
