#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include <iostream>

class Arbol {
    private:
        Nodo* raiz;
        // Metodos del auxiliares
        void insertarNodo(Nodo *&, int, Nodo*);
        void mostrarArbol(Nodo *, int) const;
        bool buscarArbol(Nodo *, int) const;
        void preOrden(Nodo *) const;
        void inOrden(Nodo *) const;
        void postOrden(Nodo *) const;
        int obtenerAltura(Nodo *) const;
        int obtenerFactorBalance(Nodo *) const;
        void actualizarAltura(Nodo *);
        void balancear(Nodo *&, Nodo *);
        void rotacionIzq(Nodo *&);
        void rotacionDer(Nodo *&);

    public:
        Arbol() : raiz(nullptr) {}
        void insertar(int dato);
        void mostrar() const;
        bool buscar(int dato) const;
        void recorrerPreOrden() const;
        void recorrerInOrden() const;
        void recorrerPostOrden() const;
};
#endif //ARBOL_H
