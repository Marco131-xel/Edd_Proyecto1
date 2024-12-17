#ifndef REGISTRAR_USUARIO_H
#define REGISTRAR_USUARIO_H
#include <iostream>

using namespace std;

class Registrar_Usuario {
    public:
        string nombre;
        string password;
        string departamento;
        string empresa;
        string nombre_completo;

        Registrar_Usuario();
        void registrar();
        void mostrar();
        void depaActivos();
        void empreActivos();
};
#endif //REGISTRAR_USUARIO_H
