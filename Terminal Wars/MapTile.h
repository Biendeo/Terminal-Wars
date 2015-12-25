#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {
	class MapTile {
		public:
		MapTile(MapTileType type, std::string name);
		~MapTile();
		MapTileType GetType();
		std::string GetName();

		private:
		MapTileType type;
		std::string name;
		// TODO: Other properties.
	};
}