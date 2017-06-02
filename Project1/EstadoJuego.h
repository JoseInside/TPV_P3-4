#pragma once
#include "SDL.h"
#include <vector>

enum GAME_STATES { MENU_PRINCIPAL, GAME_OVER, PAUSE, PLAY };

class EstadoJuego
{
public:

	EstadoJuego() {}

	virtual ~EstadoJuego() {}

	virtual void draw() = 0;

	virtual void onClick() = 0;
	
	virtual void update() = 0;


//	virtual GAME_STATES getCurrentState() = 0;

	//virtual void changeCurrentState(GAME_STATES newType) = 0;

};

