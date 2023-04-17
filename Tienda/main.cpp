#include "Vendedor.h"
#include <string.h>
#include "iostream"
#include "stdio.h"
#include "Tienda.h"
#include "Prenda.h"
#include <chrono>

using namespace std;
char fecha_actual[11];
char hora_actual[6];

int main()
{
    char nombre_v[10];
    char apellido_v[10];
    char tienda_n[15];
    char direccion_n[15];
    strcpy_s(nombre_v, 10, "Hola");
    strcpy_s(apellido_v, 10, "Bola");
    strcpy_s(tienda_n, 15, "Tienda Nube");
    strcpy_s(direccion_n, 15, "Alameda 112");
    strcpy_s(fecha_actual, 11, "10/05/1985");
    strcpy_s(hora_actual, 6, "10:30");
    Tienda* Tiendita = new Tienda(tienda_n, direccion_n);
    Vendedor* Uno = new Vendedor(nombre_v, apellido_v, 2);
    cout << "Tienda creada: " << Tiendita->nombre_tienda() << " ";
    Prenda* nuevo_chupin;

    nuevo_chupin = Prenda::pickup(6);
    nuevo_chupin->m_cantidad(19);
    nuevo_chupin->m_calidad(0);
    float precio = (float)123.2;
    float* actualizar = &precio;
    nuevo_chupin->actualiza_descuento(actualizar);
    cout << "Precio antes: " << "123.2" << "precio despues ... " << precio;
    cout << "Cantidad de chupines: " << nuevo_chupin->devolver_stock();

    // debería instanciar una de las clases polimorficas... 
    //agregar_prendas(Prenda nueva);
    cout << Uno->listar_datos_vendedor().nombre << " ";
    cout << Uno->listar_datos_vendedor().apellido<< " ";
    cout << Uno->listar_datos_vendedor().id_vendedor;
    cin.get();
    cout << Uno->cotizar(fecha_actual, hora_actual, 6, (float)123.2, 3) << " ";
    cin.get();
    cout << Uno->listar_cotizaciones();
    delete Tiendita;
    delete Uno;

    return 0;
}

