//
// Created by saulb on 19/08/2020.
//

#include "persona.h"
persona::persona(int edad, string nombre) {
    this->edad=edad;
    this->nombre=nombre;
}
void persona::setEdad(int age) {
    this->edad=age;
}
void persona::setNombre(string name)  {
    this->nombre=name;
}

string persona::getNombre() {
    return this->nombre;
}
int persona::getEdad() {
    return this->edad;
}