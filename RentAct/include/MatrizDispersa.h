#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "Nodo.h"

using namespace std;

class MatrizDispersa {
    private:
        Nodo* head;
    public:
        MatrizDispersa();
        void agregarUsuario(string departamento, string empresa, string nombreUsuario,
            string contrasenia, string nombreCompĺeto);
        void mostrarUsuario();
};

#endif //MATRIZDISPERSA_H
