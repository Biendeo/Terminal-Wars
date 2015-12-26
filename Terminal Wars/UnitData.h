#pragma once
#include <vector>
#include "Constants.h"

namespace TerminalWars {
	class UnitData {
		public:
		UnitData(UnitType type, std::string name, char displayChar, Color color, MoneyCost cost, MovementType movementType);
		~UnitData();
		std::string GetName();
		UnitType GetType();
		MoneyCost GetCost();
		MovementType GetMovementType();
		BaseDamage GetBaseDamage(UnitType defender);
		char GetDisplayChar();
		Color GetColor();

		private:
		std::string name;
		UnitType type;
		MoneyCost cost;
		MovementType movementType;
		std::vector<BaseDamage> baseDamage;
		char displayChar;
		Color color;
		// TODO: Weapons.
	};
}