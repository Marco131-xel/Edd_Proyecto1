#ifndef AGREGAR_ACTIVO_H
#define AGREGAR_ACTIVO_H
#include "NodoM.h"
#include "Activo.h"
#include <iostream>

using namespace std;

class Agregar_Activo {
    public:
    string nombre_activo;
    string descripcion;
    int idR;
    string idT;
    string generarIDTRAN();
    int crearID();
    // pasor los datos al arbol
    Activo nuevoActivo;

    Agregar_Activo();
    void agregar_activo(NodoM* usuario);
    void mostrar_activo(NodoM* usuario);
};

#endif //AGREGAR_ACTIVO_H
