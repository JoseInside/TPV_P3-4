#pragma once
#include "SDL.h"
#include "ObjetoPG.h"

class Premio : public ObjetoPG
{
public:
	Premio(JuegoPG * hereJuego, int x, int y, Texturas_t textura);
	~Premio();
	int numIntentos = 3;
	int PP = 100; //Puntos de Premio Iniciales

	virtual bool onClick();
	virtual void update();
	void reinicia();
};

