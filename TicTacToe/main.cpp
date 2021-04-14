#include <cstdlib>
#include <iostream>
#include "game_controller.h"

int main() {
	game_controller c = game_controller();
	c.start_game();
	return EXIT_SUCCESS;
}