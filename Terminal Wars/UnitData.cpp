#include <string>
#include "UnitData.h"


namespace TerminalWars {
	UnitData::UnitData(UnitType type, std::string name, char displayChar, Color color, MoneyCost cost, MovementType movementType) {
		// TODO: All of this.
		this->type = type;
		this->name = name;
		this->displayChar = displayChar;
		this->color = color;
		this->cost = cost;
		this->movementType = movementType;
	}


	UnitData::~UnitData() {
	}


	std::string UnitData::GetName() {
		return name;
	}

	UnitType UnitData::GetType() {
		return type;
	}

	MoneyCost UnitData::GetCost() {
		return cost;
	}

	MovementType UnitData::GetMovementType() {
		return movementType;
	}
	
	BaseDamage UnitData::GetBaseDamage(UnitType defender) {
		// TODO: Make this a lot more professional than it is.
		// I should not rely on the fact that enums are in numerical order.
		return baseDamage.at(static_cast<int>(defender));
	}

	char UnitData::GetDisplayChar() {
		return displayChar;
	}

	Color UnitData::GetColor() {
		return color;
	}
}