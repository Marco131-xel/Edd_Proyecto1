#include "../../include/Registrar_Usuario.h"
#include "../../include/MatrizDispersa.h"

MatrizDispersa matriz;
Registrar_Usuario::Registrar_Usuario() {

}

void Registrar_Usuario::registrar() {
    cout << "Ingresar Nombre del Usuario: ";
    cin >> nombre;
    cout << "Ingrese la Contrasenia: ";
    cin >> password;
    cout << "Ingrese su Nombre Completo: ";
    cin >> nombre_completo;
    cout << "Ingrese Departamento: ";
    cin >> departamento;
    cout << "Ingrese Empresa: ";
    cin >> empresa;
    cout << endl;

    matriz.agregarUsuario(departamento, empresa, nombre, password, nombre_completo);
}

void Registrar_Usuario::mostrar() {
    matriz.mostrarUsuario();
}
