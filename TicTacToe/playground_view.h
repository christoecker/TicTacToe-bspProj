#pragma once
#include "playground_model.h"

class playground_view
{
private:
	playground_model* pg_model = nullptr;
public:
	playground_view() { pg_model = nullptr; };
	playground_view(playground_model* p) : pg_model(p) {};
	void show_field();
};

