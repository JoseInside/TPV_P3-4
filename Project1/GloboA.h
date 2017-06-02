#ifndef _H_GloboA_H_
#define _H_GloboA_H_

#include "GlobosPG.h"

class GloboA : public GlobosPG
{
public:
	GloboA(JuegoPG * hereJuego, int x, int y, Texturas_t textura);
	virtual ~GloboA();

	virtual void update();

protected:
	const int DP = AP * 2; //Disminución de puntos
};

#endif