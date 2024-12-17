#ifndef RENTAR_ACTIVO_H
#define RENTAR_ACTIVO_H
#include "NodoM.h"
#include <iostream>

using namespace std;

class Rentar_Activo {
    public:
        // opt para eligir si va a rentar o no
        int opt;
        int idR; // id
        int tiempo; // para el tiempo

        Rentar_Activo();

        void rentarActivo(NodoM*);
        void activosRentados(NodoM*);
        void misActivosRentados(NodoM*);

};

#endif //RENTAR_ACTIVO_H
