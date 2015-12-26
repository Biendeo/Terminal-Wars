#include "Weapon.h"

namespace TerminalWars {
	Weapon::Weapon(WeaponType type, std::string name, Range minRange, Range maxRange, Ammo maxAmmo, MoneyCost ammoCost, bool direct) {
		this->type = type;
		this->name = name;
		this->minRange = minRange;
		this->maxRange = maxRange;
		this->maxAmmo = maxAmmo;
		this->ammoCost = ammoCost;
		this->direct = direct;
	}


	Weapon::~Weapon() {
	}

	WeaponType Weapon::GetType() {
		return type;
	}

	std::string Weapon::GetName() {
		return name;
	}

	Range Weapon::GetMinRange() {
		return minRange;
	}

	Range Weapon::GetMaxRange() {
		return maxRange;
	}

	Ammo Weapon::GetMaxAmmo() {
		return maxAmmo;
	}
	
	MoneyCost Weapon::GetAmmoCost() {
		return ammoCost;
	}

	bool Weapon::IsDirect() {
		return direct;
	}
}