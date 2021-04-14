#include <cstdlib>
#include <iostream>
#include "playground_model.h"
#include "playground_view.h"

int main() {
	playground_model p = playground_model();
	p.make_entry(2, 2, field_state::player2);
	playground_view v = playground_view(p);
	v.show_field();
	return EXIT_SUCCESS;
}