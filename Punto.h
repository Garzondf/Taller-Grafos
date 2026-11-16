#ifndef PUNTO_H
#define PUNTO_H

// Representa una coordenada del circuito en el plano cartesiano.
class Punto {
private:
    double coordenadaX;
    double coordenadaY;

public:
    Punto();
    Punto(double valorX, double valorY);

    double obtenerX() const;
    double obtenerY() const;

    void fijarX(double nuevaCoordenadaX);
    void fijarY(double nuevaCoordenadaY);
    
    // Calcula la distancia hasta otro punto.
    double distancia(const Punto& otroPunto) const;
};

#include "Punto.hxx"

#endif