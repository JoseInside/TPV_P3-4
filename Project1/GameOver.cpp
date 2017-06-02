#include "GameOver.h"
#include "Boton.h"
#include "MenuPG.h"

GameOver::GameOver(JuegoPG* jg) : EstadoPG(jg)
{
	obJuego = jg;
	score(obJuego);
	arrayObjetos.push_back(new Boton(obJuego, menu, 200, 350, Texturas_t::TBMenu));
}


GameOver::~GameOver()
{
}



void GameOver::score(JuegoPG * jg) {
	
	string m = { "Has obtenido: " + to_string(jg->getPoints()) + " puntos!\n Gracias por jugar!" };

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "EL PINCHA GLOBOS", m.c_str(), nullptr);
		
	//cout << "Has obtenido " << puntos << " puntos\n";
}

void GameOver::menu(JuegoPG * jg) {	jg->changeState(new MenuPG(jg)); }