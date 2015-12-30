#pragma once
#include "Constants.h"
#include "Data.h"
#include "Map.h"
#include "MapTile.h"
#include "UI.h"
#include "Unit.h"
#include "UnitData.h"
#include "Weapon.h"

namespace TerminalWars {
	class Game {
		public:
		Game();
		~Game();
		void Play();
		Data *d;
		Map *m;

	};
}