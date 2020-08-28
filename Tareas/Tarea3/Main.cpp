#include "ARBOL.h"//
#include "NODOARBOL.h"

// Created by saulb on 27/08/2020.
//
int main(){
    ARBOL* a=new ARBOL();
    	a->agregar(10);
    a->agregar(1);
    a->agregar(20);
    a->agregar(15);
    a->agregar(8);
    a->agregar(96);
    a->agregar(23);
    a->agregar(4);
    a->agregar(7);
    a->agregar(32);
    a->Preorden();
    a->Inorden();
    a->Postorden();
    a->ver();
}

