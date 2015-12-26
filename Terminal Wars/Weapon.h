#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {
	class Weapon {
		public:
		Weapon(WeaponType type, std::string name, Range minRange, Range maxRange, Ammo maxAmmo, MoneyCost ammoCost, bool direct);
		~Weapon();
		WeaponType GetType();
		std::string GetName();
		Range GetMinRange();
		Range GetMaxRange();
		Ammo GetMaxAmmo();
		MoneyCost GetAmmoCost();
		bool IsDirect();

		private:
		WeaponType type;
		std::string name;
		Range minRange;
		Range maxRange;
		Ammo maxAmmo;
		MoneyCost ammoCost;
		bool direct;
	};
}