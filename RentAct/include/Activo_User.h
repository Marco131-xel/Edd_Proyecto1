#ifndef ACTIVO_USER_H
#define ACTIVO_USER_H
#include "NodoM.h"
#include "Activo.h"
#include <iostream>

using namespace std;

class Activo_User {
    public:
    string nombre_activo;
    string descripcion;
    int idR;
    string idT;
    string generarIDTRAN();
    int crearID();
    // pasor los datos al arbol
    Activo nuevoActivo;

    Activo_User();
    void agregar_activo(NodoM* usuario);
    void mostrar_activo(NodoM* usuario);
    void eliminar_activo(NodoM* usuario);
    void modificar_activo(NodoM* usuario);
};

#endif //ACTIVO_USER_H
