#include "ARBOL.h"

ARBOL::ARBOL()
{
}

ARBOL::~ARBOL()
{
    //dtor
}

void ARBOL::agregar(int numero)
{
    try
    {
        if(raiz != NULL)
        {
            asignar(raiz,numero);
        }
        else
        {
            raiz = new NODOARBOL(numero);
        }
    }catch(const char *e)
    {
       std::cout <<e;
    }
}

void ARBOL::asignar(NODOARBOL * puntero, int nuevoelemento)
{
    if(nuevoelemento < puntero->getData())
    {
        if(puntero->izquierda != NULL)
        {
            asignar(puntero->izquierda,nuevoelemento);
        }
        else
        {
            puntero->izquierda = new NODOARBOL(nuevoelemento);
        }
    }
    else if(nuevoelemento > puntero->getData())
    {
        if(puntero->derecha != NULL)
        {
            asignar(puntero->derecha,nuevoelemento);
        }
        else
        {
            puntero->derecha = new NODOARBOL(nuevoelemento);
        }
    }
    else
    {
        // valor repetido.
    }
}

int ARBOL::Buscar(int dato)
{
   return Buscar(raiz,dato);
}

int ARBOL::Buscar(NODOARBOL * puntero, int dato)
{
  string encontro;
  string no="No encontrado";

  if(puntero == NULL)
  {
      cout<<"No encontrado"<<endl;
  }
  else if(dato < puntero->getData())
  {
      encontro = Buscar(puntero->izquierda, dato);
  }
  else if(dato > puntero->getData())
  {
      encontro = Buscar(puntero->derecha, dato);
  }
  else
  {
      encontro = "Encontrado";
  }

  cout<<"Encontrado!"<<endl;
}

void ARBOL::ver()
{
    try
    {
        ver(raiz);
    }
    catch(const char e)
    {
        std::cout << e;
    }
}

void ARBOL::ver(NODOARBOL * nuevo)
{
    if(nuevo != NULL)
    {
        if(nuevo->izquierda != NULL)
        {
            std::cout<<"Usuario: " << nuevo->izquierda->getData() << endl;
            NODOARBOL * aux = nuevo->izquierda;
            ver(nuevo->izquierda);
        }
        if(nuevo->derecha != NULL)
        {
            std::cout<<"Usuario: " << nuevo->derecha->getData() << endl;
            NODOARBOL * aux1 = nuevo->derecha;
            ver(nuevo->derecha);
        }
    }
    else
    {
        std::cout << "No hay usuarios insertados." << endl;
    }
}

void ARBOL::Preorden()
{
    Preorden(raiz);
    std::cout << "\n";
}

void ARBOL::Preorden(NODOARBOL * puntero)
{
    if(puntero != NULL)
    {
       std::cout << puntero->getData() << ",";
       Inorden(puntero->izquierda);
       Inorden(puntero->derecha);
    }
}

void ARBOL::Inorden()
{
    Inorden(raiz);
    std::cout << "\n"<<endl;
}

void ARBOL::Inorden(NODOARBOL * puntero)
{
    if(puntero != NULL)
    {
       Inorden(puntero->izquierda);
       std::cout << puntero->getData() << ",";
       Inorden(puntero->derecha);
    }
}

void ARBOL::Postorden()
{
    Postorden(raiz);
    std::cout << "\n";
}

void ARBOL::Postorden(NODOARBOL * puntero)
{
    if(puntero != NULL)
    {
       Postorden(puntero->izquierda);
       Postorden(puntero->derecha);
       std::cout << puntero->getData() << ",";
    }
}

void ARBOL::GraficarArbol()
{
  NODOARBOL * puntero = raiz;

  ofstream archivo("Arbol\\arbol.dot");
  archivo << "digraph Arbol{";
  archivo << "\nrankdir = TB;\n";
  // --------------------------  --------------------------
  archivo << "label =\"" << "SCABBLE REPORTE ARBOL BINARIO" << "\"";
  archivo << "\n";
  archivo << RecorrerPreorden(raiz);
  archivo << "\n";
  archivo << RecorrerInorden(raiz);
  archivo << "\n";
  // --------------------------  --------------------------
  archivo << "\n}";
  archivo.close();
}
// "[shape = record, label =\"{" << <<"}\", style = filled];";

string ARBOL::RecorrerPreorden(NODOARBOL * puntero)
{
    string instruccion;
    if(puntero != NULL)
    {
        instruccion += puntero->getData() + "[shape = record, label =\"{" + puntero->getData() ;
        instruccion+= "}\", style = filled];";
        instruccion += RecorrerPreorden(puntero->izquierda);
        instruccion += RecorrerPreorden(puntero->derecha);
    }
    return instruccion;
}

