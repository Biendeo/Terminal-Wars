#include <cstdlib>
#include <string>
#include <vector>
#include "../Terminal Wars/rlutil.h"
#include "../Terminal Wars/UI.h"
#include "../Terminal Wars/Data.h"
#include "../Terminal Wars/MapTile.h"

void test1();
void test2();

int main() {
	rlutil::hidecursor();

	test1();
	test2();

	return EXIT_SUCCESS;
}

void test1() {
	using namespace std;
	using namespace TerminalWars;

	rlutil::cls();
	cout << "Press any key to begin TEST 1" << endl;
	rlutil::getkey();

	vector<string> testMenu;
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

	// These two should be the same.
	MapTile tile1 = d.GetMapTileData(MapTileType::PLAIN);
	MapTile tile2 = Data::GetMapTileData(MapTileType::PLAIN);

	std::cout << "Tile1 is of name " << tile1.GetName() << std::endl;
	std::cout << "Tile2 is of name " << tile2.GetName() << std::endl;

	UnitData unit1 = d.GetUnitData(UnitType::INFANTRY);
	UnitData unit2 = Data::GetUnitData(UnitType::INFANTRY);

	// These two should be the same.
	std::cout << "Unit1 is of name " << unit1.GetName() << std::endl;
	std::cout << "Unit2 is of name " << unit2.GetName() << std::endl;

	rlutil::anykey();
}