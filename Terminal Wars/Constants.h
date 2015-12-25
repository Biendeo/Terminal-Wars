#pragma once

namespace TerminalWars {
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
		FIELD,
		NONE_CITY,
		RED_CITY,
		BLUE_CITY,
		GREEN_CITY,
		YELLOW_CITY
	};

	// TODO: Finish UnitType
	enum class UnitType : char{
		NONE,
		INFANTRY,
		MECH
	};
}