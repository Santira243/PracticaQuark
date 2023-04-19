#pragma once
#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <vector>
#include "Cotizacion.h"

struct datos {   
	  char* nombre;
	  char* apellido;
	  unsigned int id_vendedor;
};


class Vendedor
{
private:
	struct datos datos_vendedor;
	std::vector <Cotizacion> list_cotizacion;
	const char* nomb;

public:
	Vendedor(char* name, char* lname, unsigned int id);
	bool tiene_cotizacion();
	const char* cotizar(char* fecha_actual, char* hora_actual, int prenda, float precio, int cant_prenda);
	struct datos* listar_datos_vendedor();
	const char* listar_cotizaciones();
	const char* devolver_nombre();
	const char* devolver_apellido();
	~Vendedor();
};
#endif