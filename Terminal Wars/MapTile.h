#pragma once
#include <string>
#include "Constants.h"

namespace TerminalWars {

	class MapTile {
		public:
		MapTile(MapTileType type, std::string name, char displayChar, Color foregroundColor, Color backgroundColor, Movement infantry, Movement mech, Movement tires, Movement tread, Movement pipe, Movement slime, Movement ship, Movement transport, Movement air, DefenseRating defense);
		~MapTile();
		MapTileType GetType();
		std::string GetName();
		char GetDisplayChar();
		Color GetForegroundColor();
		Color GetBackgroundColor();
		Movement GetMovementCost(MovementType type);
		DefenseRating GetDefense();

		private:
		// TODO: Is the type necessary to store if the map requires it for access?
		MapTileType type;
		std::string name;
		char displayChar;
		char foregroundColor;
		char backgroundColor;
		struct {
			Movement infantry;
			Movement mech;
			Movement tires;
			Movement tread;
			Movement pipe;
			Movement slime;
			Movement ship;
			Movement transport;
			Movement air;
		} movementCost;
		DefenseRating defense;
	};
}