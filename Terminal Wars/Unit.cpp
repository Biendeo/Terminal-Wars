#include "Unit.h"

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
}