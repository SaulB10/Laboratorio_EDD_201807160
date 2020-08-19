//
// Created by saulb on 19/08/2020.
//

#ifndef COLA_PERSONA_H
#define COLA_PERSONA_H
#include "nodogenerico.h"
#include <string>
#include <iostream>
using namespace std;

class persona {
public:
    persona(int edad,string nombre);
    string getNombre();
    int getEdad();
    void setNombre(string name);
    void setEdad(int age);

private:
    string nombre;
    int edad;

};


#endif //COLA_PERSONA_H
