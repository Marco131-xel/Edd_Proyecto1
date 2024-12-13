#include "../../include/Nodo.h"

// Constructor para iniciar nodos Matriz
Nodo::Nodo(string nombreUsuario, string contrasenia, string nombreCompleto)
    : nombreUsuario(nombreUsuario), contrasenia(contrasenia), nombreCompleto(nombreCompleto),
    next(nullptr),
    prev(nullptr),
    up(nullptr),
    down(nullptr),
    foward(nullptr),
    backward(nullptr){}

// Constructor para iniciar nodos Arbol
Nodo::Nodo(int valor, Nodo *branch = nullptr)
    : dato(valor), izq(nullptr), der(nullptr), altura(1){}