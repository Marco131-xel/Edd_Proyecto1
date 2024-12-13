#include "../../include/NodoA.h"

// Constructor para iniciar nodos Arbol
NodoA::NodoA(int valor, NodoA *branch = nullptr)
    : dato(valor), izq(nullptr), der(nullptr), altura(1){}