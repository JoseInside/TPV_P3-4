#pragma once
#include "JuegoPG.h"
#include "EstadoPG.h"

class Pausa : public EstadoPG
{
public:
	Pausa(JuegoPG* jg);
	~Pausa();

protected:

	static void continuar(JuegoPG * jg);
	static void menu(JuegoPG * jg);
};

