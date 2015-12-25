#include <cstdlib>
#include <string>
#include <vector>
#include "rlutil.h"
#include "UI.h"

void testFunctions() {
	using namespace std;
	using namespace TerminalWars;
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

	int selectedOption = CreateMenu(0, 0, 7, 80, testMenu, true, 8);

	//rlutil::cls();
	rlutil::locate(1, 14);
	cout << "You selected " << selectedOption << endl;

	rlutil::anykey();
}

int main() {
	rlutil::hidecursor();
	rlutil::cls();

	testFunctions();

	return EXIT_SUCCESS;
}