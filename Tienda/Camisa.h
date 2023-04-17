#pragma once
#ifndef CAMISA_H
#define CAMISA_H

#include "Prenda.h"
#include "Cuello.h"

class Camisa : public Prenda
{
private:
	Cuello* cuello;
	bool manga;
	int descuento;
public:
	Camisa(int tipo);
	// Inherited via Prenda
	void actualiza_descuento(float* precio_actualizar) override;
};
#endif //CAMISA_H
