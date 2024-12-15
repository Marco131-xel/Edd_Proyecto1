#include "../../include/Agregar_Activo.h"


// Constructor vacio
Agregar_Activo::Agregar_Activo(): nuevoActivo() {
}

// funcion para generar el id de transacciones
string Agregar_Activo::generarIDTRAN() {
    string id;
    for(int i = 0; i < 15; i++) {
        if (i % 2 == 0) {
            // generar una letra
            char letra = 'a' + rand() % 26;
            id += letra;
        } else {
            // generar un numero
            char numero = '0' + rand() % 10;
            id += numero;
        }
    }
    return id;
}

// funcion para crear id de rentado
int Agregar_Activo::crearID() {
    static int contador = 0;
    contador = (contador % 100) + 1;
    return contador;
}


// Funcion para agregar activos
void Agregar_Activo::agregar_activo(NodoM* usuario) {
    cout << "Ingresar Nombre: ";
    cin >> nombre_activo;
    cout << "Ingresar Descripcion: ";
    cin >> descripcion;
    cout << endl;
    // generar id de transaccion
    idT = generarIDTRAN();
    // generar id de rentado
    idR = crearID();
    cout << "ID generado: " << idR << " Transc: "<< idT<< endl;
    Activo* nuevoActivo = new Activo(idR, nombre_activo, descripcion, idT);
    usuario->activos->insertar(*nuevoActivo);
    cout << "Activo agregado correctamente al arbol AVL" << endl;
}

// Funcion para mostrar los activos
void Agregar_Activo::mostrar_activo(NodoM* usuario) {
    cout << "activos de : " << usuario->nombreUsuario << endl;
    usuario->activos->mostrar();
}

