#include <cstdlib>
#include "Game.h"
#include "rlutil.h"

int main(int argc, char *argv[]) {
	using namespace TerminalWars;
	rlutil::hidecursor();

	Game *g = new Game();
	
	// TODO: Checks to see if files are there (maybe validity too?).

	g->Play();

	delete g;

	rlutil::showcursor();

	return EXIT_SUCCESS;
}