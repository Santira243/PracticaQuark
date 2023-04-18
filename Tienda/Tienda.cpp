
#include "Tienda.h"

Tienda::Tienda(char* name, char* direcc)
{
	nombre=name;
	direccion = direcc;
}

void Tienda::agregar_prendas(Prenda nueva)
{
	
	Prendas_existentes.push_back(nueva);
	
}

const char* Tienda::nombre_tienda()
{
	return nombre;
}

const char* Tienda::direccion_tienda()
{
	return direccion;
}

vector<Prenda> Tienda::listar_prendas()
{
	return Prendas_existentes;
}