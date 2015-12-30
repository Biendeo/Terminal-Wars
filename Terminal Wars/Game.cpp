#include <string>
#include "Data.h"
#include "Game.h"


namespace TerminalWars {
	Game::Game() {
		d = new Data();
		std::string mapSelection = SelectMap();
		m = new Map(mapSelection);
	}


	Game::~Game() {
		delete d;
		delete m;
	}

	void Game::Play() {

	}
}
