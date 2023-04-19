#include "Presenter.h"
#include "IView.h"
#include "Tienda/Tienda.h"
#include "Tienda/Prenda.h"
#include "Tienda/Vendedor.h"




Presenter::Presenter(IView* view) : m_view(view)
{

	// --------- Inicializamos el ejemplo ----------- //

	//Inicio Tienda
	strcpy_s(tienda_n, 20, "Tienda Nube 2.0");
	strcpy_s(direccion_n, 20, "Campamento 406");
	m_tienda = new Tienda(tienda_n, direccion_n);

	//Cargo Stock
	Prenda manga_c_mao_premium;
	manga_c_mao_premium.pickup(2);
	manga_c_mao_premium.m_calidad(1);
	manga_c_mao_premium.m_cantidad(100);
	m_tienda->agregar_prendas(manga_c_mao_premium);

	Prenda manga_c_mao_standard;
	manga_c_mao_standard.pickup(2);
	manga_c_mao_standard.m_calidad(0);
	manga_c_mao_standard.m_cantidad(100);
	m_tienda->agregar_prendas(manga_c_mao_standard);

	Prenda manga_c_c_standard;
	manga_c_c_standard.pickup(1);
	manga_c_c_standard.m_calidad(0);
	manga_c_c_standard.m_cantidad(150);
	m_tienda->agregar_prendas(manga_c_c_standard);

	Prenda manga_c_c_premium;
	manga_c_c_premium.pickup(1);
	manga_c_c_premium.m_calidad(1);
	manga_c_c_premium.m_cantidad(150);
	m_tienda->agregar_prendas(manga_c_c_premium);

	Prenda manga_l_mao_standard;
	manga_l_mao_standard.pickup(4);
	manga_l_mao_standard.m_calidad(0);
	manga_l_mao_standard.m_cantidad(75);
	m_tienda->agregar_prendas(manga_l_mao_standard);

	Prenda manga_l_mao_premium;
	manga_l_mao_premium.pickup(4);
	manga_l_mao_premium.m_calidad(1);
	manga_l_mao_premium.m_cantidad(75);
	m_tienda->agregar_prendas(manga_l_mao_premium);

	Prenda manga_l_standard;
	manga_l_standard.pickup(3);
	manga_l_standard.m_calidad(0);
	manga_l_standard.m_cantidad(175);
	m_tienda->agregar_prendas(manga_l_standard);

	Prenda manga_l_premium;
	manga_l_premium.pickup(3);
	manga_l_premium.m_calidad(1);
	manga_l_premium.m_cantidad(175);
	m_tienda->agregar_prendas(manga_l_premium);

	Prenda pantalon_chup_standard;
	pantalon_chup_standard.pickup(6);
	pantalon_chup_standard.m_calidad(0);
	pantalon_chup_standard.m_cantidad(750);
	m_tienda->agregar_prendas(pantalon_chup_standard);

	Prenda pantalon_chup_premium;
	pantalon_chup_premium.pickup(6);
	pantalon_chup_premium.m_calidad(1);
	pantalon_chup_premium.m_cantidad(750);
	m_tienda->agregar_prendas(pantalon_chup_premium);

	Prenda pantalon_standard;
	pantalon_standard.pickup(5);
	pantalon_standard.m_calidad(0);
	pantalon_standard.m_cantidad(250);
	m_tienda->agregar_prendas(pantalon_standard);

	Prenda pantalon_premium;
	pantalon_premium.pickup(5);
	pantalon_premium.m_calidad(1);
	pantalon_premium.m_cantidad(250);
	m_tienda->agregar_prendas(pantalon_premium);

	//Agregamos el vendedor y datos de horarios
	char fecha_actual[11];
	char hora_actual[6];
	char nombre_v[10];
	char apellido_v[10];
	strcpy_s(nombre_v, 10, "Vendo");
	strcpy_s(apellido_v, 10, "Mucho");
	strcpy_s(direccion_n, 15, "Alameda 112");
	strcpy_s(fecha_actual, 11, "10/05/1985");
	strcpy_s(hora_actual, 6, "10:30");
	unsigned int id_v = 20;
	Vendedor Uno(nombre_v, apellido_v, id_v);
	m_tienda->agregar_vendedor(Uno);
	unsigned int prenda_nro = 6;
	//Inicializa una cotizacion
	unsigned int cantidad_prendas_a_Cotizar_1 = 4;
	float precio = (float)123.2;
	const char* precio_final = m_tienda->listar_vendedores(0).cotizar(fecha_actual, hora_actual, prenda_nro, precio, cantidad_prendas_a_Cotizar_1);
	presenta_cotizacion cargando_inicializacion;
	cargando_inicializacion.id_m = 0;
	cargando_inicializacion.id_vende_m = id_v;
	cargando_inicializacion.fecha_m = fecha_actual;
	cargando_inicializacion.hora_m = hora_actual;

	//const auto* prenda_a = m_PrendaMenuItems[prenda_nro];
	//std::string nombre_prenda = prenda_a->getName();
	
	// ---------- Fin de Inicializacion ----------- //
}

Presenter::~Presenter()
{
	delete m_tienda;
};

Tienda* Presenter::datos_tienda()
{
	return m_tienda;
}

void Presenter::getListaPrendas()
{
	auto listOfClassConstants = Prenda::getConstants();
	m_view->setPrendasMenuItems(listOfClassConstants); // seteamos en la vista los ítems de menú
}  
