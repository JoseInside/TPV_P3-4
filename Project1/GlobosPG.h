#ifndef _H_GlobosPG_H_
#define _H_GlobosPG_H_
#include "ObjetoPG.h"

class GlobosPG : public ObjetoPG
{
public:
	
	GlobosPG(JuegoPG * hereJuego, int x, int y, Texturas_t textura);
	virtual ~GlobosPG();

	//bool muerto;
	//int puntosObjeto = 10;

	virtual bool onClick();
	virtual void update();

protected:
	 
	static const int DT = 5;	// Disminución de tamaño
	static const int AP = 5;	// Aumento de puntos
	static const int PVIS = 70; // Probabilidad Visibles
	static const int PDES = 30; // Probabilidad Desinflados
};

#endif