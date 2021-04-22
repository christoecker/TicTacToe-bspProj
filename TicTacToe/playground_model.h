#pragma once
#include "tictactoe_utils.h"
#include <array>

class playground_model
{
private:
	std::array<std::array<field_state, 3>, 3> field;
public:
	playground_model();
	void clear_field();
	bool make_entry(int x, int y, field_state s);
	bool make_entry(int f, field_state s);
	field_state get_entry(int x, int y);
	field_state get_entry(int num);
};

