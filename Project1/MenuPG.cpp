#include "MenuPG.h"
#include "PlayPG.h"
#include "MenuOpciones.h"

MenuPG::MenuPG(JuegoPG* jg) : EstadoPG(obJuego)
{
	obJuego = jg;

	B_play = new Boton(obJuego, play, 200, 120, Texturas_t::TBPlay);
	B_options = new Boton(obJuego, options, 200, 220, Texturas_t::TBOpciones);
	B_exit = new Boton(obJuego, exit, 200, 320, Texturas_t::TBExit);

	arrayObjetos.push_back(B_play);
	arrayObjetos.push_back(B_options);
	arrayObjetos.push_back(B_exit);
}


MenuPG::~MenuPG()
{
}


void MenuPG::play(JuegoPG * jg) {
	jg->changeState(new PlayPG(jg));

}
void MenuPG::exit(JuegoPG * jg) {
	jg->setSalir();
}

void MenuPG::options(JuegoPG * jg) {
	jg->changeState(new MenuOpciones(jg));

}