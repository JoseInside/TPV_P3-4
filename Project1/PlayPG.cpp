#include "PlayPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "Premio.h"
#include "Mariposa.h"
#include "GameOver.h"


PlayPG::PlayPG(JuegoPG * juego) : EstadoPG(juego)
{
	initObjetos();
}


PlayPG::~PlayPG()
{
	freeObjetos();
}



void PlayPG::newBaja(ObjetoJuego* po) {
	if (typeid(*po) == typeid(GlobosPG) || typeid(*po) == typeid(GloboA)) {
		--globos;
	}
	else if (typeid(*po) == typeid(Mariposa)) {
		newPremio(po);
	}
	else if (typeid(*po) == typeid(Premio)) {
		dynamic_cast<Premio*>(po)->reinicia();
	}
}

void PlayPG::newPuntos(ObjetoJuego * po) {
	if (typeid(*po) == typeid(GlobosPG) || typeid(*po) == typeid(GloboA)) {
		obJuego->setPoints(dynamic_cast<GlobosPG*>(po)->valorGlobo);
	}
	else if (typeid(*po) == typeid(Premio)) {
		obJuego->setPoints(dynamic_cast<Premio*>(po)->PP);
	}
}

void PlayPG::newPremio(ObjetoJuego* po) {

	//Contador hacia atr�s para leer los premios
	int atras = arrayObjetos.size() - 1;
	po = arrayObjetos[atras];

	//Contador tradicional para leer los premios totales
	int cont = 0;
	bool activado = false;


	while (cont < premioTotales && !activado) {
		//Comprobamos primero si se trata de un premio
		if (typeid(*po) != typeid(Premio)) {
			atras--;
			po = arrayObjetos[atras];
		}
		//Si es as�, comprobamos que tal premio no est� ya activado
		else if (dynamic_cast<Premio*>(po)->visible == true) {
			atras--;
			po = arrayObjetos[atras];
		}
		//Si se dan ambas condiciones, activamos el premio en cuesti�n
		else {
			dynamic_cast<Premio*>(po)->visible = true;
			activado = true;
		}
	}
}
/*void PlayPG::newBaja(ObjetoJuego* po) {
	if (static_cast<ObjetoPG*>(po) != nullptr)
		finglobos--;
}

void PlayPG::newPuntos(ObjetoJuego* po) {

	points += static_cast<ObjetoPG*>(po)->damePuntos();

}

void PlayPG::newPremio() {
	dynamic_cast<Premio*>(arrayObjetos[numglobos + numglobosA])->reiniciaPremio();
}*/



void PlayPG::initObjetos() {

	int x, y;

	puntos = 0;
	globos = globosTotales;

	for (int i = 0; i < globosTotales; ++i) {
		x = rand() % 610;
		y = rand() % 420;

		if (rand() % 100 < 50) {
			ObjetoJuego* unGlobo = new GloboA(obJuego, x, y, TGlobos);
			arrayObjetos.push_back(unGlobo);
		}
		else {
			ObjetoJuego* unGlobo = new GlobosPG(obJuego, x, y, TGlobos);
			arrayObjetos.push_back(unGlobo);
		}

	}

	for (int cont = 0; cont < mariTotales; cont++) {
		x = rand() % 610;
		y = rand() % 420;
		ObjetoJuego* mariposa = new Mariposa(obJuego, x, y, TMariposa);
		arrayObjetos.push_back(mariposa);
	}

	for (int w = 0; w < premioTotales; w++) {
		x = rand() % 610;
		y = rand() % 420;
		ObjetoJuego* premio = new Premio(obJuego, x, y, TPremio);
		arrayObjetos.push_back(premio);
	}

/*	if (i == arrayObjetos.size())
		return true;
	else return false;*/

}


void PlayPG::freeObjetos() {

	for (int i = 0; i < arrayObjetos.size(); ++i)
		delete arrayObjetos[i];
}

/*
void JuegoPG::update() {

	if (!pausa)
	{
		for (int i = 0; i < vObjetos.size(); ++i) {
			vObjetos[i]->update();
		}
	}
}*/

void PlayPG::update() {

	if (globos == 0) {

		obJuego->changeState(new GameOver(obJuego));

	}
	else
		EstadoPG::update();
}
