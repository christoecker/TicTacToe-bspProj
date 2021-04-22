#include "playground_view.h"
#include <fstream>

void playground_view::show_field()
{
	std::ifstream f("fieldTemplate.txt");
	if (!f.fail()) {
		char c;
		while ((c = f.get()) != EOF) {
			if (c >= 49 && c <= 57) {
				field_state s = pg_model->get_entry(c - 48);
				switch (s) {
				case field_state::empty: std::putc(c, stdout); break;
				case field_state::player1: std::putc(p1, stdout); break;
				case field_state::player2: std::putc(p2, stdout); break;
				}
			}
			else {
				std::putc(c, stdout);
			}
			
		}
		
	}
}
