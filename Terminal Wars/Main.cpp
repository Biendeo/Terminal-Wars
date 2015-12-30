#include <cstdlib>
#include "Game.h"

int main(int argc, char *argv[]) {
	using namespace TerminalWars;
	Game *g = new Game();

	// TODO: Checks to see if files are there (maybe validity too?).

	g->Play();

	delete g;

	return EXIT_SUCCESS;
}