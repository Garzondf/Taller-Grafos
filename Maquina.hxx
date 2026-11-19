#ifndef MAQUINA_HXX
#define MAQUINA_HXX

#include "Maquina.h"
#include <vector>
#include <limits>

// Ubica la maquina en el origen.
Maquina::Maquina() : origen(0.0, 0.0) {}

// Crea un grafo con el origen y todos los agujeros.
Grafo<Punto, double> Maquina::construirGrafo(const Circuito& circuito) const {
    Grafo<Punto, double> grafo;

    grafo.insertarVertice(this->origen);

    int cantidadAgujeros = circuito.cantidadAgujeros();
    for (int indiceAgujero = 0; indiceAgujero < cantidadAgujeros; ++indiceAgujero) {
        grafo.insertarVertice(circuito.obtenerAgujero(indiceAgujero));
    }

    int cantidadVertices = grafo.cantidadVertices();
    for (int indiceOrigen = 0; indiceOrigen < cantidadVertices; ++indiceOrigen) {
        for (int indiceDestino = indiceOrigen + 1; indiceDestino < cantidadVertices; ++indiceDestino) {
            double distancia = grafo.obtenerVertice(indiceOrigen).distancia(grafo.obtenerVertice(indiceDestino));
            grafo.insertarArista(indiceOrigen, indiceDestino, distancia);
        }
    }

    return grafo;
}

// Agrega al circuito de salida el agujero no visitado mas cercano en cada paso.
Circuito Maquina::ordenarAgujeros(const Circuito& circuito) const {
    Circuito ordenado;
    int cantidadAgujeros = circuito.cantidadAgujeros();
    if (cantidadAgujeros == 0) {
        return ordenado;
    }

    Grafo<Punto, double> grafo = this->construirGrafo(circuito);
    int cantidadVertices = grafo.cantidadVertices();

    std::vector<bool> verticesVisitados(cantidadVertices, false);
    int indiceActual = 0;
    verticesVisitados[0] = true;

    for (int numeroPaso = 0; numeroPaso < cantidadAgujeros; ++numeroPaso) {
        std::list<std::pair<int, double>> vecinosActuales = grafo.obtenerVecinos(indiceActual);
        int indiceMejorVecino = -1;
        double menorCostoEncontrado = std::numeric_limits<double>::max();

        for (std::list<std::pair<int, double>>::const_iterator iteradorVecino =
                 vecinosActuales.begin();
             iteradorVecino != vecinosActuales.end(); ++iteradorVecino) {
            int indiceVecino = iteradorVecino->first;
            double costoArista = iteradorVecino->second;

            if (!verticesVisitados[indiceVecino] && costoArista < menorCostoEncontrado) {
                menorCostoEncontrado = costoArista;
                indiceMejorVecino = indiceVecino;
            }
        }

        if (indiceMejorVecino != -1) {
            verticesVisitados[indiceMejorVecino] = true;
            ordenado.agregarAgujero(grafo.obtenerVertice(indiceMejorVecino));
            indiceActual = indiceMejorVecino;
        }
    }

    return ordenado;
}

// Suma el recorrido desde el origen por los agujeros y de regreso al origen.
double Maquina::calcularDistancia(const Circuito& circuito) const {
    int cantidadAgujeros = circuito.cantidadAgujeros();
    if (cantidadAgujeros == 0) {
        return 0.0;
    }

    double distanciaTotal = 0.0;
    Punto posicionActual = this->origen;

    for (int indiceAgujero = 0; indiceAgujero < cantidadAgujeros; ++indiceAgujero) {
        Punto siguienteAgujero = circuito.obtenerAgujero(indiceAgujero);
        distanciaTotal += posicionActual.distancia(siguienteAgujero);
        posicionActual = siguienteAgujero;
    }

    distanciaTotal += posicionActual.distancia(this->origen);

    return distanciaTotal;
}

#endif