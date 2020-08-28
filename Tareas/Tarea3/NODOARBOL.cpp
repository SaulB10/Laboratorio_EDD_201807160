#include "NODOARBOL.h"

NODOARBOL::NODOARBOL()
{

}

NODOARBOL::NODOARBOL(int numero )
{
  this->data = numero;
}

NODOARBOL::~NODOARBOL()
{
    //dtor
}

int NODOARBOL::getData()
{
    return data;
}
