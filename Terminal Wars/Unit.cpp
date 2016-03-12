#include "Unit.h"
#include "UnitData.h"
#include "rlutil.h"

namespace TerminalWars {

	Unit::Unit(UnitType type, Team team, UnitData &datac, int x, int y) : data(datac) {
		givenName = "";
		this->type = type;
		this->team = team;
		Move(x, y);
		carried = false;
		health = 100;
	}
	
	Unit::Unit(UnitType type, Team team, UnitData &datac) : Unit::Unit(type, team, datac, 0, 0) {}

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

	int Unit::GetX() {
		return x;
	}

	int Unit::GetY() {
		return y;
	}

	void Unit::Move(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool Unit::GetCarried() {
		return carried;
	}

	void Unit::ToggleCarry() {
		if (carried) {
			carried = false;
		} else {
			carried = true;
		}
	}
}