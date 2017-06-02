#include "Boton.h"



Boton::Boton(JuegoPG* jg, CallBack_t* callback, int px, int py, Texturas_t text) : ObjetoPG(jg, px, py, text)
{
	obJuego = jg;
	tipoTextura = text;
	rect.x = px;
	rect.y = py;
	_callBack = callback;
}


Boton::~Boton()
{
}

void Boton::draw() {
	
	rect.h = 100;
	rect.w = 250;
	
	obJuego->getTextura(tipoTextura)->draw(obJuego->getRender(), rect);

	//obJuego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
}

bool Boton::onClick() {
	int x, y;
	obJuego->getMousePos(x, y);

	if (dentro(x, y)) {
		_callBack(obJuego);
		return true;
	}
	return false;
}