#include "Unit.h"

namespace TerminalWars {

	Unit::Unit() {
	}


	Unit::~Unit() {
	}
	
	UnitType Unit::GetType() {
		return type;
	}

	std::string Unit::GetName() {
		return name;
	}
}