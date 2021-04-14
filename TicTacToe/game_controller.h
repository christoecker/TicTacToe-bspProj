#pragma once
#include "player.h"
#include "playground_model.h"
#include "playground_view.h"
#include "tictactoe_utils.h"

class game_controller
{
private:
	player* p[2];
	playground_model* m;
	playground_view* v;
public:
	game_controller();
	~game_controller();
	void start_game();
	char check(bool player);
};

