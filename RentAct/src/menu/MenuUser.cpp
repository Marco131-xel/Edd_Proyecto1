#include "../../include/MenuUser.h"
#include "../../include/Agregar_Activo.h"
using namespace std;

Agregar_Activo agregar;
// Constructor Vacio
MenuUser::MenuUser() {

}

// Seleccionar de las opciones
void MenuUser::display(NodoM* usuario) {
    int opt;

    do {
        cout << "\t :::: Menu de Usuario :::: " << endl;
        cout << "1. Agregar Activo" << endl;
        cout << "2. Eliminar Activo" << endl;
        cout << "3. Modificar Activo" << endl;
        cout << "4. Rentar Activo" << endl;
        cout << "5. Activos Rentados" << endl;
        cout << "6. Mis Activos Rentados" << endl;
        cout << "7. Cerrar Sesion" << endl;
        cout << "\t\t\t\t\t\t\t\tUsuario: " << usuario->nombreUsuario <<endl;
        cout << "Seleccione una Opcion: ";
        cin >> opt;
        cout << endl;

        switch (opt) {
            case 1:
                cout << "\t :::: Agregar Activo :::: " << endl;
                agregar.agregar_activo(usuario);
            break;
            case 2:
                cout << "\t :::: Eliminar Activo :::: " << endl;
            break;
            case 3:
                cout << "\t :::: Modificar Activo :::: " << endl;
            break;
            case 4:
                cout << "\t :::: Rentar Activo :::: " << endl;
            break;
            case 5:
                cout << "\t :::: Activos Rentados :::: " << endl;
            break;
            case 6:
                cout << "\t :::: Mis Activos Rentados :::: " << endl;
            break;
            case 7:
                cout << "\t\n Cerrando Sesion ....\n " << endl;
            break;
            default:
                cout << "\n ** Opcion no valida **\n " << endl;
            break;
        }
    } while (opt != 7);

}