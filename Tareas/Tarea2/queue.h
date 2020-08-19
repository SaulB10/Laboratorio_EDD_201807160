//
// Created by saulb on 19/08/2020.
//

#ifndef COLA_QUEUE_H
#define COLA_QUEUE_H
#include "nodogenerico.h"
#include "nodogenerico.cpp"
#include "persona.h"
#include <iostream>
using namespace std;
template<class T>

class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(T valor);
    void insertar(persona* p);
    NodoGenerico<T>* dequeue();
    void vaciar();
private:
    NodoGenerico<T> *top;
    NodoGenerico<T> *bottom;
};


#endif //COLA_QUEUE_H
