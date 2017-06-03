#pragma once
#include "TexturasSDL.h"
#include <vector>
#include "ObjetoJuego.h"
#include <stack>
#include "EstadoJuego.h"
#include "Factory.h"
//#include "Factory_BB.h"
//#include "Factory_PG.h"
enum Texturas_t { TFondo, TGlobos, TMariposa, TPremio, TBola, TBPlay, TBExit, TBMenu,
	TBContinue, TBOpciones, TBBouncing, TBGlobos, TNull
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
	int getScreenWidth() { return SCREEN_WIDTH; }
	int getScreenHeight() { return SCREEN_HEIGHT; }


	Factory* getFactory() { return factoria; }
	void setFactory(string type);
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
	
	Factory* factoria;

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

