#include "MenuOpciones.h"
#include "MenuPG.h"


MenuOpciones::MenuOpciones(JuegoPG* jg) : EstadoPG(obJuego)
{
	obJuego = jg;

	B_playPG = new Boton(obJuego, play_PG, 200, 90, Texturas_t::TBGlobos);
	B_playBounce = new Boton(obJuego, play_bounce, 200, 180, Texturas_t::TBBouncing);
	B_PBB = new Boton(obJuego, play_PBB, 200, 270, Texturas_t::TBBouncing);
	B_menu = new Boton(obJuego, menu, 200, 360, Texturas_t::TBMenu);

	arrayObjetos.push_back(B_playPG);
	arrayObjetos.push_back(B_playBounce);
	arrayObjetos.push_back(B_PBB);
	arrayObjetos.push_back(B_menu);
}

MenuOpciones::~MenuOpciones()
{
}

void MenuOpciones::play_bounce(JuegoPG * jg) {
	jg->setFactory("PlayBounce");
	menu(jg);
}
void MenuOpciones::play_PG(JuegoPG * jg) {
	jg->setFactory("PlayPG");
	menu(jg);
}

void MenuOpciones::play_PBB(JuegoPG * jg) {
	jg->setFactory("PlayPBB");
	menu(jg);
}

void MenuOpciones::menu(JuegoPG * jg) {
	jg->changeState(new MenuPG(jg));
}