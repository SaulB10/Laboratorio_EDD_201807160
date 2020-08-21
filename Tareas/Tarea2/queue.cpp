//
// Created by saulb on 19/08/2020.
//

#include "queue.h"
#include "persona.h"
template<class T>
Queue<T>::Queue()
{
    this->top=NULL;
    this->bottom=NULL;
}

template<class T>
Queue<T>::~Queue(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp=NULL;
    while(aux!=NULL){
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}


template<class T>
void Queue<T>::enqueue(T valor){
    if(this->top==NULL){
        NodoGenerico<T> *nuevo=new NodoGenerico<T>(valor);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(valor);
        NodoGenerico<T>*aux=this->bottom;
        aux->setSiguiente(nuevo);
        this->bottom=nuevo;
    }
}

template <class T>
NodoGenerico<T>* Queue<T>::dequeue(){
    if(top==NULL){return NULL;}
    NodoGenerico<T>*aux=top;
    top=top->getSiguiente();
    return aux;
}

template<class T>
void Queue<T>::vaciar(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp;
    while(aux!=NULL){
        cout<<aux->getValue()<<"\n";
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}

template<class T>
void Queue<T>::insertar(persona *p) {
    if(this->top==NULL){

        NodoGenerico<T> *nuevo=new NodoGenerico<T>(p);
        nuevo->setValue(p);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(p);
        NodoGenerico<T>*aux=this->bottom;
        //cout<<p->getEdad()<<endl;
        if (p->getEdad() >= 65){
            //cout<<"entre al if"<<endl;
            aux->setSiguiente(bottom);
            this->top=nuevo;
            nuevo->setValue(p);



        }

        aux->setSiguiente(nuevo);
        nuevo->setValue(p);
        this->bottom=nuevo;
    }

}
