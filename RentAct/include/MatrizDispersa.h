#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "Nodo.h"

using namespace std;

class MatrizDispersa {
    private:
        Nodo* cabH;
        Nodo* cabV;

    public:
        MatrizDispersa();
        void agregarUsuario(string departamento, string empresa, string nombreUsuario,
            string contrasenia, string nombreCompĺeto);
        void mostrarUsuario();
        bool buscarUsuario(string nombreUsuario, string contrasenia);
        Nodo* insertarCabeceraH(string departamento);
        Nodo* insertarCabeceraV(string empresa);
        Nodo* cabeceraHorizontal(string departamento);
        Nodo* cabeceraVertical(string empresa);
        Nodo* enCabeceraV(Nodo* nodo);
        // Pruebas
        void mostrarCabeceras();
};

#endif //MATRIZDISPERSA_H
