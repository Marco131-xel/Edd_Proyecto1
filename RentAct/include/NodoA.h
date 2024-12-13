#ifndef NODOA_H
#define NODOA_H
#include <iostream>

using namespace std;

class NodoA {
    public:
        // Punteros para el Arbol
        int dato;
        NodoA *izq;
        NodoA *der;
        NodoA *branch;
        int altura;

        // Constructor para mi Arbol
        NodoA(int valor, NodoA *branch);
};
#endif //NODOA_H
