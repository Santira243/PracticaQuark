#pragma once
#ifndef COTIZACION_H
#define COTIZACION_H

class Prenda; 

class Cotizacion
{
private:
	char* fecha;
	char* hora;
	Prenda* prenda_a_coti;
	int cantidad_prendas;
	float monto_total;
	unsigned int id_vendedor;
public:
	Cotizacion(char* a_fecha, char* a_hora, int prenda_option, float a_precio, int a_cantidad, int a_id_vendedor);
	const char* prenda_cotizada();
	float resultado();
	~Cotizacion();
};
#endif