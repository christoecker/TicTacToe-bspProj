#pragma once
#include "tictactoe_utils.h"
#include <array>

class playground_model
{
private:
	std::array<std::array<field_state, 3>, 3> field;
	int field_capacity;
public:
	playground_model();
	void clear_field();
	bool make_entry(int x, int y, field_state s);
	int get_field_capacity();
	field_state get_entry(int x, int y);
};

