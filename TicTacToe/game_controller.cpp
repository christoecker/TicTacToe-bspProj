#include "game_controller.h"

game_controller::game_controller()
{
	m = playground_model();
	v = playground_view(&m);

	p.at(0) = player(0);
	p.at(1) = player(1);
}

void game_controller::start_game()
{
	char c = 0;			// Ergebnis von check()
	bool pS = 0;		// player selection
	char tile = 0;		// Auswahl des Felds durch Spieler
	short round = 1;
	while (c == 0 && round <= 9) {
		system("cls");
		std::cout << p.at(0).get_name() << " (" << p1 << "), " << p.at(1).get_name() << " (" << p2 << ")\n";
		std::cout << p.at(pS).get_name() << ", du bist an der Reihe!\n\n";

		v.show_field();

		std::cout << "\n";
		tile = p.at(pS).make_move();
		field_state fs;
		switch (pS) {
		case 0: fs = field_state::player1; break;
		case 1: fs = field_state::player2; break;
		}
		while (!(m.make_entry(tile, fs))) {
			std::cout << "Fehler bei der Auswahl eines Feldes!\n";
			tile = p.at(pS).make_move();
		}

		c = check(pS);
		pS = !pS;
		round++;
	}

	// Spiel ist beendet
	system("cls");
	switch (c) {
	case 0: std::cout << "Unentschieden. Niemand hat gewonnen.\n\n"; break;
	case 1: case 2:
		std::cout << p.at(!pS).get_name() << " hat gewonnen. HERZLICHEN GLUECKWUNSCH!\n\n";
	}
	v.show_field();
}

char game_controller::check(bool player)
{
	field_state p = field_state::empty;
	switch (player) {
	case 0: p = field_state::player1; break;
	case 1: p = field_state::player2; break;
	}
	// Ueberpruefung von 8 Faellen:
	// a) 3 in einer Reihe
	for (int i = 0; i < 3; i++) {
		if (m.get_entry(i, 0) == p && m.get_entry(i, 1) == p && m.get_entry(i, 2) == p) {
			return (char)p;
		}
	}
	// b) 3 in einer Spalte
	for (int i = 0; i < 3; i++) {
		if (m.get_entry(0, i) == p && m.get_entry(1, i) == p && m.get_entry(2, i) == p) {
			return (char)p;
		}
	}
	// c) Diagonalen
	if (m.get_entry(0, 0) == p && m.get_entry(1, 1) == p && m.get_entry(2, 2) == p) {
		return (char)p;
	}
	if (m.get_entry(0, 2) == p && m.get_entry(1, 1) == p && m.get_entry(2, 0) == p) {
		return (char)p;
	}

	// Falls keiner der oben betrachteten Faelle zutrifft, wird 0 zurueckgegeben:
	return 0;
}

