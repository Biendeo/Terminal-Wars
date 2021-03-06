#include <cstdlib>
#include <string>
#include <vector>
#include "../Terminal Wars/Game.h"
#include "../Terminal Wars/rlutil.h"
#include "../Terminal Wars/UI.h"
#include "../Terminal Wars/Data.h"
#include "../Terminal Wars/MapTile.h"
#include "../Terminal Wars/Weapon.h"
#include "../Terminal Wars/UnitData.h"

void test1();
void test2();
void test3();

int main(int argc, char *argv[]) {
	rlutil::hidecursor();

	test1();
	test2();
	test3();

	rlutil::showcursor();

	return EXIT_SUCCESS;
}

void test1() {
	using namespace std;
	using namespace TerminalWars;

	rlutil::cls();
	cout << "Press any key to begin TEST 1" << endl;
	rlutil::getkey();
	rlutil::cls();

	std::vector<std::string> testMenu;
	testMenu.push_back("ITEM 1 is plain old.");
	testMenu.push_back("ITEM 2");
	testMenu.push_back("ITEM 3");
	testMenu.push_back("ITEM 4");
	testMenu.push_back("ITEM 5");
	testMenu.push_back(DisableStringForMenu("ITEM 6 is disabled."));
	testMenu.push_back(DisableStringForMenu("ITEM 7 is too."));
	testMenu.push_back(DisableStringForMenu("ITEM 8"));
	testMenu.push_back(DisableStringForMenu("ITEM 9"));
	testMenu.push_back("ITEM 10 is not disabled.");
	testMenu.push_back("ITEM 11 is a much longer string that is really difficult to print in one go, so it's shortened by some dots at the end.");
	testMenu.push_back("ITEM 12 is much longer, but not quite as long as 11.");
	testMenu.push_back("ITEM 13");
	testMenu.push_back("ITEM 14");

	int selectedOption = CreateMenu(0, 0, 80, 7, testMenu, 2, true, 8);

	rlutil::locate(1, 14);
	cout << "You selected " << testMenu.at(selectedOption) << " [" << selectedOption << "]" << endl;

	rlutil::anykey();
}

void test2() {
	using namespace std;
	using namespace TerminalWars;
	rlutil::cls();
	cout << "Press any key to begin TEST 2" << endl;
	rlutil::getkey();

	Data d;

	// This tests every map tile (including the exceed case).
	for (int i = 0; i <= d.GetMapTileDataSize(); i++) {
		MapTile tile = d.GetMapTileData(static_cast<MapTileType>(i));
		std::cout << "Tile type: " << static_cast<int>(tile.GetType()) << std::endl;
		std::cout << "Tile name: " << tile.GetName() << std::endl;
		std::cout << "Tile appearance: ";
		rlutil::setColor(tile.GetForegroundColor());
		rlutil::setBackgroundColor(tile.GetBackgroundColor());
		std::cout << tile.GetDisplayChar();
		rlutil::resetColor();
		std::cout << std::endl;
		std::cout << "Tile infantry speed: " << int(tile.GetMovementCost(MovementType::INFANTRY)) << std::endl;
		std::cout << "Tile mech speed: " << int(tile.GetMovementCost(MovementType::MECH)) << std::endl;
		std::cout << "Tile tires speed: " << int(tile.GetMovementCost(MovementType::TIRES)) << std::endl;
		std::cout << "Tile tread speed: " << int(tile.GetMovementCost(MovementType::TREAD)) << std::endl;
		std::cout << "Tile pipe speed: " << int(tile.GetMovementCost(MovementType::PIPE)) << std::endl;
		std::cout << "Tile slime speed: " << int(tile.GetMovementCost(MovementType::SLIME)) << std::endl;
		std::cout << "Tile ship speed: " << int(tile.GetMovementCost(MovementType::SHIP)) << std::endl;
		std::cout << "Tile transport speed: " << int(tile.GetMovementCost(MovementType::TRANSPORT)) << std::endl;
		std::cout << "Tile air speed: " << int(tile.GetMovementCost(MovementType::AIR)) << std::endl;
		std::cout << "Tile defense rating: " << int(tile.GetDefense()) << std::endl;

		rlutil::anykey();
		rlutil::cls();
	}
	
	// This tests every unit type (including the exceed case).
	for (int i = 0; i <= d.GetUnitDataSize(); i++) {
		UnitData unit = d.GetUnitData(static_cast<UnitType>(i));
		std::cout << "Unit type: " << static_cast<int>(unit.GetType()) << std::endl;
		std::cout << "Unit name: " << unit.GetName() << std::endl;
		std::cout << "Unit appearance: ";
		rlutil::setColor(rlutil::LIGHTRED);
		std::cout << unit.GetDisplayChar() << " ";
		rlutil::setColor(rlutil::LIGHTBLUE);
		std::cout << unit.GetDisplayChar() << " ";
		rlutil::setColor(rlutil::LIGHTGREEN);
		std::cout << unit.GetDisplayChar() << " ";
		rlutil::setColor(rlutil::YELLOW);
		std::cout << unit.GetDisplayChar();
		rlutil::resetColor();
		std::cout << std::endl;
		std::cout << "Unit cost: " << int(unit.GetCost()) << std::endl;
		std::cout << "Unit movement type: " << static_cast<int>(unit.GetMovementType()) << std::endl;
		std::cout << "Unit movement points: " << int(unit.GetMaxMovement()) << std::endl;
		std::cout << "Unit fuel: " << int(unit.GetMaxFuel()) << std::endl;
		std::cout << "Unit vision: " << int(unit.GetVision()) << std::endl;
		std::cout << "Unit weapon 1: " << unit.GetWeapon1().GetName() << " (" << static_cast<int>(unit.GetWeapon1().GetType()) << ")" << std::endl;
		std::cout << "Unit weapon 2: " << unit.GetWeapon2().GetName() << " (" << static_cast<int>(unit.GetWeapon2().GetType()) << ")" << std::endl;
		// TODO: Test for damage.

		rlutil::anykey();
		rlutil::cls();
	}

	// This tests every weapon type (including the exceed case).
	for (int i = 0; i <= d.GetWeaponDataSize(); i++) {
		TerminalWars::Weapon weapon = d.GetWeaponData(static_cast<WeaponType>(i));
		std::cout << "Weapon type: " << static_cast<int>(weapon.GetType()) << std::endl;
		std::cout << "Weapon name: " << weapon.GetName() << std::endl;
		std::cout << "Weapon min range: " << int(weapon.GetMinRange()) << std::endl;
		std::cout << "Weapon max range: " << int(weapon.GetMaxRange()) << std::endl;
		std::cout << "Weapon total ammo: " << int(weapon.GetMaxAmmo()) << std::endl;
		std::cout << "Weapon ammo cost: " << int(weapon.GetAmmoCost()) << std::endl;
		std::cout << "Is it direct? : " << weapon.IsDirect() << std::endl;

		rlutil::anykey();
		rlutil::cls();
	}
}

void test3() {
	using namespace std;
	using namespace TerminalWars;
	rlutil::cls();
	cout << "Press any key to begin TEST 3" << endl;
	rlutil::getkey();

	Game *g = new Game("../Maps/Spann-Island.twmap");
	g->Play();

	rlutil::getkey();
}