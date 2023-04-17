#pragma once
#ifndef PRENDA_FACTORY_H
#define PRENDA_FACTORY_H
#include <map>

class Prenda;
enum class PrendaType { Camisa_manga_c = 1, Camisa_manga_c_mao, Camisa_manga_l, Camisa_manga_l_mao, Pantalon, Pantalon_chup};

class PrendaFactory
{
public:
	PrendaFactory();
	~PrendaFactory() = default;
	static Prenda* GetPrenda(PrendaType PrendaSelected);
	static std::map<PrendaType, Prenda*> getPrendaList();
};
#endif 
