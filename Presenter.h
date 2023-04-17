#ifndef PRESENTER_H
#define PRESENTER_H

class IView;
class Tienda;

class Presenter
{
private:
	IView* m_view = nullptr;
	Tienda* m_tienda = nullptr;
	char tienda_n[20] = "Tienda Nube 2.0";
	char direccion_n[20] = "Campamento 406";

public:
	explicit Presenter(IView* view);
	~Presenter();
	//void pickupWeapon(int option);
	//void getListOfWeaponMenuItems();
	//void shoot();
	//void seeCurrentWeapon();
	//void dropCurrentWeapon();
};
#endif //PRESENTER_H
