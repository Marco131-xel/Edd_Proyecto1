#ifndef NODOA_H
#define NODOA_H
#include <iostream>

#include "Activo.h"

using namespace std;

class NodoA {
    public:
        // Punteros para el Arbol
        Activo activo;
        NodoA *izq;
        NodoA *der;
        int altura;

        // Constructor para mi Arbol
        NodoA(Activo a);
};
#endif //NODOA_H
