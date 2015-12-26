#pragma once

namespace TerminalWars {
	typedef char Color;
	typedef short MoneyCost;
	typedef char MovementCost;
	typedef char DefenseRating;
	typedef unsigned char BaseDamage;

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
}