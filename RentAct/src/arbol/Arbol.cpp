#include "../../include/Arbol.h"

// Funcion para insertar nodo en el arbol
void Arbol::insertar(Activo nuevoActivo) {
    insertarNodo(raiz, nuevoActivo, nullptr);
}

void Arbol::insertarNodo(NodoA *&arbol, Activo nuevoActivo, NodoA *branch) {
    if (arbol == nullptr) {
        arbol = new NodoA(nuevoActivo);
    } else {
        if (nuevoActivo.idR < arbol->activo.idR) {
            insertarNodo(arbol->izq, nuevoActivo, arbol);
        } else {
            insertarNodo(arbol->der, nuevoActivo, arbol);
        }
    }
    // actualizar y balancear
    actualizarAltura(arbol);
    balancear(arbol, branch);
}

// Funcion para mostrar el Arbol
void Arbol::mostrar() const {
    mostrarArbol(raiz, 0);
}

void Arbol::mostrarArbol(NodoA *arbol, int cont) const {
    if (arbol == nullptr) {
        return;
    }
    mostrarArbol(arbol->der, cont+1);
    for (int i = 0; i < cont; i++) {
        cout << "   ";
    }
    cout << "ID: " << arbol->activo.idR << " ; "<< "Nombre: "<< arbol->activo.nombre
    << " ; " << "Descripcion: "<< arbol->activo.descripcion << endl;
    mostrarArbol(arbol->izq, cont+1);
}

// Funciona para buscar nodos en el arbol
bool Arbol::buscar(int dato) const {
    return buscarArbol(raiz, dato);
}

bool Arbol::buscarArbol(NodoA *arbol, int n) const {
    if (arbol == nullptr) {
        return false;
    }
    if (arbol->activo.idR == n) {
        return true;
    }
    if (n < arbol->activo.idR) {
        return buscarArbol(arbol->izq, n);
    }
    return buscarArbol(arbol->der, n);
}

// Funcion para ver InOrden
void Arbol::recorrerInOrden() const {
    inOrden(raiz);
    cout << "\n";
}

void Arbol::inOrden(NodoA *arbol) const {
    if (arbol == nullptr) {
        return;
    }
    inOrden(arbol->izq);
    cout << arbol->activo.idR << " - ";
    inOrden(arbol->der);
}

// getter para raiz
NodoA *Arbol::getRaiz() const {
    return raiz;
}

// funcion para obtener altura del arbol
int Arbol::obtenerAltura(NodoA *nodo) const {
    return nodo ? nodo->altura : 0;
}

// Actualizar la altura del arbol
void Arbol::actualizarAltura(NodoA *nodo) {
    if (nodo) {
        int alturaIzq = obtenerAltura(nodo->izq);
        int alturaDer = obtenerAltura(nodo->der);
        nodo->altura = 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
    }
}

// balancear el arbol
int Arbol::obtenerFactorBalance(NodoA *nodo) const {
    return nodo ? obtenerAltura(nodo->izq) - obtenerAltura(nodo->der) : 0;
}

// funcion para balancear
void Arbol::balancear(NodoA *&arbol, NodoA *branch) {
    int fb = obtenerFactorBalance(arbol);
    if (fb > 1) {
        if (obtenerFactorBalance(arbol->izq) < 0) {
            rotacionIzq(arbol->izq);
        }
        rotacionDer(arbol);
    } else if (fb < -1) {
        if (obtenerFactorBalance(arbol->der) > 0) {
            rotacionDer(arbol->der);
        }
        rotacionIzq(arbol);
    }
}

// funcion para rotar hacia la izquierda
void Arbol::rotacionIzq(NodoA *&nodo) {
    NodoA *aux = nodo->der;
    nodo->der = aux->izq;
    aux->izq = nodo;
    nodo = aux;
    actualizarAltura(nodo->izq);
    actualizarAltura(nodo);
}

// funcion para rotar hacia la derecha
void Arbol::rotacionDer(NodoA *&nodo) {
    NodoA *aux = nodo->izq;
    nodo->izq = aux->der;
    aux->der = nodo;
    nodo = aux;
    actualizarAltura(nodo->der);
    actualizarAltura(nodo);
}

// funcion de eliminar nodos en el arbol
void Arbol::eliminar(int n) {
    eliminarNodo(raiz, n);
}

void Arbol::eliminarNodo(NodoA*& arbol, int n) {
    if (arbol == nullptr) {
        return;
    }

    if (n < arbol->activo.idR) {
        eliminarNodo(arbol->izq, n);
    } else if (n > arbol->activo.idR) {
        eliminarNodo(arbol->der, n);
    } else {
        // Nodo encontrado, proceder a eliminar
        if (arbol->izq == nullptr || arbol->der == nullptr) {
            NodoA* temp = arbol;
            arbol = (arbol->izq == nullptr) ? arbol->der : arbol->izq;
            delete temp;
        } else {
            NodoA* temp = obtenerMin(arbol->der);
            arbol->activo.idR = temp->activo.idR;
            eliminarNodo(arbol->der, temp->activo.idR);
        }
    }

    if (arbol == nullptr) return;
    actualizarAltura(arbol);
    balancear(arbol, nullptr);
}

NodoA *Arbol::obtenerMin(NodoA * arbol) {
    while (arbol->izq != nullptr) {
        arbol = arbol->izq;
    }
    return arbol;
}

// funcion para modificar un activo
void Arbol::modificarActivo(int n, string nuevaDescp) {
    NodoA* nodo = buscarNodo(raiz, n);
    if (nodo != nullptr) {
        nodo->activo.descripcion = nuevaDescp;
    }
}

NodoA* Arbol::buscarNodo(NodoA* arbol, int n) {
    if (arbol == nullptr) return nullptr;
    if (arbol->activo.idR== n) return arbol;
    if (n < arbol->activo.idR) return buscarNodo(arbol->izq, n);
    return buscarNodo(arbol->der, n);
}



