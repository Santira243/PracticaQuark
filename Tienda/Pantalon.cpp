#include "Pantalon.h"

Pantalon::Pantalon(int tipo)
{
	if (tipo == 0)
	{
		this->m_name = "Pantalon_comun";
		this->modelo = 0;
	}
	if (tipo == 1)
	{
		this->m_name = "Pantalon_chupin";
		this->modelo = 0;
	}
}

void Pantalon::actualiza_descuento(float* precio_actualizar)
{
	if (this->m_name == "Pantalon_chupin") //chupin
	{
		*precio_actualizar = *precio_actualizar / 1.12;
	}
	if (this->devolver_calidad() == 1) //calidad premium
	{
		*precio_actualizar = *precio_actualizar * 1.3;
	}
}