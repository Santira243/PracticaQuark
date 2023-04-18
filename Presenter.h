#ifndef PRESENTER_H
#define PRESENTER_H

class IView;
class Tienda;

class Presenter
{
private:
	IView* m_view = nullptr;
	
	char tienda_n[20];
	char direccion_n[20];
	Tienda* m_tienda;
	
public:
	explicit Presenter(IView* view);
	~Presenter();
	Tienda* datos_tienda();
	//void pickupWeapon(int option);
	//void getListOfWeaponMenuItems();
	//void shoot();
	//void seeCurrentWeapon();
	//void dropCurrentWeapon();
};
#endif //PRESENTER_H
