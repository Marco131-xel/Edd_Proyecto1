#ifndef NODOA_H
#define NODOA_H
#include <iostream>

#include "Activo.h"

using namespace std;

class NodoA {
    public:
        // Punteros para el Arbol
        Activo activo;
        //int dato;
        NodoA *izq;
        NodoA *der;
        //NodoA *branch;
        int altura;

        // Constructor para mi Arbol
        //NodoA(int valor, NodoA *branch);
        NodoA(Activo a);
};
#endif //NODOA_H
