#ifndef MAQUINA_H
#define MAQUINA_H

#include "Punto.h"
#include "Circuito.h"
#include "Grafo.h"

class Maquina {
private:
    Punto origen;

public:
    Maquina();

    Grafo<Punto, double> construirGrafo(const Circuito& circuito) const;
    Circuito ordenarAgujeros(const Circuito& circuito) const;
    double calcularDistancia(const Circuito& circuito) const;
};

#include "Maquina.hxx"

#endif