#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <utility>

template <class TipoVertice, class TipoCosto>
class Grafo {
private:
    std::vector<TipoVertice> vertices;
    std::vector<std::list<std::pair<int, TipoCosto>>> aristas;

public:
    Grafo();

    int cantidadVertices() const;
    int cantidadAristas() const;
    int insertarVertice(const TipoVertice& nuevoVertice);
    bool insertarArista(int indiceOrigen, int indiceDestino, const TipoCosto& costo);
    TipoVertice obtenerVertice(int indiceVertice) const;
    bool hayArista(int indiceOrigen, int indiceDestino) const;
    TipoCosto obtenerCosto(int indiceOrigen, int indiceDestino) const;
    std::list<std::pair<int, TipoCosto>> obtenerVecinos(int indiceVertice) const;
};

#include "Grafo.hxx"

#endif