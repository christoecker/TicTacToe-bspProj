#pragma once
#include "playground_model.h"

class playground_view
{
private:
	playground_model& pg_model;
public:
	playground_view(playground_model& p) : pg_model(p) {};
	void show_field();
};

