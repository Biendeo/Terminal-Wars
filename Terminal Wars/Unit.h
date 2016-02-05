#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {
	class Unit {
		public:
		Unit(UnitType type, Team team);
		Unit(UnitType type, Team team, int x, int y);
		~Unit();

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