#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <vector>
#include "Punto.h"

class Circuito {
private:
    std::vector<Punto> agujeros;

public:
    Circuito();

    int cantidadAgujeros() const;
    Punto obtenerAgujero(int indiceAgujero) const;
    std::vector<Punto> obtenerAgujeros() const;
    void agregarAgujero(const Punto& nuevoAgujero);
    void fijarAgujeros(const std::vector<Punto>& nuevosAgujeros);
};

#include "Circuito.hxx"

#endif