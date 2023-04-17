#pragma once
#ifndef PANTALON_H
#define PANTALON_H

#include "Prenda.h"


class Pantalon : public Prenda
{
private:
	int modelo;
	int descuento;
public:
	Pantalon(int tipo);
	void actualiza_descuento(float* precio_actualizar) override;
};
#endif //PANTALON_H