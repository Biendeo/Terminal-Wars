#include "Unit.h"
#include "rlutil.h"

namespace TerminalWars {

	Unit::Unit() {
		givenName = "";
	}


	Unit::~Unit() {
	}
	
	UnitType Unit::GetType() {
		return type;
	}

	std::string Unit::GetGivenName() {
		return givenName;
	}

	void Unit::SetGivenName(std::string givenName) {
		this->givenName = givenName;
	}

	Team Unit::GetTeam() {
		return team;
	}

	Color Unit::GetColor() {
		switch (GetTeam()) {
			case Team::NONE:
			default:
				return rlutil::GREY;
			case Team::RED:
				return rlutil::LIGHTRED;
			case Team::BLUE:
				return rlutil::LIGHTBLUE;
			case Team::GREEN:
				return rlutil::LIGHTGREEN;
			case Team::YELLOW:
				return rlutil::YELLOW;
		}
	}
}