
#include "Tienda.h"

Tienda::Tienda(char* name, char* direcc)
{
	nombre=name;
	direccion = direcc;
}

void Tienda::agregar_prendas(Prenda nueva)
{
	
	prendas_existentes.push_back(nueva);
	
}

void Tienda::agregar_vendedor(Vendedor nuevo)
{

	vendedores.push_back(nuevo);

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
	return prendas_existentes;
}

Vendedor Tienda::listar_vendedores(int index)
{
	 return vendedores[index];
}