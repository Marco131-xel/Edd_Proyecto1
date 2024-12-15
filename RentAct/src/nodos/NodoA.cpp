#include "../../include/NodoA.h"

// Constructor para iniciar nodos Arbol
NodoA::NodoA(Activo a)
    : activo(a), izq(nullptr), der(nullptr), altura(1){}