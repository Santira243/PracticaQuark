#include "Prenda_factory.h"
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <algorithm>

PrendaFactory::PrendaFactory() = default;

Prenda* PrendaFactory::GetPrenda(PrendaType prendaSelected)
{
	auto prendas = getPrendaList();
	if (prendas.count(prendaSelected) == 0) {
		return nullptr;
	}
	auto item = prendas[prendaSelected];
	return item;
}

std::map<PrendaType, Prenda*> PrendaFactory::getPrendaList()
{
	
	auto camisa_manga_c = new Camisa(0);
	auto camisa_manga_c_mao = new Camisa(1);
	auto camisa_manga_l = new Camisa(2);
	auto camisa_manga_l_mao = new Camisa(3);
	auto pantalon = new Pantalon(0);
	auto pantalon_chup = new Pantalon(1);
	
	return std::map<PrendaType, Prenda*> {
		{ PrendaType::Camisa_manga_c, camisa_manga_c},
		{ PrendaType::Camisa_manga_c_mao,    camisa_manga_c_mao },
		{ PrendaType::Camisa_manga_l,  camisa_manga_l },
		{ PrendaType::Camisa_manga_l_mao,  camisa_manga_l_mao },
		{ PrendaType::Pantalon,  pantalon },
		{ PrendaType::Pantalon_chup,  pantalon_chup },
	};
}
