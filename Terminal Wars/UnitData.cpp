#include <string>
#include "UnitData.h"
#include "Weapon.h"
#include "Data.h"


namespace TerminalWars {
	UnitData::UnitData(UnitType type, std::string name, char displayChar, MoneyCost cost, MovementType movementType, Movement maxMovement, Movement maxFuel, Vision vision, WeaponType weapon1, WeaponType weapon2) {
		// TODO: All of this.
		this->type = type;
		this->name = name;
		this->displayChar = displayChar;
		this->cost = cost;
		this->movementType = movementType;
		this->maxMovement = maxMovement;
		this->maxFuel = maxFuel;
		this->vision = vision;
		this->weapon1 = weapon1;
		this->weapon2 = weapon2;
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

	Weapon UnitData::GetWeapon1() {
		return Data::GetWeaponData(weapon1);
	}
	Weapon UnitData::GetWeapon2() {
		return Data::GetWeaponData(weapon2);
	}

	char UnitData::GetDisplayChar() {
		return displayChar;
	}
}