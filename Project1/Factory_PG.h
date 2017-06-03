#pragma once
#include "Factory.h"
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"
#include "JuegoPG.h"

class Factory_PG : public Factory
{
public:

	Factory_PG(JuegoPG* jg) : obJuego(jg) {}

	virtual ~Factory_PG() {}


	ObjetoJuego* createNormalElement() {
		x = rand() % obJuego->getScreenWidth();
		y = rand() % obJuego->getScreenHeight();

		return new GlobosPG(obJuego, x, y, Texturas_t::TGlobos); 
	}
	ObjetoJuego* createSpecialElement() { 
		x = rand() % obJuego->getScreenWidth();
		y = rand() % obJuego->getScreenHeight();

		return new Mariposa(obJuego, x, y, Texturas_t::TMariposa); 
	}
	ObjetoJuego* createPrizeElement() {
		x = rand() % obJuego->getScreenWidth();
		y = rand() % obJuego->getScreenHeight();

		return new Premio(obJuego, x, y, Texturas_t::TPremio); 
	}

	JuegoPG* obJuego;
	int x, y;
protected:

};

