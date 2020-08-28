#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "NODOARBOL.h"
#include <fstream>

using namespace std;

class ARBOL
{
    public:
        ARBOL();
        ~ARBOL();
        NODOARBOL * raiz = NULL;
        void agregar(int );
        int Buscar(int);
        void ver();
        void Preorden();
        void Inorden();
        void Postorden();
        void GraficarArbol();
        void CrearImagenArbol();
        void GraficarPreorden();
        void GraficarInorden();
        void GraficarPostorden();
        void CrearImagenPreorden();
        void CrearImagenInorden();
        void CrearImagenPostorden();

    protected:

    private:
        void asignar(NODOARBOL *, int);
        int Buscar(NODOARBOL *, int);
        void ver(NODOARBOL *);
        void Preorden(NODOARBOL *);
        void Inorden(NODOARBOL *);
        void Postorden(NODOARBOL *);

        string RecorrerPreorden(NODOARBOL *);
        string RecorrerInorden(NODOARBOL *);
        string RecorrerPostorden(NODOARBOL *);

        string ListaPreorden(NODOARBOL *);
        string ListaInorden (NODOARBOL *);
        string ListaInordenA (NODOARBOL *);
        string ListaPostorden (NODOARBOL *);
};

#endif // ARBOL_H
