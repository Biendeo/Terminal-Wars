#pragma once
#include <vector>
#include "Constants.h"
#include "Weapon.h"

class Weapon;

namespace TerminalWars {
	class UnitData {
		public:
		UnitData(UnitType type, std::string name, char displayChar, MoneyCost cost, MovementType movementType, Movement maxMovement, Movement maxFuel, Vision vision, WeaponType weapon1, WeaponType weapon2);
		~UnitData();
		std::string GetName();
		UnitType GetType();
		MoneyCost GetCost();
		MovementType GetMovementType();
		Movement GetMaxMovement();
		Movement GetMaxFuel();
		Vision GetVision();
		Weapon GetWeapon1();
		Weapon GetWeapon2();
		char GetDisplayChar();

		private:
		std::string name;
		UnitType type;
		MoneyCost cost;
		MovementType movementType;
		Movement maxMovement;
		Movement maxFuel;
		Vision vision;
		WeaponType weapon1;
		WeaponType weapon2;
		char displayChar;
		// TODO: Weapons.
	};
}