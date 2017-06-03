#pragma once
#include "ObjetoPG.h"
#include "JuegoPG.h"

class Vago : public ObjetoPG
{
public:

	Vago(JuegoPG * juego, int x, int y, Texturas_t t_textura) : ObjetoPG(juego, x, y, t_textura) {};
	~Vago() {};

	bool onClick() { return false; };
	void update() { };
};

