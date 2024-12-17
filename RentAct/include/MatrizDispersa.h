#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodoM.h"
#include <fstream>

using namespace std;

class MatrizDispersa {
    private:
        NodoM* cabH;
        NodoM* cabV;

    public:
        MatrizDispersa();
        ~MatrizDispersa(); // destructor
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
        NodoM* usuarioActual;
        // Reportes
        void generarGraphvizDot();
        void generarActivosDOT();
        void generarEmpresasDOT();
        void generarActivosDOT(ofstream &, NodoM*);
        void generarActivosRecDOT(ofstream &, NodoA*, const string &);
};

#endif //MATRIZDISPERSA_H
