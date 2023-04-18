#include "Presenter.h"
#include "IView.h"
#include "Tienda/Tienda.h"


Presenter::Presenter(IView* view) : m_view(view)  //INICIALIZADA PARA ESTE EJEMPLO.
{
	strcpy_s(tienda_n, 20, "Tienda Nube 2.0");
	strcpy_s(direccion_n, 20, "Campamento 406");
	m_tienda = new Tienda(tienda_n, direccion_n);
}

Presenter::~Presenter()
{
	delete m_tienda;
};

Tienda* Presenter::datos_tienda()
{
	return m_tienda;
}
/*
void Presenter::shoot()
{
	const char* behaviour = m_soldier->shoot();
	m_view->showText(behaviour);
}

void Presenter::seeCurrentWeapon()
{
	const char* behaviour = m_soldier->seeCurrentWeapon();
	m_view->showText(behaviour);
}

void Presenter::dropCurrentWeapon()
{
	const char* behaviour = m_soldier->dropCurrentWeapon();
	m_view->showText(behaviour);
}

void Presenter::pickupWeapon(int option)
{
	std::system("cls");
	const char* behaviour = m_soldier->pickupWeapon(option);
	m_view->showText(behaviour);
}

void Presenter::getListOfWeaponMenuItems()
{
	auto listOfClassConstants = Weapon::getConstants();
	m_view->setWeaponMenuItems(listOfClassConstants); // seteamos en la vista los ítems de menú
}
*/