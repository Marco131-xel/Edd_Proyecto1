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

        // Punteros para el Arbol
        int dato;
        Nodo *izq;
        Nodo *der;
        Nodo *branch;
        int altura;

        // Constructor para mi Matriz
        Nodo(string nombreUsuario, string contrasenia, string nombreCompleto);
        // Constructor para mi Arbol
        Nodo(int valor, Nodo *branch);
};
#endif //NODO_H
