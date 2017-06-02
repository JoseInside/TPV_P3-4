#include "Premio.h"
#include "PlayPG.h"

Premio::Premio(JuegoPG * hereJuego, int x, int y, Texturas_t textura) : ObjetoPG(hereJuego, x, y, textura)
{
	visible = false;
	rect.h = 70, rect.w = 50;
}


Premio::~Premio()
{
}

bool Premio::onClick(){

	if (visible){
		//Disminuimos posibilidad de clickear	
		numIntentos--;
		int posX, posY;
		obJuego->getMousePos(posX, posY);
		if (dentro(posX, posY)){
			dynamic_cast<PlayPG*>(obJuego->topEstado())->newPuntos(this);
			dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
			return true;
		}
	}
	else return false;
}

void Premio::update(){
	
	if (PP > 0){
		--PP;
	}
	if (numIntentos == 0){
		dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
	}
}

void Premio::reinicia(){
	visible = false;
	numIntentos = 3;
	PP = 100;
}