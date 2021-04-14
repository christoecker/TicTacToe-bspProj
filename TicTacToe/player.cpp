#include "player.h"

player::player(bool p)
{
    std::cout << "Hallo Spieler " << p+1 << ". Bitte gib deinen Namen ein:\n";
    std::cin >> name;
}

int player::make_move()
{
    int sel = 0;
    std::cout << name << ": Bitte waehle ein freies Feld aus." << std::endl;
    std::cin >> sel;
    while (sel < 1 || sel > 9) {
        std::cout << "Deine Eingabe ist ungueltig. Bitte gib eine Zahl zwischen 1 und 9 ein.\n";
        std::cin >> sel;
    }
    return sel;
}
