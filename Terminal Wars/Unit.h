#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {
	class Unit {
		public:
		Unit();
		~Unit();

		UnitType GetType();
		std::string GetGivenName();
		void SetGivenName(std::string givenName);
		Team GetTeam();
		Color GetColor();

		private:
		UnitType type;
		std::string givenName;
		Team team;
	};
}