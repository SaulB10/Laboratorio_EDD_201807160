//
// Created by saulb on 19/08/2020.
//

#ifndef COLA_NODOGENERICO_H
#define COLA_NODOGENERICO_H
#include <iostream>
using namespace std;
template<class T>

class NodoGenerico{

public:
    NodoGenerico(T valor);
    void setValue(T valor);
    T getValue();
    void setSiguiente(NodoGenerico* siguiente);
    NodoGenerico* getSiguiente();
private:
    T valor;
    NodoGenerico* siguiente;
};


#endif //COLA_NODOGENERICO_H
