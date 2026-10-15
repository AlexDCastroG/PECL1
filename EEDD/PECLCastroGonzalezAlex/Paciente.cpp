#include "Paciente.hpp"

Paciente::Paciente()
{
    generarDNI();
    apendicitis = rand() % 2; // 1: apendicitis, 0: hernias
    id = 0;
    habitacion = 0;
}

Paciente::~Paciente()
{
}

void Paciente::generarDNI()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int numero = 0;
    for (int i = 0; i < 8; i++) {
        int digito = rand() % 10;
        dni[i] = '0' + digito;
        numero = numero * 10 + digito;
    }
    dni[8] = letras[numero % 23];
    dni[9] = '\0';
}

bool Paciente::tieneApendicitis()
{
    return apendicitis;
}

int Paciente::getId()
{
    return id;
}

int Paciente::getHabitacion()
{
    return habitacion;
}

void Paciente::setId(int nuevoId)
{
    id = nuevoId;
}

void Paciente::setHabitacion(int nuevaHab)
{
    habitacion = nuevaHab;
}

void Paciente::mostrar()
{
    cout << "\tEl paciente cuyo DNI es " << dni << " tiene "
         << (apendicitis ? "apendicitis" : "hernias");

    if (id != 0 && habitacion != 0) {
        cout << ", su ID es: " << id << " y su habitacion asignada es: " << habitacion;
    }
    cout << endl;
}