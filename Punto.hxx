#ifndef PUNTO_HXX
#define PUNTO_HXX

#include "Punto.h"
#include <cmath>

Punto::Punto() : coordenadaX(0.0), coordenadaY(0.0) {}

Punto::Punto(double valorX, double valorY) : coordenadaX(valorX), coordenadaY(valorY) {}

double Punto::obtenerX() const {
    return this->coordenadaX;
}

double Punto::obtenerY() const {
    return this->coordenadaY;
}

void Punto::fijarX(double nuevaCoordenadaX) {
    this->coordenadaX = nuevaCoordenadaX;
}

void Punto::fijarY(double nuevaCoordenadaY) {
    this->coordenadaY = nuevaCoordenadaY;
}

// Calcula la distancia euclidiana hasta otro punto.
double Punto::distancia(const Punto& otroPunto) const {
    double diferenciaX = this->coordenadaX - otroPunto.obtenerX();
    double diferenciaY = this->coordenadaY - otroPunto.obtenerY();
    return std::sqrt(diferenciaX * diferenciaX + diferenciaY * diferenciaY);
}

#endif