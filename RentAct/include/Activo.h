#ifndef ACTIVO_H
#define ACTIVO_H
#include <iostream>

using namespace std;

class Activo {
    public:
        int idR;
        string nombre;
        string descripcion;
        string idT;
        Activo(int idR, string nombre, string descripcion, string idT);

        Activo();
};

#endif //ACTIVO_H
