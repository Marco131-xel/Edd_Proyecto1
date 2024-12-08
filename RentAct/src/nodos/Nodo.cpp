#include "../../include/Nodo.h"

// Constructor para iniciar nodos
Nodo::Nodo(string nombreUsuario, string contrasenia, string nombreCompleto)
    : nombreUsuario(nombreUsuario), contrasenia(contrasenia), nombreCompleto(nombreCompleto),
    next(nullptr),
    prev(nullptr),
    up(nullptr),
    down(nullptr),
    foward(nullptr),
    backward(nullptr){}