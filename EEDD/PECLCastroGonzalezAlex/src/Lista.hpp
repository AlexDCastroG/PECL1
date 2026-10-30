#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    void insertarOrden(Paciente v);
    void mostrar();
    Paciente getMayorPrioridad();
    Paciente getMenorPrioridad();
    int getLongitud();
    bool estaVacia();
    void vaciar();

private:
    pnodoLista primero;
    int longitud;
};

#endif