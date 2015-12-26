#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {

	typedef char MovementCost;
	typedef char DefenseRating;

	class MapTile {
		public:
		MapTile(MapTileType type, std::string name, char displaychar, Color foregroundColor, Color backgroundColor, MovementCost infantry, MovementCost mech, MovementCost tires, MovementCost tread, MovementCost pipe, MovementCost slime, MovementCost ship, MovementCost transport, MovementCost air, DefenseRating defense);
		~MapTile();
		MapTileType GetType();
		std::string GetName();
		char GetDisplayChar();
		Color GetForegroundColor();
		Color GetBackgroundColor();
		MovementCost GetMovementCost(MovementType type);
		DefenseRating GetDefense();

		private:
		MapTileType type;
		std::string name;
		char displayChar;
		char foregroundColor;
		char backgroundColor;
		struct {
			MovementCost infantry;
			MovementCost mech;
			MovementCost tires;
			MovementCost tread;
			MovementCost pipe;
			MovementCost slime;
			MovementCost ship;
			MovementCost transport;
			MovementCost air;
		} movementCost;
		DefenseRating defense;
	};
}