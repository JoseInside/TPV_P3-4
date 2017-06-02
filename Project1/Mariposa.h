#pragma once
#include "SDL.h"
#include "ObjetoPG.h"


class Mariposa : public ObjetoPG
{
public:
	Mariposa(JuegoPG * hereJuego, int x, int y, Texturas_t textura);
	~Mariposa();

	virtual void draw();
	virtual bool onClick();
	virtual void update();

protected:
	int numClicks = 0;
	int estadoActual = 0;
	const int nEstados = 6;

};

