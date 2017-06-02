#pragma once
#include "EstadoJuego.h"
#include "JuegoPG.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG(JuegoPG* ptr);
	virtual ~EstadoPG();

	virtual void draw();
	virtual void onClick();
	virtual void update();

protected:
	JuegoPG* obJuego;
	SDL_Renderer* pRender;
	TexturasSDL* textura;
	std::vector<ObjetoJuego*> arrayObjetos;
};

