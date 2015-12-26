#pragma once
#include <vector>
#include "Constants.h"

namespace TerminalWars {
	class UnitData {
		public:
		UnitData(UnitType type, std::string name, char displayChar, Color color, MoneyCost cost, MovementType movementType, Movement maxMovement, Vision vision);
		~UnitData();
		std::string GetName();
		UnitType GetType();
		MoneyCost GetCost();
		MovementType GetMovementType();
		Movement GetMaxMovement();
		Vision GetVision();
		BaseDamage GetBaseDamage(UnitType defender);
		char GetDisplayChar();

		private:
		std::string name;
		UnitType type;
		MoneyCost cost;
		MovementType movementType;
		Movement maxMovement;
		Vision vision;
		std::vector<BaseDamage> baseDamage;
		char displayChar;
		// TODO: Weapons.
	};
}