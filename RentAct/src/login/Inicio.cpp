#include "../../include/Inicio.h"
#include "../../include/Login.h"
using namespace std;

Login logiarse;

// Constructor vacio
Inicio::Inicio() {

}

// Menu de inicio
void Inicio::display() {
    int opt;

    do {
        cout << "\t :::: Renta de Activos :::: " << endl;
        cout << " -- Iniciar Sesion -- " << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Usuario" << endl;
        cout << "3. Salir \n" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opt;
        cout << endl;

        switch (opt) {
            case 1:
                logiarse.login_admin();
            break;
            case 2:
                logiarse.login_user();
            break;
            case 3:
                cout << "\t\n *** Cerrando Programa ***" << endl;
            break;
            default:
                cout << "\n ** Opcion no valida **\n " << endl;
            break;
        }
    }while (opt != 3);
}

