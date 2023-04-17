#include "Camisa.h"

Camisa::Camisa(int tipo)
{
	if (tipo == 0)
	{
		this->m_name = "Camisa_manga_corta_cuello_normal";
		this->manga = 0;
		this->cuello = new Cuello(0);
	}
	else
	{
		if (tipo == 1)
		{
			this->m_name = "Camisa_manga_corta_mao";
			this->manga = 0;
			this->cuello = new Cuello(1);
		}

		else

		{
			if (tipo == 2)
			{
				this->m_name = "Camisa_manga_larga_cuello_normal";
				this->manga = 1;
				this->cuello = new Cuello(0);
			}
			else

			{
				if (tipo == 3)
				{
					this->m_name = "Camisa_manga_larga_mao";
					this->manga = 1;
					this->cuello = new Cuello(1);
				}
				else
				{
					this->m_name = "Error";
					this->manga = 0;
					this->cuello = new Cuello(0);
				}
			}
		}
	}
}

void Camisa::actualiza_descuento(float* precio_actualizar)
{
	if (this->manga == 0) //manda corta
	{
		*precio_actualizar = *precio_actualizar / 1.10;
	}
	if (this->cuello->caracteristica() == "mao")
	{
		*precio_actualizar = *precio_actualizar * 1.03;
	}
	if (this->devolver_calidad()== 1) //calidad premium
	{
		*precio_actualizar = *precio_actualizar * 1.3;
	}
}