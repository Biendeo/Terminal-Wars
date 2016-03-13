#pragma once
#include <string>

namespace TerminalWars {
	typedef char Color;
	typedef int Money;
	typedef unsigned short MoneyCost;
	typedef char Movement;
	typedef char DefenseRating;
	typedef unsigned char BaseDamage;
	typedef char Vision;
	typedef char Range;
	typedef char Ammo;
	typedef int DamageKey;
	typedef short Health;

	enum class Team : char {
		NONE,
		RED,
		BLUE,
		GREEN,
		YELLOW
	};

	enum class MapTileType : char {
		NONE,
		FOREST,
		MISSILE_SILO,
		MISSILE_SILO_USED,
		MOUNTAIN,
		PIPE,
		PIPE_SEAM,
		PLAIN,
		REEF,
		RIVER,
		ROAD,
		SEA,
		SHOAL,
		NONE_CITY,
		RED_CITY,
		BLUE_CITY,
		GREEN_CITY,
		YELLOW_CITY,
		NONE_HQ,
		RED_HQ,
		BLUE_HQ,
		GREEN_HQ,
		YELLOW_HQ,
		NONE_BASE,
		RED_BASE,
		BLUE_BASE,
		GREEN_BASE,
		YELLOW_BASE,
		NONE_PORT,
		RED_PORT,
		BLUE_PORT,
		GREEN_PORT,
		YELLOW_PORT,
		NONE_AIRPORT,
		RED_AIRPORT,
		BLUE_AIRPORT,
		GREEN_AIRPORT,
		YELLOW_AIRPORT,
		NONE_TOWER,
		RED_TOWER,
		BLUE_TOWER,
		GREEN_TOWER,
		YELLOW_TOWER
	};

	enum class UnitType : char {
		NONE,
		INFANTRY,
		MECH,
		RECON,
		TANK,
		MD_TANK,
		NEOTANK,
		MEGATANK,
		APC,
		ARTILLERY,
		ROCKETS,
		ANTI_AIR,
		MISSILES,
		PIPERUNNER,
		OOZIUM,
		BATTLESHIP,
		CRUISER,
		LANDER,
		SUB,
		BLACK_BOAT,
		CARRIER,
		FIGHTER,
		BOMBER,
		B_COPTER,
		T_COPTER,
		STEALTH,
		BLACK_BOMB
	};

	enum class MovementType : char {
		NONE,
		INFANTRY,
		MECH,
		TIRES,
		TREAD,
		PIPE,
		SLIME,
		SHIP,
		TRANSPORT,
		AIR
	};

	enum class WeaponType : char {
		NONE,
		M_GUN,
		BAZOOKA,
		T_CANNON,
		MD_CANNON,
		NEO_CANNON,
		MEGA_CANNON,
		ART_CANNON,
		ROCKETS,
		VULCAN,
		G_MISSILES,
		PIPE,
		F_MISSILES,
		BOMBS,
		COP_MISSILES,
		OMNIMISSILES,
		BSHIP_CANNON,
		CRU_MISSILES,
		CRU_AA,
		TORPEDOS,
		CAR_MISSILES
	};
}