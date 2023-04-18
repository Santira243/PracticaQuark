#pragma once
#ifndef TIENDA_H
#define TIENDA_H
#include <vector>

#include "Prenda.h"
using namespace std;

class Tienda
{
private:
	char* nombre;
	char* direccion;
	vector<Prenda> Prendas_existentes;

public:
	Tienda(char* name, char* direcc);
	void agregar_prendas(Prenda nueva);
	const char* nombre_tienda();
	const char* direccion_tienda();
	vector<Prenda> listar_prendas();
	//void eliminar_prendas();
	//modificar_tienda();
	
};
#endif //TIENDA_H
