#include "Pausa.h"
#include "Boton.h"
#include "MenuPG.h"

Pausa::Pausa(JuegoPG* jg) : EstadoPG(obJuego)
{
	obJuego = jg;
	arrayObjetos.push_back(new Boton(obJuego, continuar, 200, 120, Texturas_t::TBContinue));
	arrayObjetos.push_back(new Boton(obJuego, menu, 200, 220, Texturas_t::TBMenu));
}


Pausa::~Pausa()
{
}


void Pausa::menu(JuegoPG * jg) { jg->changeState(new MenuPG(jg)); }

void Pausa::continuar(JuegoPG * jg) { jg->popState(); }
