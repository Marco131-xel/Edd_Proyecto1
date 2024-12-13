#include "../../include/Arbol.h"

// Funcion para insertar nodo en el arbol
void Arbol::insertar(int dato) {
    insertarNodo(raiz, dato, nullptr);
}

void Arbol::insertarNodo(NodoA *&arbol, int n, NodoA *branch) {
    if (arbol == nullptr) {
        arbol = new NodoA(n, branch);
    } else {
        if (n < arbol->dato) {
            insertarNodo(arbol->izq, n, arbol);
        } else {
            insertarNodo(arbol->der, n, arbol);
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
    cout << arbol->dato << "\n";
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
    if (arbol->dato == n) {
        return true;
    }
    if (n < arbol->dato) {
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
    cout << arbol->dato << " - ";
    inOrden(arbol->der);
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