string ARBOL::RecorrerInorden(NODOARBOL * puntero)
{
    string instruccion;
    if(puntero != NULL)
    {
        if(puntero->izquierda != NULL)
        {
            instruccion += puntero->getData() + "->" + puntero->izquierda->getData();
            instruccion += ";";
            instruccion += RecorrerInorden(puntero->izquierda);
        }
        if(puntero->derecha != NULL)
        {
            instruccion += puntero->getData() + "->" + puntero->derecha->getData();
            instruccion += ";";
            instruccion += RecorrerInorden(puntero->derecha);
        }
    }
    return instruccion;
}

string ARBOL::RecorrerPostorden(NODOARBOL * puntero)
{
    string instruccion;
    if(puntero != NULL)
    {
        if(puntero->izquierda != NULL)
        {
            instruccion += puntero->getData() + "->" + puntero->izquierda->getData();
            instruccion += ";";
            instruccion += RecorrerPostorden(puntero->izquierda);
        }
        if(puntero->derecha != NULL)
        {
            instruccion += puntero->getData() + "->" + puntero->derecha->getData() ;
            instruccion += ";";
        }
    }
    return instruccion;
}

void ARBOL::CrearImagenArbol()
{
    system("dot.exe -Tpng Arbol\\arbol.dot -o Imagenes\\imagenarbol.png");
}

void ARBOL::GraficarPreorden()
{
    NODOARBOL * auxiliar = raiz;
     ofstream write("Arbol\\arbolpreorden.dot");
     write << "digraph ArbolPreorden{";
     write << "\nrankdir = LR;";
     // --------------------------RECORRER PREORDEN--------------------------
     write << "\n";
     write << ListaPreorden(auxiliar);
     write << "\n";
     write << "label =\"" << "SCABBLE REPORTE ARBOL BINARIO ->PREORDEN" << "\"";
     // --------------------------  --------------------------
     write << "\n}";
     write.close();
}

string ARBOL::ListaPreorden(NODOARBOL * node)
{
    string concatenar;

    if(node != NULL)
    {
        concatenar += node->getData() + "->";
        concatenar += ListaInorden(node->izquierda);
        concatenar += ListaInorden(node->derecha);
    }
    concatenar += "NULL;";

    return concatenar;
}

void ARBOL::GraficarInorden()
{
    NODOARBOL * auxiliar = raiz;
    ofstream write("Arbol\\arbolinorden.dot");
    write << "digraph ArbolInorden{";
    write << "\nrankdir = LR;";
    // --------------------------  --------------------------
    write << "\n";
    write << ListaInordenA(auxiliar);
    write << "\n";
    write << "label =\"" << "SCABBLE REPORTE ARBOL BINARIO -> INORDEN" << "\"";
    // --------------------------  --------------------------
    write << "\n}";
    write.close();
}

string ARBOL::ListaInorden(NODOARBOL * node)
{
    string concatenar;

    if(node != NULL)
    {
        concatenar += ListaInorden(node->izquierda);
        concatenar += node->getData() + "->";
        concatenar += ListaInorden(node->derecha);
    }

    return concatenar;
}

string ARBOL::ListaInordenA(NODOARBOL * node)
{
    string concatenar;

    if(node != NULL)
    {
        concatenar += ListaInorden(node->izquierda);
        concatenar += node->getData() + "->";
        concatenar += ListaInorden(node->derecha);
    }
    concatenar += "NULL;";

    return concatenar;
}

void ARBOL::GraficarPostorden()
{
    NODOARBOL * aux = raiz;

    ofstream escribir("Arbol\\arbolpostorden.dot");
    escribir << "digraph ArbolPorstorden{";
    escribir << "\nrankdir = LR;\n";
    // --------------------------  --------------------------
    escribir << ListaPostorden(aux);
    escribir << "NULL;\n";
    escribir << "label =\"" << "SCABBLE REPORTE ARBOL BINARIO -> POSTORDEN" << "\"";
    // --------------------------  --------------------------
    escribir << "\n}";
    escribir.close();
}

string ARBOL::ListaPostorden(NODOARBOL * aux)
{
    string concatenar;

    if(aux != NULL)
    {
        concatenar += ListaPostorden(aux->izquierda);
        concatenar += ListaPostorden(aux->derecha);
        concatenar += aux->getData() + "->";
    }

    return concatenar;
}

void ARBOL::CrearImagenPreorden()
{
    system("dot.exe -Tpng Arbol\\arbolpreorden.dot -o Imagenes\\imagenarbolpreorden.png");
}

void ARBOL::CrearImagenInorden()
{
    system("dot.exe -Tpng Arbol\\arbolinorden.dot -o Imagenes\\imagenarbolinorden.png");
}

void ARBOL::CrearImagenPostorden()
{
    system("dot.exe -Tpng Arbol\\arbolpostorden.dot -o Imagenes\\imagenarbolpostorden.png");
}
