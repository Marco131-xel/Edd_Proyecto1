#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodoM.h"

using namespace std;

class MatrizDispersa {
    private:
        NodoM* cabH;
        NodoM* cabV;

    public:
        MatrizDispersa();
        void agregarUsuario(string departamento, string empresa, string nombreUsuario,
            string contrasenia, string nombreCompĺeto);
        void mostrarUsuario();
        bool buscarUsuario(string nombreUsuario, string contrasenia);
        NodoM* insertarCabeceraH(string departamento);
        NodoM* insertarCabeceraV(string empresa);
        NodoM* cabeceraHorizontal(string departamento);
        NodoM* cabeceraVertical(string empresa);
        NodoM* enCabeceraV(NodoM* nodo);
        // Pruebas
        void mostrarCabeceras();
};

#endif //MATRIZDISPERSA_H
