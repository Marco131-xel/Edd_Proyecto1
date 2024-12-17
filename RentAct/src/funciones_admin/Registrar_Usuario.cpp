#include "../../include/Registrar_Usuario.h"
#include "../../include/Global.h"

// Constructor vacio
Registrar_Usuario::Registrar_Usuario() {

}

// Funcion para registrar los Usuarios
void Registrar_Usuario::registrar() {
    cout << "Ingresar Usuario: ";
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

// Esta es de prueba para verificar Usuarios ingresados
void Registrar_Usuario::mostrar() {
    matriz.mostrarUsuario();
    cout << "\n\n" << endl;
    matriz.mostrarCabeceras();
    matriz.generarGraphvizDot();
}

// para imprimir reportes
void Registrar_Usuario::depaActivos() {
    matriz.generarActivosDOT();
}

void Registrar_Usuario::empreActivos() {
    matriz.generarEmpresasDOT();
}


