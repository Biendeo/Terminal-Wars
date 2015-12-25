#include <string>
#include "MapTile.h"

namespace TerminalWars {
	MapTile::MapTile(MapTileType type, std::string name) {
		this->type = type;
		this->name = name;
	}


	MapTile::~MapTile() {
	}

	MapTileType MapTile::GetType() {
		return type;
	}

	std::string MapTile::GetName() {
		return name;
	}

}