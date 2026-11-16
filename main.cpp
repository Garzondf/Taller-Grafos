#include <iostream>
#include <fstream>
#include <iomanip>
#include "Punto.h"
#include "Circuito.h"
#include "Maquina.h"

using namespace std;

// Verifica que se reciban exactamente dos argumentos: archivo de entrada y salida.
int main(int cantidadArgumentos, char* argumentos[]) {
    if (cantidadArgumentos != 3) {
        cout << "Uso: " << argumentos[0] << " archivo_entrada.txt archivo_salida.txt" << endl;
        return 1;
    }

    // Abre el archivo de entrada y termina si no se pudo abrir.
    ifstream entrada(argumentos[1]);
    if (!entrada.is_open()) {
        cout << "Error: No se pudo abrir el archivo de entrada '" << argumentos[1] << "'." << endl;
        return 1;
    }

    // Crea el archivo de salida y termina si no se pudo abrir.
    ofstream salida(argumentos[2]);
    if (!salida.is_open()) {
        cout << "Error: No se pudo crear el archivo de salida '" << argumentos[2] << "'." << endl;
        entrada.close();
        return 1;
    }

    // Lee la cantidad total de circuitos del archivo.
    int cantidadCircuitos = 0;
    if (!(entrada >> cantidadCircuitos)) {
        cout << "Error: Formato invalido al leer la cantidad de circuitos." << endl;
        entrada.close();
        salida.close();
        return 1;
    }

    Maquina maquina;
    salida << cantidadCircuitos << "\n";

    cout << "Cantidad de circuitos: " << cantidadCircuitos << "\n";
    cout << fixed << setprecision(2);

    for (int indiceCircuito = 0; indiceCircuito < cantidadCircuitos; ++indiceCircuito) {
        int cantidadAgujeros = 0;
        entrada >> cantidadAgujeros;

        Circuito circuitoOriginal;
        for (int indiceAgujero = 0; indiceAgujero < cantidadAgujeros; ++indiceAgujero) {
            double coordenadaX = 0.0, coordenadaY = 0.0;
            entrada >> coordenadaX >> coordenadaY;
            circuitoOriginal.agregarAgujero(Punto(coordenadaX, coordenadaY));
        }

        Circuito circuitoOrdenado = maquina.ordenarAgujeros(circuitoOriginal);
        double distanciaTotal = maquina.calcularDistancia(circuitoOrdenado);

        salida << cantidadAgujeros + 1 << "\n";
        for (int indiceAgujero = 0; indiceAgujero < cantidadAgujeros; ++indiceAgujero) {
            Punto agujero = circuitoOrdenado.obtenerAgujero(indiceAgujero);
            salida << agujero.obtenerX() << " " << agujero.obtenerY() << "\n";
        }
        //para hacer que vaya a 00 al final 
        salida << "0 0\n";

        cout << "Circuito " << (indiceCircuito + 1) << ": "
             << cantidadAgujeros << " agujeros, distancia total recorrida = "
             << distanciaTotal << " mm\n";
    }

    entrada.close();
    salida.close();

    return 0;
}