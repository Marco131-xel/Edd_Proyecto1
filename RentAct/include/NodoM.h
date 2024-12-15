#ifndef NODOM_H
#define NODOM_H
#include "Arbol.h"
#include <iostream>

using namespace std;

class NodoM {
public:
    string nombreUsuario;
    string contrasenia;
    string nombreCompleto;

    // Arbol AVL para almacenar los activos del usuario
    Arbol *activos;

    // Puntero para moverme en la matriz
    NodoM *next; // Nodo a la dercha
    NodoM *prev; // Nodo a la izquieda
    NodoM *up; // Nodo arriba
    NodoM *down; // Nodo abajo
    NodoM *foward; // Nodo opcional (atajo)
    NodoM *backward; // Nodo opcional (atajo

    // Constructor para mi Matriz
    NodoM(string nombreUsuario, string contrasenia, string nombreCompleto);
};
#endif //NODOM_H
