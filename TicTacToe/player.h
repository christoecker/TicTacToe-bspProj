#pragma once
#include <string>
#include <iostream>

class player
{
private:
	std::string name;
public:
	player() {};
	player(bool p);
	int make_move();
	std::string get_name() { return name; };
};

