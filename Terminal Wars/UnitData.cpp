#include <string>
#include "UnitData.h"
#include "Weapon.h"
#include "Data.h"


namespace TerminalWars {
	UnitData::UnitData(UnitType type, std::string name, char displayChar, MoneyCost cost, MovementType movementType, Movement maxMovement, Movement maxFuel, Vision vision, Weapon &weapon1c, Weapon &weapon2c) : weapon1(weapon1c), weapon2(weapon2c) {
		this->type = type;
		this->name = name;
		this->displayChar = displayChar;
		this->cost = cost;
		this->movementType = movementType;
		this->maxMovement = maxMovement;
		this->maxFuel = maxFuel;
		this->vision = vision;
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

	Movement UnitData::GetMaxMovement() {
		return maxMovement;
	}

	Movement UnitData::GetMaxFuel() {
		return maxFuel;
	}

	Vision UnitData::GetVision() {
		return vision;
	}

	Weapon &UnitData::GetWeapon1() {
		return weapon1;
	}
	Weapon &UnitData::GetWeapon2() {
		return weapon2;
	}

	char UnitData::GetDisplayChar() {
		return displayChar;
	}
}