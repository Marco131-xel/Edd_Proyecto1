#include "../../include/MatrizDispersa.h"

#include <iostream>

using namespace std;

// Constructor para iniciar la cabeza de la matriz
MatrizDispersa::MatrizDispersa() {
    cabH = nullptr;
    cabV = nullptr;
}

void MatrizDispersa::agregarUsuario(string departamento, string empresa, string nombreUsuario,
    string contrasenia, string nombreCompleto) {

    // Crear el nodo del usuario
    NodoM* nuevoUsuario = new NodoM(nombreUsuario, contrasenia, nombreCompleto);

    // Crear cabecera horizontal, departamento
    NodoM* cabH = cabeceraHorizontal(departamento);
    if (cabH == nullptr) {
        cabH = insertarCabeceraH(departamento);
    }

    // Crear la cabecera vertical, empresa
    NodoM* cabV = cabeceraVertical(empresa);
    if (cabV == nullptr) {
        cabV = insertarCabeceraV(empresa);
    }

    // Insertar nodo usuario al final de la cabecera horizontal
    NodoM* auxH = cabH;
    while (auxH->down != nullptr && auxH->down->nombreUsuario < nombreUsuario) {
        auxH = auxH->down; // Encontrar posición ordenada
    }
    // Enlazar el nuevo nodo en la cabecera horizontal
    nuevoUsuario->down = auxH->down;
    if (auxH->down != nullptr) {
        auxH->down->up = nuevoUsuario;
    }
    auxH->down = nuevoUsuario;
    nuevoUsuario->up = auxH;

    // Insertar nodo el usuario en cabecera vertical
    NodoM* auxV = cabV;
    while (auxV->next != nullptr && auxV->next->nombreUsuario < nombreUsuario) {
        auxV = auxV->next;
    }
    // Enlazar el nuevo nodo en la cabecera vertical
    nuevoUsuario->next = auxV->next;
    if (auxV->next != nullptr) {
        auxV->next->prev = nuevoUsuario;
    }
    auxV->next = nuevoUsuario;
    nuevoUsuario->prev = auxV;
}

void MatrizDispersa::mostrarUsuario() {
    NodoM* auxH = cabH;

    while (auxH != nullptr) { // recorre cabecera h depa
        cout << "Departamento: " << auxH->nombreUsuario << endl;

        NodoM* aux = auxH->down; // ver usuarios en la cabe h
        while (aux != nullptr) {
            cout << "  Usuario: " << aux->nombreUsuario
                 << ", Empresa: " << enCabeceraV(aux)->nombreUsuario
                 << ", Nombre Completo: " << aux->nombreCompleto << endl;
            aux = aux->down;
        }

        auxH = auxH->next; // Ir al siguiente depar
    }
}

// Funcion para buscar los Usuarios de la matriz
bool MatrizDispersa::buscarUsuario(string nombreUsuario, string contrasenia) {
    // Iniciar cabeceras horizontales
    NodoM* actualH = cabH; // recorre en los departamentos
    while (actualH != nullptr) {
        // Ir al primer nodo de la cabecera horizontal
        NodoM* actual = actualH->down;
        while (actual != nullptr) {
            if (actual->nombreUsuario == nombreUsuario && actual->contrasenia == contrasenia) {
                return true;
            }
            actual = actual->down; // se mueve en la cabe H
        }
        actualH = actualH->next; // se mueve el siguiente depa
    }
    return false; // Usuario no encontrado
}

// Funcion para el departamento en base del usuario
NodoM* MatrizDispersa::insertarCabeceraH(string departamento) {
    NodoM* nuevaCab = new NodoM(departamento, "", "");

    if (cabH == nullptr) {
        cabH = nuevaCab;
        return nuevaCab;
    }

    NodoM* aux = cabH;
    while (aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = nuevaCab;
    nuevaCab->prev = aux;
    return nuevaCab;
}

// Funcion para la empresa en base del usuario
NodoM* MatrizDispersa::insertarCabeceraV(string empresa) {
    NodoM* nuevaCab = new NodoM(empresa, "", "");

    if (cabV == nullptr) {
        cabV = nuevaCab;
        return nuevaCab;
    }

    NodoM* aux = cabV;
    while (aux->down != nullptr) {
        aux = aux->down;
    }

    aux->down = nuevaCab;
    nuevaCab->up = aux;
    return nuevaCab;
}

NodoM* MatrizDispersa::cabeceraHorizontal(string departamento) {
    NodoM* aux = cabH;
    while (aux != nullptr) {
        if (aux->nombreUsuario == departamento) { // nombreUsuario es el id
            return aux;
        }
        aux = aux->next;
    }
    return nullptr; // No existe la cabecera
}

NodoM* MatrizDispersa::cabeceraVertical(string empresa) {
    NodoM* aux = cabV;
    while (aux != nullptr) {
        if (aux->nombreUsuario == empresa) { // nombreUsuario es sel id
            return aux;
        }
        aux = aux->down;
    }
    return nullptr; // No existe la cabecera
}

NodoM* MatrizDispersa::enCabeceraV(NodoM* nodo) {
    NodoM* aux = nodo;
    while (aux->up != nullptr) {
        aux = aux->up;
    }
    return aux;
}

// FUNCION EXTRA PARA VER CABECERAS
void MatrizDispersa::mostrarCabeceras() {
    cout << "Cabeceras horizontales:" << endl;
    NodoM* auxH = cabH;
    while (auxH != nullptr) {
        cout << auxH->nombreUsuario << " -> ";
        auxH = auxH->next;
    }
    cout << "NULL" << endl;

    cout << "Cabeceras verticales:" << endl;
    NodoM* auxV = cabV;
    while (auxV != nullptr) {
        cout << auxV->nombreUsuario << " -> ";
        auxV = auxV->down;
    }
    cout << "NULL" << endl;
}
