#pragma once
#include"Cotizacion.h"

class Lista_cotizaciones {
private:
    class Nodo {
    public:
        Cotizacion cotizado;
        Nodo* sig;
    };

    Nodo* raiz;
public:
    Lista_cotizaciones();
    ~Lista_cotizaciones();
    int cantidad();
    void insertar(int pos, int x);
    int extraer(int pos);
    void borrar(int pos);
    bool existe(int x);
};