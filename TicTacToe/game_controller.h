#pragma once
#include <array>
#include "player.h"
#include "playground_model.h"
#include "playground_view.h"
#include "tictactoe_utils.h"

class game_controller
{
private:
	std::array<player, 2> p;
	playground_model m;
	playground_view v;
public:
	game_controller();
	void start_game();
	char check(bool player);
};

