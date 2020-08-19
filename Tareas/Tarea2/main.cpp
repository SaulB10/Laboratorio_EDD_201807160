#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "persona.h"
using namespace std;

int main()
{

    cout << "Hello World!www" << endl;
    Queue<int>*cola=new Queue<int>();
    Queue<string>*cola2=new Queue<string>();
    Queue<persona*>*cola1=new Queue<persona*>();

    cola->enqueue(10);
    cola->enqueue(20);
    cola->enqueue(30);
    cola2->enqueue("hola");
    cola2->enqueue("como");
    persona* a=new persona(20,"saul");
    persona* c=new persona(66,"diego");
    persona* b=new persona(70,"ender");

    cola1->insertar(a);
    cola1->insertar(b);
    cola1->insertar(c);
    persona * aux=cola1->dequeue()->getValue();
    cout<<aux->getNombre()<<endl;
    cout<<"-----------------"<<endl;


    cola->vaciar();
    delete cola;
    return 0;
}

