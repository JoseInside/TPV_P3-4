#pragma once
#include "EstadoPG.h"
class PlayPG : public EstadoPG
{
public:

	PlayPG(JuegoPG * juego);
	~PlayPG();

	void update();
	
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);


protected:

	void initObjetos();
	void freeObjetos();

	int globos, puntos;
	const int globosTotales = 2;	//Numero de globos totales (NG)
	const int mariTotales = 2;		//Numero de mariposas totales
	const int premioTotales = 2;	//Numero de premios totales
	const int bolasTotales = 2;
	/*int numglobos;
	int numglobosA;
	int finglobos;
	int points;*/

};

