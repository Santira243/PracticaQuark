#include "Prenda.h"
#include "Prenda_factory.h"

Prenda* Prenda::pickup(int prendaSelected)
{
	return PrendaFactory::GetPrenda((PrendaType)prendaSelected);
}

std::map<PrendaType, Prenda*> Prenda::getConstants()
{
	return PrendaFactory::getPrendaList();
}

const char* Prenda::getName() const
{
	return m_name;
}

void Prenda::m_calidad(char nueva_calidad) {
	calidad = nueva_calidad;
}


char Prenda::devolver_calidad() {
	return calidad;
}
void Prenda::m_cantidad(unsigned int valor_stock) {
	cantidad_stock = valor_stock;
}

void Prenda::m_precio(float precio_nuevo) {
	precio_unit = precio_nuevo;
}
unsigned int Prenda::devolver_stock() {
	return cantidad_stock;
}

float Prenda::devolver_precio() {
	return precio_unit;
}

void Prenda::actualiza_descuento(float* precio_actualizar)
{
	if (this->devolver_calidad() == 1) //calidad premium
	{
		*precio_actualizar = *precio_actualizar * 1.3;
	}
}