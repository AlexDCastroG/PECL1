#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include <ctime>

class Controlador
{
public:
    Controlador();
    ~Controlador();

    int pacientesEnPila();
    int pacientesEnSalaA();
    int pacientesEnSalaB();
    int pacientesEnSalaC();
    int pacientesEnSalaD();
    int pacientesEnListaApendicitis();
    int pacientesEnListaHernias();
    int pacientesEnArbol();

    void genera12Pacientes();
    void muestraPacientes();
    void borraPacientesPila();
    void encolarPacientes();
    void muestraPacientesSalasAyB();
    void muestraPacientesSalasCyD();
    void borraPacientesColas();
    void enlistarPacientes();
    void muestraPacientesApendicitis();
    void muestraPacientesHernias();
    void buscarPacientes();
    void reiniciar();

private:
    Pila pila;
    Cola salaA, salaB, salaC, salaD;
    Lista listaApendicitis, listaHernias;

    int totalGeneradosPila;
    bool idsUsados[100];
    bool habitacionesUsadas[300];

    int generarIdUnico(bool esApendicitis);
    int generarHabitacionUnica(bool esApendicitis);
    void inicializarRegistros();
};

#endif