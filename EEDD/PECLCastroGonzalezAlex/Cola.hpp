#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    void insertar(Paciente v);
    Paciente eliminar();
    void mostrar();
    Paciente verPrimero();
    int getLongitud();
    void vaciar();

private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP