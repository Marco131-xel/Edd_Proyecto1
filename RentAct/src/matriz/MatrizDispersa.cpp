#include "../../include/MatrizDispersa.h"

#include <iostream>

using namespace std;

// Constructor para iniciar la cabeza de la matriz
MatrizDispersa::MatrizDispersa() {
    // head vacia
    head = nullptr;
}

// Agregar un usuario a la matriz
void MatrizDispersa::agregarUsuario(string departamento, string empresa, string nombreUsuario,
    string contrasenia, string nombreCompĺeto) {

    // Crear el nodo de usuario
    Nodo* nuevoUsuario = new Nodo(nombreUsuario, contrasenia, nombreCompĺeto);

    // Si la matriz esta vacia iniciar head
    if (head == nullptr) {
        head = nuevoUsuario;
        return;
    }

    // EMPEZEMOS CON LA PRUEBA SIMPLE PARA AGREGAR USUARIOS
    nuevoUsuario->next = head;
    head = nuevoUsuario; // head ahora es el nuevo nodo
}

// mostrar todos los usuarios en la matriz
void MatrizDispersa::mostrarUsuario() {
    Nodo* actual = head;
    while (actual != nullptr) {
        cout << "Usuario: " << actual->nombreUsuario<< endl;
        cout << "Nombre Completo: " << actual->nombreCompleto << endl;
        cout << "Contrasenia: " << actual->contrasenia << endl;
        actual = actual->next;
    }
}
