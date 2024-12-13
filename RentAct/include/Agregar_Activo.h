#ifndef AGREGAR_ACTIVO_H
#define AGREGAR_ACTIVO_H
#include <iostream>

using namespace std;

class Agregar_Activo {
    public:
    string nombre_activo;
    string descripcion;
    const string id;

    Agregar_Activo();
    void agregar_activo();
    void mostrar_activo();
};

#endif //AGREGAR_ACTIVO_H
