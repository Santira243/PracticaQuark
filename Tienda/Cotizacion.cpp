#include "Prenda.h"
#include "Cotizacion.h"



Cotizacion::Cotizacion(char* a_fecha, char* a_hora, int prenda_option, float a_precio, int a_cantidad, int a_id_vendedor)
{

    fecha = a_fecha;
    hora = a_hora;
    prenda_a_coti = Prenda::pickup(prenda_option);
    cantidad_prendas = a_cantidad;
    monto_total = a_precio * cantidad_prendas;
    float* actualizar = &monto_total;
    prenda_a_coti->actualiza_descuento(actualizar); //actualiza monto total al precio con descuento. 
    id_vendedor = a_id_vendedor;
}


float Cotizacion::resultado()
{
    return monto_total;
}

const char* Cotizacion::prenda_cotizada()
{
    return prenda_a_coti->getName();
}

Cotizacion::~Cotizacion()
{
}
