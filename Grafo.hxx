#ifndef GRAFO_HXX
#define GRAFO_HXX

#include "Grafo.h"


template <class TipoVertice, class TipoCosto>
Grafo<TipoVertice, TipoCosto>::Grafo() {}

template <class TipoVertice, class TipoCosto>
int Grafo<TipoVertice, TipoCosto>::cantidadVertices() const {
    return static_cast<int>(this->vertices.size());
}

template <class TipoVertice, class TipoCosto>
int Grafo<TipoVertice, TipoCosto>::cantidadAristas() const {
    int totalAristas = 0;
    for (int indiceVertice = 0; indiceVertice < this->cantidadVertices(); ++indiceVertice) {
        totalAristas += static_cast<int>(this->aristas[indiceVertice].size());
    }
    return totalAristas / 2;
}

// Inserta un vertice y devuelve su indice.
template <class TipoVertice, class TipoCosto>
int Grafo<TipoVertice, TipoCosto>::insertarVertice(const TipoVertice& nuevoVertice) {
    this->vertices.push_back(nuevoVertice);
    this->aristas.push_back(std::list<std::pair<int, TipoCosto>>());
    return static_cast<int>(this->vertices.size()) - 1;
}

// Agrega una arista entre dos vertices con el costo indicado.
template <class TipoVertice, class TipoCosto>
bool Grafo<TipoVertice, TipoCosto>::insertarArista(
    int indiceOrigen, int indiceDestino, const TipoCosto& costo) {
    int cantidadVertices = this->cantidadVertices();
    if (indiceOrigen < 0 || indiceOrigen >= cantidadVertices ||
        indiceDestino < 0 || indiceDestino >= cantidadVertices ||
        indiceOrigen == indiceDestino) {
        return false;
    }
    if (this->hayArista(indiceOrigen, indiceDestino)) {
        return false;
    }

    this->aristas[indiceOrigen].push_back(std::make_pair(indiceDestino, costo));
    this->aristas[indiceDestino].push_back(std::make_pair(indiceOrigen, costo));
    return true;
}


template <class TipoVertice, class TipoCosto>
TipoVertice Grafo<TipoVertice, TipoCosto>::obtenerVertice(int indiceVertice) const {
    if (indiceVertice < 0 || indiceVertice >= this->cantidadVertices()) {
        return TipoVertice();
    }
    return this->vertices[indiceVertice];
}

template <class TipoVertice, class TipoCosto>
bool Grafo<TipoVertice, TipoCosto>::hayArista(int indiceOrigen, int indiceDestino) const {
    int cantidadVertices = this->cantidadVertices();
    if (indiceOrigen < 0 || indiceOrigen >= cantidadVertices ||
        indiceDestino < 0 || indiceDestino >= cantidadVertices) {
        return false;
    }
    for (typename std::list<std::pair<int, TipoCosto>>::const_iterator iteradorArista =
             this->aristas[indiceOrigen].begin();
         iteradorArista != this->aristas[indiceOrigen].end(); ++iteradorArista) {
        if (iteradorArista->first == indiceDestino) {
            return true;
        }
    }
    return false;
}

// Devuelve el costo de la arista entre dos vertices.
template <class TipoVertice, class TipoCosto>
TipoCosto Grafo<TipoVertice, TipoCosto>::obtenerCosto(
    int indiceOrigen, int indiceDestino) const {
    if (indiceOrigen >= 0 && indiceOrigen < this->cantidadVertices()) {
        for (typename std::list<std::pair<int, TipoCosto>>::const_iterator iteradorArista =
                 this->aristas[indiceOrigen].begin();
             iteradorArista != this->aristas[indiceOrigen].end(); ++iteradorArista) {
            if (iteradorArista->first == indiceDestino) {
                return iteradorArista->second;
            }
        }
    }
    return TipoCosto();
}

// Devuelve los vecinos del vertice con el costo de cada arista.
template <class TipoVertice, class TipoCosto>
std::list<std::pair<int, TipoCosto>> Grafo<TipoVertice, TipoCosto>::obtenerVecinos(
    int indiceVertice) const {
    if (indiceVertice < 0 || indiceVertice >= this->cantidadVertices()) {
        return std::list<std::pair<int, TipoCosto>>();
    }
    return this->aristas[indiceVertice];
}

#endif