#include "PrBouncingBall.h"
#include "PlayPG.h"


PrBouncingBall::PrBouncingBall(JuegoPG* hereJuego, int x, int y, Texturas_t textura, PBBVMProg* prog) : BouncingBall(hereJuego, x, y, textura)
{
	obJuego = hereJuego;
	rect.x = x;
	rect.y = y;

	programa = prog;

	tipoTextura = textura;
	visible = true;
	
}


PrBouncingBall::~PrBouncingBall()
{
}

bool PrBouncingBall::onClick()
{

	int posX, posY;
	obJuego->getMousePos(posX, posY);

	if (dentro(posX, posY)) {
		_totalClicks++;
		VM.run(*programa, *this);
		return true;
	}
	
	return false;
}


void PrBouncingBall::setDirectionX(int dx)
{
	_dx = dx;
}

void PrBouncingBall::setDirectionY(int dy)
{
	_dy = dy;
}

void PrBouncingBall::setPoints(int pointsAssigned)
{
	puntosObjeto = pointsAssigned;
}

void PrBouncingBall::addGlobalPoints(int globalPoints)
{
	obJuego->setPoints(globalPoints);
}

void PrBouncingBall::setActive(bool active)
{
	muerto = true;
	visible = false;
	dynamic_cast<PlayPG*>(obJuego->topEstado())->newBaja(this);
}
