#include "../../include/MenuAdmin.h"
#include "../../include/Registrar_Usuario.h"

using namespace std;

Registrar_Usuario registrar_user;
// Constructor vacio
MenuAdmin::MenuAdmin() {

}

// Selecionar de la opciones
void MenuAdmin::display() {
    int opt;
    do {
        cout << "\t :::: Menu de Administrador :::: " << endl;
        cout << "1. Registrar Usuario" << endl;
        cout << "2. Reporte Matriz Dispersa" << endl;
        cout << "3. Reporte Activos Disponibles de un Departamento" << endl;
        cout << "4. Reporte Activos Disponibles de una Empresa " << endl;
        cout << "5. Reporte Transacciones " << endl;
        cout << "6. Reporte Activos de un Usuario" << endl;
        cout << "7. Activos rentados por un Usuaio" << endl;
        cout << "8. Ordenar Transacciones" << endl;
        cout << "9. Cerrar Sesion \n" << endl;

        cout << "Seleccione una Opcion: ";
        cin >> opt;
        cout << endl;

        switch (opt) {
            case 1:
                cout << " :::: Registrar Usuario ::::" << endl;
                registrar_user.registrar();
            break;
            case 2:
                cout << " :::: Reporte Matriz Dispersa ::::" << endl;
                registrar_user.mostrar();
            break;
            case 3:
                cout << " :::: Reporte Activos Disponibles de un Departamento :::: " << endl;
            break;
            case 4:
                cout << " :::: Reporte Activos Disponibles de una Empresa ::::" << endl;
            break;
            case 5:
                cout << " :::: Reporte Transacciones :::: " << endl;
            break;
            case 6:
                cout << " :::: Reporte Activos de un Usuario :::: " << endl;
            break;
            case 7:
                cout << " :::: Activos Rentados por un Usuario :::: " << endl;
            break;
            case 8:
                cout << " :::: Ordenar Transacciones :::: " << endl;
            break;
            case 9:
                cout << "\n\tCerrando Sesion ....\n" << endl;
            break;
            default:
                cout << "\n ** Opcion no valida **\n " << endl;
            break;
        }
    } while (opt != 9);
}
