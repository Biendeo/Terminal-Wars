#pragma once

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

	enum class Team : char {
		NONE,
		RED,
		BLUE,
		GREEN,
		YELLOW
	};

	// TODO: Finish MapTileType
	enum class MapTileType : char {
		NONE,
		PLAIN,
		NONE_CITY,
		RED_CITY,
		BLUE_CITY,
		GREEN_CITY,
		YELLOW_CITY
	};

	// TODO: Finish UnitType
	enum class UnitType : char {
		NONE,
		INFANTRY,
		MECH
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