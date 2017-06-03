#pragma once
#include "Factory.h"
#include "JuegoPG.h"
#include "BouncingBall.h"
#include "Vago.h"

class Factory_BB : public Factory
{

public:

	Factory_BB(JuegoPG* jg) : obJuego(jg) {}

	~Factory_BB() {};


	ObjetoJuego* createNormalElement() {
		
		x = rand() % obJuego->getScreenWidth();
		y = rand() % obJuego->getScreenHeight();

		return new BouncingBall(obJuego, x, y, Texturas_t::TBola); 
	}

	ObjetoJuego* createSpecialElement(){ return new Vago(obJuego, 0, 0, Texturas_t::TNull); }
	ObjetoJuego* createPrizeElement(){ return new Vago(obJuego, 0, 0, Texturas_t::TNull); }

protected:

	JuegoPG* obJuego;
	int x, y;

};