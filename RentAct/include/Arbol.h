#ifndef ARBOL_H
#define ARBOL_H
#include "NodoA.h"
#include <iostream>

class Arbol {
    private:
        NodoA* raiz;
        // Metodos del auxiliares
        void insertarNodo(NodoA *&, Activo, NodoA*);
        void mostrarArbol(NodoA *, int) const;
        bool buscarArbol(NodoA *, int) const;
        void eliminarNodo(NodoA *&, int);
        void preOrden(NodoA *) const;
        void inOrden(NodoA *) const;
        void postOrden(NodoA *) const;
        int obtenerAltura(NodoA *) const;
        int obtenerFactorBalance(NodoA *) const;
        void actualizarAltura(NodoA *);
        void balancear(NodoA *&, NodoA *);
        void rotacionIzq(NodoA *&);
        void rotacionDer(NodoA *&);

    public:
        Arbol() : raiz(nullptr) {}
        NodoA* obtenerMin(NodoA*);
        NodoA* buscarNodo(NodoA*, int);
        void insertar(Activo);
        void mostrar() const;
        bool buscar(int) const;
        void eliminar(int);
        void modificarActivo(int, string, string);
        void recorrerPreOrden() const;
        void recorrerInOrden() const;
        void recorrerPostOrden() const;
};
#endif //ARBOL_H
