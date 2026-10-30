#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paciente v)
{
    pnodoCola nuevo = new NodoCola(v);
    if (ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if (!primero)
        primero = nuevo;
    longitud++;
}

Paciente Cola::eliminar()
{
    pnodoCola nodo;
    Paciente v;
    nodo = primero;
    if (!nodo)
        return v;
    primero = nodo->siguiente;
    v = nodo->valor;
    delete nodo;
    if (!primero)
        ultimo = NULL;
    longitud--;
    return v;
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

Paciente Cola::verPrimero()
{
    Paciente v;
    if (!primero)
        return v;
    return primero->valor;
}

int Cola::getLongitud()
{
    return this->longitud;
}

void Cola::vaciar()
{
    while (primero)
        eliminar();
}

Cola::~Cola()
{
    vaciar();
}
