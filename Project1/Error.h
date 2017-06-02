#pragma once
#include <string>

using namespace std;

class Error
{
public:

	Error(string mensaje) : mensaje(mensaje) {};
	~Error();
	string showMensaje() { return mensaje; }

protected:
	string mensaje;
};

