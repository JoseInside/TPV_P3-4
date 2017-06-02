#pragma once
#include "TexturasSDL.h"
#include <vector>
#include "ObjetoJuego.h"
#include <stack>
#include "EstadoJuego.h"

enum Texturas_t { TFondo = 0, TGlobos = 1, TMariposa = 2, TPremio = 3, TBPlay = 4, TBExit = 5, TBMenu = 6,
	TBContinue = 7, TBPuntos = 8
};


class JuegoPG
{
public:
		
	JuegoPG();
	~JuegoPG();
	void run();
	bool error;

	TexturasSDL* getTextura(Texturas_t et) const { return vTexturas[et]; };
	SDL_Renderer* getRender() const { return pRender; };
	void getMousePos(int &mpx, int &mpy) const;
	void setPoints(int i);
	int getPoints();
	int getGlobos() { return globos; }

//	void newBaja(ObjetoJuego* po);	 // Los objetos informarán al juego cuando causen baja
	//void newPuntos(ObjetoJuego* po); // Los objetos informarán al juego cuando se obtengan puntos
	//void newPremio(ObjetoJuego* po); // Los objetos informará al juego cuando se obtenga un premio

	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	EstadoJuego* topEstado();
	void popState();
	void setSalir();

private:

	SDL_Rect aux;						//Rectángulo auxiliar para el fondo
	SDL_Window * pWin;					//La ventana donde se mostrará el render
	SDL_Renderer * pRender;				//Render
	TexturasSDL * pTexture;				//La imagen (globos.png) que mostraremos por ventana
	TexturasSDL * fondo;				//El fondo de pantalla en el juego


	int globos, puntos;
	bool exit, gameOver, pausa;
	int px = -1, py = -1;
	vector <string> archText;
	vector <ObjetoJuego*> vObjetos;
	vector <TexturasSDL*>  vTexturas;

	const int SCREEN_WIDTH = 640;   //Ancho de ventana
	const int SCREEN_HEIGHT = 480;  //Alto de ventana
	

	bool initSDL();
	void closeSDL();
	//bool initObjetos();
	//void freeObjetos();
	void initMedia();
	void closeMedia();
	void render();
	void onClick(int pmx, int pmy);
	void update();
	void handle_event();

	stack<EstadoJuego*> states;	//Pila de Estados

};

