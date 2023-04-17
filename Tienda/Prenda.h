#pragma once
#ifndef PRENDA_H
#define PRENDA_H

#include <map>
#include "Prenda_Factory.h"

class Prenda
{
	friend class Camisa;
	friend class Pantalon;
	
public:
	virtual ~Prenda() = default;
	static Prenda* pickup(int prendaSelected);
	static std::map<PrendaType, Prenda*> getConstants();
	const char* getName();
	void m_calidad(char nueva_calidad);
	char devolver_calidad();
	void m_cantidad(unsigned int valor_stock);
	void m_precio(float precio_nuevo);
	unsigned int devolver_stock();
	float devolver_precio();
	virtual void actualiza_descuento(float* precio_actualizar);
protected:
	const char* m_name;
private:
	char calidad=0;	
	float precio_unit;
	unsigned int cantidad_stock;
};
#endif //PRENDA_H