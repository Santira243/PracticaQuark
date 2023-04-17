#pragma once
#ifndef VENDEDOR_H
#define VENDEDOR_H

class Cotizacion;

struct datos {   
	const char* nombre;  
	const char* apellido;
	unsigned int id_vendedor;
} ;

class Vendedor
{
private:
	struct datos datos_vendedor;
	Cotizacion* m_cotizacion; 

public:
	Vendedor(char* name, char* lname, unsigned int id);
	bool tiene_cotizacion() const;
	const char* cotizar(char* fecha_actual, char* hora_actual, int prenda, float precio, int cant_prenda);
	datos listar_datos_vendedor();
	const char* listar_cotizaciones();
	const char* modificar_vendedor() ;
	~Vendedor();
};
#endif