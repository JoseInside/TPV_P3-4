#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
	typedef void CallBack_t(JuegoPG* jg);

public:
	Boton(JuegoPG* jg, CallBack_t* callback, int px, int py, Texturas_t textur);
	~Boton();

	virtual void draw();
	virtual void update() {};
	virtual bool onClick();

protected:

	CallBack_t* _callBack;
};

