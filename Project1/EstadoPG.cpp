#include "EstadoPG.h"



EstadoPG::EstadoPG(JuegoPG* jg) : obJuego(jg) {

}


EstadoPG::~EstadoPG()
{
}


void EstadoPG::draw() {
	
	for (int i = 0; i < arrayObjetos.size(); i++) {
		arrayObjetos[i]->draw();
	}

}

void EstadoPG::onClick() {
	
	bool click = false;
	int i = 0;

	while (i < arrayObjetos.size() && !click) {
		if (arrayObjetos[i]->onClick()) {
			click = true;
		}
		i++;
	}
}

void EstadoPG::update() {
	
	for (int i = 0; i < arrayObjetos.size(); i++) {
		arrayObjetos[i]->update();
	}
}