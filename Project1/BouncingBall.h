#pragma once
#include "ObjetoPG.h"

class BouncingBall : public ObjetoPG
{
public:
	BouncingBall(JuegoPG* juego, int x, int y, Texturas_t text);
	~BouncingBall();


	bool onClick();
	void update();

protected:

	bool choqueBorders();
	int dx, dy;
	SDL_Rect aux;
};

