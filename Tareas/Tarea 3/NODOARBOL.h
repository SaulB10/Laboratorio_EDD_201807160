#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>
#include <string>

using namespace std;

class NODOARBOL
{
    public:
        NODOARBOL();
        NODOARBOL(int);
        ~NODOARBOL();
        NODOARBOL * izquierda = NULL;
        NODOARBOL * derecha = NULL;
        int getData();

    private:
        int data;
};

#endif // NODOARBOL_H
