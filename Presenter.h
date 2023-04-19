#ifndef PRESENTER_H
#define PRESENTER_H
#include <vector>
using namespace std;

class IView;
class Tienda;

struct presenta_cotizacion {
	unsigned int id_m;
	const char* fecha_m;
	const char* hora_m;
	unsigned int id_vende_m;
	const char* prenda_m;
	float precio_m;
	int cantidad_m;
	float precio_f;
};

class Presenter
{
private:
	IView* m_view = nullptr;
	char tienda_n[20];
	char direccion_n[20];
	Tienda* m_tienda;
	std::vector <presenta_cotizacion> coti_mostrar;
	
public:
	explicit Presenter(IView* view);
	~Presenter();
	Tienda* datos_tienda();
	void getListaPrendas();

};
#endif //PRESENTER_H
