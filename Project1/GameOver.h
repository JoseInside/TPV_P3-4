#pragma once
#include "EstadoPG.h"
class GameOver : public EstadoPG
{
public:
	GameOver(JuegoPG * jg);
	~GameOver();

protected:

	static void score(JuegoPG * jg);
	static void menu(JuegoPG * jg);
};

