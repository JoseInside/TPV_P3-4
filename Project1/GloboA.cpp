#include "GloboA.h"
#include "PlayPG.h"

GloboA::GloboA(JuegoPG * hereJuego, int x, int y, Texturas_t textura) : GlobosPG(hereJuego, x, y, textura)
{
	visible = true;
}


GloboA::~GloboA()
{
}


void GloboA::update() {
	
	if (visible){

		//Desinfla y asciende
		if (rand() % 100 > PDES){
			rect.h -= DT;
			rect.w -= DT;
			puntosObjeto += AP;
			
			if(rect.y >= 0)
				rect.y-= 10;
			else {
				puntosObjeto -= DP;
			}
		}
		if (rect.h <= 0 || rect.w <= 0) {
			visible = false;
			muerto = true;
			dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
		}
	}
}