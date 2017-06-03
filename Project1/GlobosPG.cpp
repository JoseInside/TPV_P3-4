#include "GlobosPG.h"
#include "PlayPG.h"

GlobosPG::GlobosPG(JuegoPG * hereJuego, int x, int y, Texturas_t textura) : ObjetoPG(hereJuego, x, y, textura)
{	
	if (rand() % 100 < PVIS)
		visible = true;
	else visible = false;
	muerto = false;

	obJuego = hereJuego;
	
	puntosObjeto = 10;
	//Dimensiones de los globos
	rect.h = 70;
	rect.w = 50;
}


GlobosPG::~GlobosPG()
{
}


bool GlobosPG::onClick(){
	int posX, posY;
	obJuego->getMousePos(posX, posY);

	if (visible && dentro(posX, posY)){
		//Explotamos el globo
		dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
		dynamic_cast<PlayPG*>(obJuego->topEstado())->newPuntos(this);
		//obJuego->newPuntos(this);
		//obJuego->newBaja(this);
		visible = false;
		muerto = true;
		return true;
	}
	else return false;


}


void GlobosPG::update(){

	if (!muerto) {
		if (rand() % 100 < PVIS)
			visible = true;
		else visible = false;

		if (visible){

			if (rand() % 100 > PDES){
				rect.h -= DT;
				rect.w -= DT;
				puntosObjeto += AP;
			}

			if (rect.h <= 0 || rect.w <= 0) {
				visible = false;
				muerto = true;
				dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
			}
		}
	}

}