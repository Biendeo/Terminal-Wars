#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {
	class Unit {
		public:
		Unit();
		~Unit();

		UnitType GetType();
		std::string GetName();

		private:
		UnitType type;
		std::string name;
	};
}