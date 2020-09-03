#include <iostream>
using namespace std;

string Palabras[]={"Hola como estas","Yo bien gracias","ESTE ES UN MENSAJE","Vamos a ganar EDD todos juntos","!!!!Vamos a sacar 100","$$$$$$$$$#$$$$$","Este es el ultimo mensaje del dia de hoy*45"};
int ascii[5];
void ArrayString(string Palabras[],int lenght);

int main()
{
    int lenght=sizeof(Palabras)/sizeof(Palabras[0]);

    ArrayString(Palabras,lenght);
    return 0;
}

void ArrayString(string Palabras[],int lenght ){
    int n;
    string caracter;
    int valor=0;
    int valores[lenght];
    int nuevo[lenght];
    int aux,pos;
    string ordenado[lenght];

    for (int i = 0; i < lenght; ++i) {
        cout<<Palabras[i]<<endl;
        for (int j = 0; j <Palabras[i].length() ; ++j) {

            caracter=Palabras[i];
            //cout<<caracter[j]<<endl;
            cout<<"Valor de "<<caracter[j]<<" es "<<int(caracter[j])<<endl;
            valor+=int(caracter[j]);
        }
        cout<<valor<<endl;
        valores[i]=valor;
        nuevo[i]=valor;
        valor=0;

    }
    cout<<"Array Original: "<<endl;
    for (int i = 0; i <lenght ; ++i) {

        cout<<valores[i]<<endl;

    }
    cout<<"-------------------------------"<<endl;


//metodo de inserción
    for (int i = 0; i <lenght ; ++i) {
        aux=nuevo[i];
        pos=i;
        while ((pos>0) && nuevo[pos-1]>aux){
            nuevo[pos]=nuevo[pos-1];
            pos--;
        }
        nuevo[pos]=aux;
    }
    cout<<"Array ordenado: "<<endl;
    for (int i = 0; i <lenght ; ++i) {

        cout<<nuevo[i]<<endl;

    }
    cout<<"-------------------------------"<<endl;
    //  cambio
    for (int i = 0; i <lenght ; ++i) {
        for (int j = 0; j < lenght; ++j) {
            if(nuevo[i]==valores[j]){
                cout<<"posicion en viejo: "<<j<<endl;
                ordenado[i]=Palabras[j];

            }
        }

    }
    cout<<"Array ordenado de Palabras: "<<endl;
    for (int i = 0; i <lenght ; ++i) {

        cout<<ordenado[i]<<endl;

    }
    cout<<"-------------------------------"<<endl;









}
/*
void insercion(int*a,int lenght){
int aux,pos;
    for (int i = 0; i <lenght ; ++i) {
        aux=a[i];
        pos=i;
        while ((pos>0) && a[pos-1]>aux){
            a[pos]=a[pos-1];
            pos--;
        }
        a[pos]=aux;


    }
}*/
