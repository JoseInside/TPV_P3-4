#pragma once
#include "PBBExternAccess.h"
#include "JuegoPG.h"
#include "BouncingBall.h"
#include "PBBVMProg.h"
#include "PBBVM.h"

static PBBVM VM;

class PrBouncingBall : public PBBExternAccess, public BouncingBall
{
public:
	PrBouncingBall(JuegoPG* hereJuego, int x, int y, Texturas_t textura, PBBVMProg* prog);
	~PrBouncingBall();

	bool onClick();
	
	int getPoints() { return puntosObjeto; }
	int getTotalClicks() { return _totalClicks; }
	int getDirectionX() { return _dx; }
	int getDirectionY() { return _dy; }
		
	void setDirectionX(int dx);
	void setDirectionY(int dy);
	void setPoints(int pointsAssigned);
	void addGlobalPoints(int globalPoints);
	void setActive(bool active) ;

protected:

	JuegoPG* obJuego;
	PBBVMProg* programa;

	int _totalClicks;
	int _dx, _dy;
	int points;
};

