#include "Controlador.hpp"

Controlador::Controlador()
{
    srand(time(NULL));
    totalGeneradosPila = 0;
    inicializarRegistros();
}

Controlador::~Controlador()
{
}

void Controlador::inicializarRegistros()
{
    for (int i = 0; i < 100; i++)
        idsUsados[i] = false;
    for (int i = 0; i < 300; i++)
        habitacionesUsadas[i] = false;
}

int Controlador::generarIdUnico(bool esApendicitis)
{
    int id;
    do {
        if (esApendicitis)
            id = 1 + rand() % 49;
        else
            id = 51 + rand() % 49;
    } while (idsUsados[id]);

    idsUsados[id] = true;
    return id;
}

int Controlador::generarHabitacionUnica(bool esApendicitis)
{
    int hab;
    do {
        if (esApendicitis)
            hab = 101 + rand() % 99;
        else
            hab = 201 + rand() % 99;
    } while (habitacionesUsadas[hab]);

    habitacionesUsadas[hab] = true;
    return hab;
}

int Controlador::pacientesEnPila()
{
    return pila.getLongitud();
}

int Controlador::pacientesEnSalaA()
{
    return salaA.getLongitud();
}

int Controlador::pacientesEnSalaB()
{
    return salaB.getLongitud();
}

int Controlador::pacientesEnSalaC()
{
    return salaC.getLongitud();
}

int Controlador::pacientesEnSalaD()
{
    return salaD.getLongitud();
}

int Controlador::pacientesEnListaApendicitis()
{
    return listaApendicitis.getLongitud();
}

int Controlador::pacientesEnListaHernias()
{
    return listaHernias.getLongitud();
}

int Controlador::pacientesEnArbol()
{
    return 0;
}

void Controlador::genera12Pacientes()
{
    if (totalGeneradosPila >= 48) {
        cout << "\tSe ha alcanzado el maximo de 48 pacientes generados en la pila.\n";
        return;
    }
    for (int i = 0; i < 12 && totalGeneradosPila < 48; i++) {
        Paciente p;
        pila.insertar(p);
        totalGeneradosPila++;
    }
}

void Controlador::muestraPacientes()
{
    pila.mostrar();
}

void Controlador::borraPacientesPila()
{
    pila.vaciar();
    totalGeneradosPila = 0;
}

void Controlador::encolarPacientes()
{
    while (pila.getLongitud() > 0) {
        Paciente p = pila.extraer();
        bool apendicitis = p.tieneApendicitis();

        p.setId(generarIdUnico(apendicitis));
        p.setHabitacion(generarHabitacionUnica(apendicitis));

        if (apendicitis) {
            if (salaA.getLongitud() <= salaB.getLongitud())
                salaA.insertar(p);
            else
                salaB.insertar(p);
        } else {
            if (salaC.getLongitud() <= salaD.getLongitud())
                salaC.insertar(p);
            else
                salaD.insertar(p);
        }
    }
}

void Controlador::muestraPacientesSalasAyB()
{
    cout << "\tSala A:\n";
    salaA.mostrar();
    cout << "\n\tSala B:\n";
    salaB.mostrar();
}

void Controlador::muestraPacientesSalasCyD()
{
    cout << "\tSala C:\n";
    salaC.mostrar();
    cout << "\n\tSala D:\n";
    salaD.mostrar();
}

void Controlador::borraPacientesColas()
{
    salaA.vaciar();
    salaB.vaciar();
    salaC.vaciar();
    salaD.vaciar();
}

void Controlador::enlistarPacientes()
{
    while (salaA.getLongitud() > 0)
        listaApendicitis.insertarOrden(salaA.eliminar());

    while (salaB.getLongitud() > 0)
        listaApendicitis.insertarOrden(salaB.eliminar());

    while (salaC.getLongitud() > 0)
        listaHernias.insertarOrden(salaC.eliminar());

    while (salaD.getLongitud() > 0)
        listaHernias.insertarOrden(salaD.eliminar());
}

void Controlador::muestraPacientesApendicitis()
{
    listaApendicitis.mostrar();
}

void Controlador::muestraPacientesHernias()
{
    listaHernias.mostrar();
}

void Controlador::buscarPacientes()
{
    cout << "\tApendicitis menor prioridad ->> ";
    if (!listaApendicitis.estaVacia())
        listaApendicitis.getMenorPrioridad().mostrar();
    else
        cout << "No hay pacientes en la lista de apendicitis.\n";

    cout << "\tHernias mayor prioridad ->> ";
    if (!listaHernias.estaVacia())
        listaHernias.getMayorPrioridad().mostrar();
    else
        cout << "No hay pacientes en la lista de hernias.\n";
}

void Controlador::reiniciar()
{
    pila.vaciar();
    borraPacientesColas();
    listaApendicitis.vaciar();
    listaHernias.vaciar();
    totalGeneradosPila = 0;
    inicializarRegistros();
}