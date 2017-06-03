#include "Factory_BB.h"
#include "BouncingBall.h"
#include "Vago.h"



Factory_BB::Factory_BB(JuegoPG* ju)
{
	jue = ju;
}


Factory_BB::~Factory_BB()
{
}


ObjetoJuego*Factory_BB::createNormalElement()
{
	return new BouncingBall(jue, rand() % 700, rand() % 700, Texturas_t::TBola);
}

ObjetoJuego*Factory_BB::createSpecialElement()
{
	return new Vago(jue, 0, 0, Texturas_t::TNull);
}

ObjetoJuego*Factory_BB::createPrizeElement()
{
	return new Vago(jue, 0, 0, Texturas_t::TNull);
}
