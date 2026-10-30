#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    longitud = 0;
}

void Lista::insertarOrden(Paciente v)
{
    pnodoLista nuevo = new NodoLista(v);

    if (!primero || v.getId() > primero->valor.getId()) {
        nuevo->siguiente = primero;
        primero = nuevo;
    } else {
        pnodoLista aux = primero;
        while (aux->siguiente && aux->siguiente->valor.getId() > v.getId()) {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    longitud++;
}

void Lista::mostrar()
{
    pnodoLista aux = primero;
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

Paciente Lista::getMayorPrioridad()
{
    Paciente v;
    if (primero)
        return primero->valor;
    return v;
}

Paciente Lista::getMenorPrioridad()
{
    Paciente v;
    if (!primero)
        return v;
    pnodoLista aux = primero;
    while (aux->siguiente) {
        aux = aux->siguiente;
    }
    return aux->valor;
}

int Lista::getLongitud()
{
    return this->longitud;
}

bool Lista::estaVacia()
{
    return primero == NULL;
}

void Lista::vaciar()
{
    pnodoLista aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    longitud = 0;
}

Lista::~Lista()
{
    vaciar();
}