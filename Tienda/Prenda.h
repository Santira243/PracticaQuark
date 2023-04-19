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
	const char* getName() const;
	void m_calidad(char nueva_calidad);
	char devolver_calidad();
	void m_cantidad(unsigned int valor_stock);
	void m_precio(float precio_nuevo);
	unsigned int devolver_stock();
	float devolver_precio();
	virtual void actualiza_descuento(float* precio_actualizar);
protected:
	const char* m_name=0;
private:
	char calidad=0;	
	float precio_unit=0;
	unsigned int cantidad_stock=0;
};
#endif //PRENDA_H