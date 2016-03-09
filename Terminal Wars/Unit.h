#pragma once
#include <string>
#include "Constants.h"
#include "UnitData.h"

namespace TerminalWars {
	class Unit {
		public:
		Unit(UnitType type, Team team, UnitData *data);
		Unit(UnitType type, Team team, UnitData *data, int x, int y);
		~Unit();
		UnitData *data; // TODO: Can this be done with a reference?

		UnitType GetType();
		std::string GetGivenName();
		void SetGivenName(std::string givenName);
		Team GetTeam();
		Color GetColor();
		int GetX();
		int GetY();
		void Move(int x, int y);
		bool GetCarried();
		void ToggleCarry();

		private:
		// TODO: More properties.
		// TODO: Transport carry properties.
		UnitType type;
		std::string givenName;
		Team team;
		int x;
		int y;
		bool carried;
		Health health;
	};
}