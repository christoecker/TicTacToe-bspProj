#include "playground_model.h"

playground_model::playground_model()
{
	for (auto& i : field) {
		for (auto& j : i) {
			j = field_state::empty;
		}
	}

	field_capacity = 9;
}

void playground_model::clear_field()
{
	for (auto& i : field) {
		for (auto& j : i) {
			j = field_state::empty;
		}
	}
	field_capacity = 9;
}

bool playground_model::make_entry(int x, int y, field_state s)
{
	if (s == field_state::empty || field_capacity == 0) return false;

	if (x >= 0 && x < 3 && y >= 0 && y < 3) {
		if (field[x][y] == field_state::empty) {
			field[x][y] = s;
			field_capacity--;
			return true;
		}
	}
	return false;
}

int playground_model::get_field_capacity()
{
	return field_capacity;
}

field_state playground_model::get_entry(int x, int y)
{
	if (x >= 0 && x < 3 && y >= 0 && y < 3) {
		return field[x][y];
	}
	return field_state::access_error;
}

field_state playground_model::get_entry(int num)
{
	if (num >= 1 && num <= 9) {
		num--;
		return field[num / 3][num % 3];
	}
	return field_state();
}
