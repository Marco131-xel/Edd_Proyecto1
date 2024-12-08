#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo {
    public:
        string nombreUsuario;
        string contrasenia;
        string nombreCompleto;

        // Puntero para moverme en la matriz
        Nodo *next; // Nodo a la dercha
        Nodo *prev; // Nodo a la izquieda
        Nodo *up; // Nodo arriba
        Nodo *down; // Nodo abajo
        Nodo *foward; // Nodo opcional (atajo)
        Nodo *backward; // Nodo opcional (atajo

        // Constructor
        Nodo(string nombreUsuario, string contrasenia, string nombreCompleto);
};
#endif //NODO_H
