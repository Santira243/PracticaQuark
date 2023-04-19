#pragma once
#ifndef TIENDA_H
#define TIENDA_H
#include "Prenda.h"
#include "Vendedor.h"
#include <vector>
using namespace std;

class Tienda
{
private:
	char* nombre;
	char* direccion;
	std::vector <Prenda> prendas_existentes;
	std::vector <Vendedor> vendedores;

public:
	Tienda(char* name, char* direcc);
	void agregar_prendas(Prenda nueva);
	void agregar_vendedor(Vendedor nuevo);
	const char* nombre_tienda();
	const char* direccion_tienda();
	vector<Prenda> listar_prendas();
	Vendedor listar_vendedores(int index);
};
#endif //TIENDA_H
