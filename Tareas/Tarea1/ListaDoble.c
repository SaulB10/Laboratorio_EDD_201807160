#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


//Se realizo un menu de opciones para mayor facilidad al manejar la lista






typedef struct nodo{
    int dato;
    struct nodo* siguiente;
    struct nodo* atras;

}nodo;

nodo* primero=NULL;
nodo* ultimo=NULL;

void insertarNodo();
void buscarNodo();
void eliminarNodo();


int main(){
    int opcionMenu = 0;
	do{
		printf("\n|------------------|");
		printf("\n|    LISTA DOBLE   |");
		printf("\n|------------------|");
		printf("\n| 1. Insertar      |");
		printf("\n| 2. Buscar        |");
		printf("\n| 3. Eliminar      |");
		printf("\n| 7. Salir         |");		
		printf("\n|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA LISTA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodo();
				break;	
			
			case 3:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				eliminarNodo();
				break;
			
			case 7:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 7);
	return 0;
}

void insertarNodo(){
nodo* nuevo= (nodo*)malloc(sizeof(nodo));
printf(" Ingrese el dato que contendra en nuevo Nodo: ");
scanf("%d",&nuevo->dato);

if (primero==NULL){

    primero = nuevo;
    primero->siguiente = NULL;
    primero->atras = NULL;
    ultimo = primero;

}else{

    ultimo->siguiente = nuevo;
    nuevo->siguiente= NULL;
    nuevo->atras= ultimo;
    ultimo= nuevo;

}

printf("\nNodo ingresado con exito!\n\n");

}
void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato \" %d \" Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}
 
