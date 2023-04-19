#include "Vendedor.h"
#include "Cotizacion.h"
#include <string>
#include <iostream>

using namespace std;



const std::string NO_COTIZACION_MESSAGE = "Parece que el vendedor no tiene ninguna cotización...";
const std::string COTIZACION_MESSAGE = "El vendedor ha creado una cotización...";


Vendedor::Vendedor( char* name,  char* lname, unsigned int id)
{
    datos_vendedor.nombre = name;
    nomb = name;
    datos_vendedor.apellido= lname;
    datos_vendedor.id_vendedor = id;
}

bool Vendedor::tiene_cotizacion() 
{
    return list_cotizacion.size();
}

const char* Vendedor::cotizar(char* fecha_actual, char* hora_actual, int prenda, float precio, int cant_prenda)
{
    Cotizacion aux_cotizacion(fecha_actual, hora_actual, prenda, precio, cant_prenda, datos_vendedor.id_vendedor);
    list_cotizacion.push_back(aux_cotizacion);

    
    return COTIZACION_MESSAGE.c_str();
}

const char* Vendedor::listar_cotizaciones()
{
    if (tiene_cotizacion())
    {
        return "Listando...";
    }
    else
    {
        return NO_COTIZACION_MESSAGE.c_str();
    }
}

Vendedor::~Vendedor()
{
}

struct datos* Vendedor::listar_datos_vendedor()
{

    return &datos_vendedor;
}

const char* Vendedor::devolver_apellido()
{
    return datos_vendedor.apellido;
}

const char* Vendedor::devolver_nombre()
{
    return datos_vendedor.nombre;
}