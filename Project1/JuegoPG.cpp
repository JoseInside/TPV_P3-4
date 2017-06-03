#include "JuegoPG.h"
#include "SDL.h"
#include <iostream>
#include <vector>
#include "GlobosPG.h"
#include <time.h>
#include "Mariposa.h"
#include "Premio.h"
#include "GloboA.h"
#include "EstadoJuego.h"
#include "MenuPG.h"
#include "Pausa.h"
#include "Factory_BB.h"
#include "Factory_PG.h"

using namespace std;

JuegoPG::JuegoPG()
{  
	puntos = 0;
	gameOver = false;
	error = false;
	exit = false;
	pausa = false;
	globos = 2;

	aux.x = 0;
	aux.y = 0;
	aux.h = SCREEN_HEIGHT;
	aux.w = SCREEN_WIDTH;

	initSDL();
	initMedia();
	setFactory("PlayPG");
	states.push(new MenuPG(this));

}


JuegoPG::~JuegoPG()
{
	closeMedia();
	closeSDL();
}


void JuegoPG::run() {

	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		render();
		handle_event();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
			"EL PINCHA GLOBOS", "Preparado?\n Pulsa 'OK' cuando estes listo!", nullptr);
		while (!exit && !gameOver) {
			
			srand(SDL_GetTicks());

			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				// while (elapsed >= MSxUpdate) 
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event();
			if (globos == 0)
				gameOver = true;
		}
		if (exit) cout << "EXIT \n";
		SDL_Delay(1000); 
	}
}

bool JuegoPG::initSDL(){
	
	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWin = SDL_CreateWindow("GLOBOS_TPV ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWin == nullptr){
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRender == nullptr){
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

void JuegoPG::initMedia() {

	srand(time(NULL));

	archText.push_back("..\\bmps\\fondo.png");
	archText.push_back("..\\bmps\\globo.png");
	archText.push_back("..\\bmps\\mariposa.png");
	archText.push_back("..\\bmps\\premio.png");
	archText.push_back("..\\bmps\\bola.png");
	archText.push_back("..\\bmps\\play.png");
	archText.push_back("..\\bmps\\salir.png");
	archText.push_back("..\\bmps\\menu.png");
	archText.push_back("..\\bmps\\continuar.png");
	archText.push_back("..\\bmps\\options.png");
	archText.push_back("..\\bmps\\bouncing_ball.png");
	archText.push_back("..\\bmps\\globos.png");

	//Cargamos las texturas (fondo, globos, mariposas y premio)
	for (int j = 0; j < archText.size(); ++j) {

		pTexture = new TexturasSDL;
		pTexture->load(pRender, archText[j]);
		vTexturas.push_back(pTexture);
	}
}

void JuegoPG::closeMedia() {
	for (int j = 0; j < vTexturas.size(); ++j)
		delete vTexturas[j];
}

void JuegoPG::closeSDL () {

	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}



void JuegoPG::render(){

	SDL_RenderClear(pRender);
	
	//Primero pintamos el fondo
	vTexturas[0]->draw(pRender,aux);

	/*for (int i = 0; i < vObjetos.size(); ++i){
		vObjetos[i]->draw();
	}*/

	topEstado()->draw();

	SDL_RenderPresent(pRender);
}

void JuegoPG::onClick(int pmx, int pmy) {
	
	//int i = vObjetos.size() - 1;
	//bool pinchado = false;
	px = pmx;
	py = pmy;
	topEstado()->onClick();

	/*while (i >= 0 && !pinchado){
		if (vObjetos[i]->onClick()){
			pinchado = true;
			i = vObjetos.size() - 1;
		}
		else i--;
	}*/

}

void JuegoPG::getMousePos(int &mpx, int &mpy) const{
	
	if (px == -1 || py == -1){
		cout << "Error: mouse position not defined" << "\n";
	}
	else{
		mpx = px;
		mpy = py;
	}
}

void JuegoPG::update() {
	
	topEstado()->update();

	/*if (!pausa)
	{
		for (int i = 0; i < vObjetos.size(); ++i){
			vObjetos[i]->update();
		}
	}*/
}

void JuegoPG::handle_event(){
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) exit = true;
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK\n";
				onClick(e.button.x, e.button.y);
			}
		}
		if (e.type == SDL_KEYUP) {
			if (e.key.keysym.sym == SDLK_p){
				pausa = !pausa;
				pushState(new Pausa(this));
			}
		}
	}
}

EstadoJuego * JuegoPG::topEstado() {
	return states.top();
}

void JuegoPG::changeState(EstadoJuego* newSt) {
	popState();
	pushState(newSt);
}

void JuegoPG::pushState(EstadoJuego* newState) {
	states.push(newState);
}

void JuegoPG::popState() {
	states.pop();
}

void JuegoPG::setSalir() {
	exit = true;
	closeSDL();

}

void JuegoPG::setPoints(int i) {
	puntos += i;
}

int JuegoPG::getPoints() {
	return puntos;
}

void JuegoPG::setFactory(string type) {
	
	if (type == "PlayBounce")
		factoria = new Factory_BB(this);
	else if(type == "PlayPG")
		factoria = new Factory_PG(this);
}