#include <string>
#include "MapTile.h"

namespace TerminalWars {
	MapTile::MapTile(MapTileType type, std::string name, char displaychar, Color foregroundColor, Color backgroundColor, MovementCost infantry, MovementCost mech, MovementCost tires, MovementCost tread, MovementCost pipe, MovementCost slime, MovementCost ship, MovementCost transport, MovementCost air, DefenseRating defense) {
		this->type = type;
		this->name = name;
		this->displayChar = displayChar;
		this->foregroundColor = foregroundColor;
		this->backgroundColor = backgroundColor;
		this->movementCost.infantry = infantry;
		this->movementCost.mech = mech;
		this->movementCost.tires = tires;
		this->movementCost.tread = tread;
		this->movementCost.pipe = pipe;
		this->movementCost.slime = slime;
		this->movementCost.ship = ship;
		this->movementCost.transport = transport;
		this->movementCost.air = air;
		this->defense = defense;
	}

	MapTile::~MapTile() {
	}

	MapTileType MapTile::GetType() {
		return type;
	}

	std::string MapTile::GetName() {
		return name;
	}

	char MapTile::GetDisplayChar() {
		return displayChar;
	}

	Color MapTile::GetForegroundColor() {
		return foregroundColor;
	}
	
	Color MapTile::GetBackgroundColor() {
		return backgroundColor;
	}

	MovementCost MapTile::GetMovementCost(MovementType type) {
		switch (type) {
			case MovementType::NONE:
			default:
				return 0;
			case MovementType::INFANTRY:
				return movementCost.infantry;
			case MovementType::MECH:
				return movementCost.mech;
			case MovementType::TIRES:
				return movementCost.tires;
			case MovementType::TREAD:
				return movementCost.tread;
			case MovementType::PIPE:
				return movementCost.pipe;
			case MovementType::SLIME:
				return movementCost.slime;
			case MovementType::SHIP:
				return movementCost.ship;
			case MovementType::TRANSPORT:
				return movementCost.transport;
			case MovementType::AIR:
				return movementCost.air;
		}
	}

	DefenseRating MapTile::GetDefense() {
		return defense;
	}

}