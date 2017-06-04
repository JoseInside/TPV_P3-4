#pragma once
#include "EstadoPG.h"
#include "Boton.h"

class MenuOpciones : public EstadoPG
{
public:
	MenuOpciones(JuegoPG* jg);
	~MenuOpciones();

	static void play_bounce(JuegoPG * jg);
	static void play_PG(JuegoPG* jg);
	static void play_PBB(JuegoPG* jg);
	static void menu(JuegoPG * jg);

protected:

	Boton* B_playPG;
	Boton* B_playBounce;
	Boton* B_PBB;
	Boton* B_menu;

};

