#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Paciente
{
public:
    Paciente();
    ~Paciente();

    bool tieneApendicitis();
    int getId();
    int getHabitacion();
    void setId(int nuevoId);
    void setHabitacion(int nuevaHab);
    void mostrar();

private:
    char dni[10];
    int id;
    int habitacion;
    bool apendicitis; // true (1) = apendicitis, false (0) = hernias

    void generarDNI();
};

#endif // PACIENTE_HPP