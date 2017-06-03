#include "BouncingBall.h"
#include "PlayPG.h"


BouncingBall::BouncingBall(JuegoPG* hereJuego, int x, int y, Texturas_t textura) : ObjetoPG(hereJuego, x, y, textura)
{
	obJuego = hereJuego;
	tipoTextura = textura;
	visible = true;
	
	//Mismo tamaño que los globos
	rect.h = 70;
	rect.w = 50;

	//Dirección
	//Formula: rand()%(max-min + 1) + min;
	dx = rand() % (5 - (-5) + 1) + (-5);
	dy = rand() % (5 - (-5) + 1) + (-5);

	dx *= 2;
	dy *= 2;
	puntosObjeto = rand() % (100 - 50 + 1) + 50;
}


BouncingBall::~BouncingBall()
{
}


bool BouncingBall::onClick() {
	int posX, posY;
	obJuego->getMousePos(posX, posY);

	if (dentro(posX, posY)) {
		dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
		dynamic_cast<PlayPG*>(obJuego->topEstado())->newPuntos(this);
		muerto = true;
		visible = false;
		return true;
	}
	else return false;


}


void BouncingBall::update() {

	if (!muerto) {

		aux = rect;

		aux.x += dx;
		aux.y += dy;

		if (choqueBorders()) {
			puntosObjeto -= 10;
		}

		if (puntosObjeto <= 0) {
			visible = false;
			muerto = true;
			dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
		}

		rect.x += dx;
		rect.y += dy;
	}
}

bool BouncingBall::choqueBorders() {
	
	//X
	if (aux.x < 0 || aux.x + rect.w > obJuego->getScreenWidth()) {
		dx = -dx;
		return true;
	}
	//Y
	else if (aux.y < 0 || aux.y + rect.h > obJuego->getScreenHeight()) {
		dy = -dy;
		return true;
	}
	
	return false;
}