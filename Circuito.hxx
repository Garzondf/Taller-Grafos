#ifndef CIRCUITO_HXX
#define CIRCUITO_HXX

#include "Circuito.h"
#include <stdexcept>

// Crea un circuito vacio
Circuito::Circuito() {}

// Devuelve la cantidad de agujeros del circuito
int Circuito::cantidadAgujeros() const {
    return static_cast<int>(this->agujeros.size());
}

// Devuelve el agujero que ocupa el indice que se busca
Punto Circuito::obtenerAgujero(int indiceAgujero) const {
    if (indiceAgujero < 0 || indiceAgujero >= this->cantidadAgujeros()) {
        throw std::out_of_range("Indice de agujero fuera de rango");
    }
    return this->agujeros[indiceAgujero];
}

// Devuelve una el vector code agujeroso
std::vector<Punto> Circuito::obtenerAgujeros() const {
    return this->agujeros;
}

// Agrega un agujero al final del circuito lo de 00
void Circuito::agregarAgujero(const Punto& nuevoAgujero) {
    this->agujeros.push_back(nuevoAgujero);
}

// Reemplaza los agujeros actuales por una nueva lista
void Circuito::fijarAgujeros(const std::vector<Punto>& nuevosAgujeros) {
    this->agujeros = nuevosAgujeros;
}

#endif