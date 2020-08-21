#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "persona.h"
using namespace std;

int main()
{

    cout << "Hello World!www" << endl;

    Queue<persona*>*cola1=new Queue<persona*>();


    persona* a=new persona(20,"saul");
    persona* c=new persona(66,"diego");
    persona* b=new persona(70,"ender");

    cola1->insertar(a);
    cola1->insertar(b);
    cola1->insertar(c);


    cola1->vaciar();
    delete cola1;
    return 0;
}

