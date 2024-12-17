#include "../../include/MatrizDispersa.h"

#include <iostream>

using namespace std;

// Constructor para iniciar la cabeza de la matriz
MatrizDispersa::MatrizDispersa() {
    cabH = nullptr;
    cabV = nullptr;
    usuarioActual = nullptr;
}

// Destructor
MatrizDispersa::~MatrizDispersa() {
    NodoM* auxH = cabH;
    while (auxH != nullptr) {
        NodoM* auxUsuario = auxH->down;
        while (auxUsuario != nullptr) {
            NodoM* temp = auxUsuario;
            auxUsuario = auxUsuario->down;
            delete temp;
        }
        NodoM* tempH = auxH;
        auxH = auxH->next;
        delete tempH;
    }

    NodoM* auxV = cabV;
    while (auxV != nullptr) {
        NodoM* tempV = auxV;
        auxV = auxV->down;
        delete tempV;
    }
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
                usuarioActual = actual;
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

void MatrizDispersa::generarGraphvizDot() {
    ofstream archivo("matriz.dot");

    archivo << "digraph G {\n";
    archivo << "  label=\"Matriz dispersa\";\n";
    archivo << "  labelloc=top;\n";
    archivo << "  rankdir=LR;\n";

    archivo << "  subgraph cluster_departamentos {\n";
    archivo << "    label=\"Departamentos\";\n";
    archivo << "    style=dashed;\n";

    NodoM* auxH = cabH;
    while (auxH != nullptr) {
        archivo << "  \"" << auxH->nombreUsuario << "\" [shape=box, style=filled, color=lightblue];\n";
        auxH = auxH->next;
    }
    archivo << "  }\n";

    NodoM* auxV = cabV;
    while (auxV != nullptr) {
        archivo << "  \"" << auxV->nombreUsuario << "\" [shape=ellipse, style=filled, color=lightgreen];\n";
        auxV = auxV->down;
    }

    auxH = cabH;
    while (auxH != nullptr) {
        NodoM* auxUsuario = auxH->down;
        while (auxUsuario != nullptr) {
            archivo << "  \"" << auxH->nombreUsuario << "\" -> \"" << auxUsuario->nombreUsuario << "\";\n";
            archivo << "  \"" << auxUsuario->nombreUsuario << "\" -> \"" << enCabeceraV(auxUsuario)->nombreUsuario << "\";\n";
            auxUsuario = auxUsuario->down;
        }
        auxH = auxH->next;
    }

    archivo << "}\n";
    archivo.close();

    cout << "\t -- El archivo DOT generado 'matriz.dot' -- \n" << endl;
}

void MatrizDispersa::generarActivosDOT() {
    ofstream archivo("Depa_activos.dot");

    archivo << "digraph MatrizDispersa {" << endl;
    archivo << "    rankdir=LR;" << endl;
    archivo << "    node [shape=rectangle];" << endl;

    // Recorrer cabeceras horizontales (departamentos)
    NodoM* auxH = cabH;
    while (auxH != nullptr) {
        archivo << "    \"" << auxH->nombreUsuario << "\" [label=\"Departamento: " << auxH->nombreUsuario << "\"];" << endl;

        // Recorrer usuarios en cada departamento
        NodoM* auxUsuario = auxH->down;
        while (auxUsuario != nullptr) {
            archivo << "    \"" << auxUsuario->nombreUsuario << "\" [label=\"Usuario: " << auxUsuario->nombreCompleto << "\"];" << endl;
            archivo << "    \"" << auxH->nombreUsuario << "\" -> \"" << auxUsuario->nombreUsuario << "\";" << endl;

            // Recorrer activos en el arbol AVL de cada usuario
            if (auxUsuario->activos != nullptr) {
                generarActivosDOT(archivo, auxUsuario);
            }

            auxUsuario = auxUsuario->down;
        }
        auxH = auxH->next;
    }

    archivo << "}" << endl;
    archivo.close();

    cout << "\t -- El archivo DOT generado 'Depa_Activos.dot' --\n" << endl;
}

void MatrizDispersa::generarActivosDOT(ofstream &archivo, NodoM* usuario) {
    generarActivosRecDOT(archivo, usuario->activos->getRaiz(), usuario->nombreUsuario);
}

void MatrizDispersa::generarActivosRecDOT(ofstream &archivo, NodoA* nodo, const string &usuarioNombre) {
    if (nodo == nullptr) return;

    // Crear nodo para el activo
    archivo << "    \"" << nodo->activo.idR << "\" [label=\"ID: " << nodo->activo.idR
            << "\\nNombre: " << nodo->activo.nombre
            << "\\nDescripción: " << nodo->activo.descripcion << "\"];" << endl;

    // Conectar usuario con su activo
    archivo << "    \"" << usuarioNombre << "\" -> \"" << nodo->activo.idR << "\";" << endl;

    // Recorrer hijos izquierdo y derecho
    generarActivosRecDOT(archivo, nodo->izq, usuarioNombre);
    generarActivosRecDOT(archivo, nodo->der, usuarioNombre);
}

void MatrizDispersa::generarEmpresasDOT() {
    ofstream archivo("Empre_Activo.dot");

    archivo << "digraph MatrizEmpresas {" << endl;
    archivo << "    rankdir=TB;" << endl;
    archivo << "    node [shape=rectangle];" << endl;

    // Recorrer cabeceras verticales (empresas)
    NodoM* auxV = cabV;
    while (auxV != nullptr) {
        archivo << "    \"" << auxV->nombreUsuario << "\" [label=\"Empresa: " << auxV->nombreUsuario << "\"];" << endl;

        // Recorrer usuarios en cada empresa
        NodoM* auxUsuario = auxV->next;
        while (auxUsuario != nullptr) {
            archivo << "    \"" << auxUsuario->nombreUsuario << "\" [label=\"Usuario: " << auxUsuario->nombreUsuario << "\"];" << endl;
            archivo << "    \"" << auxV->nombreUsuario << "\" -> \"" << auxUsuario->nombreUsuario << "\";" << endl;

            // Recorrer activos en el arbol AVL de cada usuario
            if (auxUsuario->activos != nullptr) {
                generarActivosDOT(archivo, auxUsuario);
            }

            auxUsuario = auxUsuario->next;
        }
        auxV = auxV->down;
    }

    archivo << "}" << endl;
    archivo.close();

    cout << "\t -- El archivo DOT generado 'Empre_Activo.dot' --\n" << endl;
}