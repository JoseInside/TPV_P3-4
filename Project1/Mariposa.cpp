#include "Mariposa.h"
#include <iostream>
#include "PlayPG.h"

Mariposa::Mariposa(JuegoPG * hereJuego, int x, int y, Texturas_t textura) : ObjetoPG(hereJuego, x, y, textura)
{
	visible = true;
	rect.h = 70, rect.w = 50;
	obJuego = hereJuego;
}

Mariposa::~Mariposa()
{
}


void Mariposa::draw() {
	
	if (visible)
		obJuego->getTextura(tipoTextura)->animacion(nEstados, estadoActual, obJuego->getRender(), rect);
		
}

bool Mariposa::onClick(){
	
	int posX, posY;
	obJuego->getMousePos(posX, posY);

	if (visible && dentro(posX, posY)){
		//Aumentamos los clicks en uno
		numClicks++;
		rect.x = rand() % 610;
		rect.y = rand() % 420;

		if (numClicks == 3){
			visible = false;
			numClicks = 0;
			dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
			//obJuego->newBaja(this);
		}
		return true;
	}
	else return false;
}
void Mariposa::update(){
	
	if (visible){
		//animacion
		if (estadoActual < nEstados - 1)
			estadoActual++;
		else estadoActual = 0;	
	}
	
}