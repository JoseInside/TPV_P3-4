#pragma once
#include "EstadoPG.h"
#include "Boton.h"

class MenuPG : public EstadoPG
{
public:
	MenuPG(JuegoPG* jg);
	~MenuPG();

	static void play(JuegoPG * jg);
	static void options(JuegoPG* jg);
	static void exit(JuegoPG * jg);

protected:

	Boton* B_play;
	Boton* B_exit;
	Boton* B_options;
};

