#include "TexturasSDL.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "JuegoPG.h"

using namespace std;


TexturasSDL::~TexturasSDL()
{
	//pRender = nullptr;
	SDL_DestroyTexture(textura);
}


bool TexturasSDL::load(SDL_Renderer* pRender, string const& nombArch){
	

	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load image
	//pTempSurface = SDL_LoadBMP(bmpName.c_str());  // si usamos string: bmpName.c_str() 
	pTempSurface = IMG_Load(nombArch.c_str());
	
	if (pTempSurface == nullptr) {
		cout << "Unable to load image " << nombArch << "! \nSDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		SDL_DestroyTexture(textura);
		textura = SDL_CreateTextureFromSurface(pRender, pTempSurface);
		rectText = pTempSurface->clip_rect;
		rectText.w = rectText.w / 6;
		SDL_FreeSurface(pTempSurface);
		success = textura != nullptr;
		
	}

	return success;
}

void TexturasSDL::draw(SDL_Renderer* pRender, SDL_Rect const& rect){
	
	// Draw objets 
	SDL_RenderCopy(pRender, textura, nullptr, &rect);  // nullptr, nullptr -> toda la textura en toda la ventana

}

//Animaci�n + dibujado de la mariposa 
void TexturasSDL::animacion(int nEstados, int estadoActual, SDL_Renderer* pRender, SDL_Rect const& rect) {
	
	this->rectText.x = this->rectText.w * estadoActual;
	SDL_RenderCopy(pRender, textura, &rectText, &rect);

}



