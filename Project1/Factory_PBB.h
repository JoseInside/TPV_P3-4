#pragma once
#include "Factory.h"
#include "JuegoPG.h"
#include "PrBouncingBall.h"
#include "Vago.h"

class Factory_PBB : public Factory
{
public:

public:

	Factory_PBB(JuegoPG* jg) : obJuego(jg) {}

	~Factory_PBB() {};

	ObjetoJuego* createNormalElement() {

		x = rand() % obJuego->getScreenWidth();
		y = rand() % obJuego->getScreenHeight();

		_prog = new PBBVMProg(rand() % 10 > 4 ? "..\\Project1\\prog1.vm" : "..\\Project1\\prog2.vm");
		return new PrBouncingBall(obJuego, x, y, Texturas_t::TBola, _prog);
	}

	ObjetoJuego* createSpecialElement() { return new Vago(obJuego, 0, 0, Texturas_t::TNull); }
	ObjetoJuego* createPrizeElement() { return new Vago(obJuego, 0, 0, Texturas_t::TNull); }

protected:

	JuegoPG* obJuego;
	int x, y;
	PBBVMProg* _prog;

};

