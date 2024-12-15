#include "../../include/Activo_User.h"


// Constructor vacio
Activo_User::Activo_User(): nuevoActivo() {
}

// funcion para generar el id de transacciones
string Activo_User::generarIDTRAN() {
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
int Activo_User::crearID() {
    static int contador = 0;
    contador = (contador % 100) + 1;
    return contador;
}


// Funcion para agregar activos
void Activo_User::agregar_activo(NodoM* usuario) {
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
    cout << "\t -- Activo agregado -- \n" << endl;
}

// Funcion para mostrar los activos
void Activo_User::mostrar_activo(NodoM* usuario) {
    cout << "\t %% Activos de: " << usuario->nombreUsuario << " %%" << endl;
    usuario->activos->mostrar();
    cout << "\n" << endl;
}

// funcion para eliminar activos de un usuario
void Activo_User::eliminar_activo(NodoM *usuario) {
    cout << "Ingrese el ID para eliminar activo: ";
    cin >> idR;
    // buscar si el ID existe en el arbol
    if (usuario->activos->buscar(idR)) {
        // buscar los datos del idR
        NodoA *nodo = usuario->activos->buscarNodo(usuario->activos->getRaiz(), idR);
        if (nodo != nullptr) {
            cout << "Datos del activo a eliminar: " << endl;
            cout << "ID: " << nodo->activo.idR << endl;
            cout << "Nombre: " << nodo->activo.nombre << endl;
            cout << "Descripcion: " << nodo->activo.descripcion << endl;
        }
        // eliminar el nodo
        usuario->activos->eliminar(idR);
        cout << "\t --Activo eliminado--\n" << endl;
    } else {
        cout << "\t ** ID no encontrado en los activos **" << endl;
    }
}

// funcion para modificar activos de un usuario
void Activo_User::modificar_activo(NodoM *usuario) {
    cout << "Ingrese el ID para modificar activo: ";
    cin >> idR;
    // buscar si el ID existe en el arbol
    if (usuario->activos->buscar(idR)) {
        // buscar los datos del idR
        NodoA *nodo = usuario->activos->buscarNodo(usuario->activos->getRaiz(), idR);
        if (nodo != nullptr) {
            cout << "Datos del activo" << endl;
            cout << "ID: " << nodo->activo.idR << "; Nombre: " << nodo->activo.nombre <<
                "; Descripcion: " << nodo->activo.descripcion << endl;
        }
        // modificar el nodo
        cout << "Ingresa nueva descripcion: ";
        cin >> descripcion;
        usuario->activos->modificarActivo(idR, descripcion);
        cout << "\t --Activo Modificado --\n" << endl;
    } else {
        cout << "\t ** ID no encontrado en los activos **" << endl;
    }

}


