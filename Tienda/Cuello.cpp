#include "Cuello.h"

Cuello::Cuello(int aux)
{
	if (aux == 0)
		this->modelo = "normal";
	if (aux == 1)
		this->modelo = "mao";

}
const char* Cuello::caracteristica()
{
	return modelo;
}