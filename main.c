/**************************************************
NOMBRE:Victor Jofre Miranda
ASIGNATURA:Estructura de Datos
PROFESOR:Tomas Lara
*************************************************/
#include <stdio.h>
#include <stdlib.h>

/***Estructura Principal***/
typedef struct Info{
	int valor;
}info;

typedef struct Nodo{
	info *ptrInfo;
	struct Nodo *izq;
	struct Nodo *der;
}nodo;

/***Manejo Nodos***/
info *crearInfo(int num){
	info *newInfo;
	if(newInfo=(info*)malloc(sizeof(info))){
		newInfo->valor=num;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newInfo;
	free(newInfo);
}

nodo *crearNodo(int val){
	nodo *newNodo;
	info *dato=crearInfo(val);
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->ptrInfo=dato;
		newNodo->izq=newNodo->der=NULL;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newNodo;
	free(newNodo);
}

nodo *insertar(nodo *nodoI,int dato){
	if(nodoI==NULL){
		return crearNodo(dato);
	}else if (dato< nodoI->ptrInfo->valor){
		nodoI->izq=insertar(nodoI->izq,dato);
	}else if(dato>nodoI->ptrInfo->valor){
		nodoI->der=insertar(nodoI->der,dato);
		return nodoI;
	}
}

/***Funciones***/
nodo* encuentraMenor(nodo *arbol){
    if(arbol==NULL || arbol->izq==NULL){
		return arbol;
	}else{
		encuentraMenor(arbol->izq);
	}
}

nodo* encuentraMayor(nodo *arbol){
    if(arbol==NULL || arbol->der==NULL){
		return arbol;
	}else{
		encuentraMayor(arbol->der);
	}
}

void InOrden(nodo *ptrIN){
	if(ptrIN!=NULL){
		InOrden(ptrIN->izq);
		printf("\n%d",ptrIN->ptrInfo->valor);
		InOrden(ptrIN->der);
	}
}

int NivelArbol(nodo *arbol){
     int izq=0;
     int der=0;
     if(arbol==NULL){
        return 0;
     }
     if(arbol->izq != NULL){
        izq = NivelArbol(arbol->izq);
     }
     if(arbol->der != NULL){
        der = NivelArbol(arbol->der);
     }
     if(izq>der){
        return izq+1;
     }
     else{
        return der+1;
     }
}

/***Menu***/
void main(){
	nodo *raiz=NULL;
	nodo *aux;

	/***Insertando lista de elementos en el árbol***/
	int datos[]={9,78,6,3,7,5,88,10,0,1,34,22,4,2,8,45,32,65,42};
	int i;
	printf("\nLos numeros colocados en el arbol son:\n");

	/***Imprime cada posicion dentro del arreglo.Luego los inserta en el arbol***/
	for (i=0;i<19;i++){
        printf("\n%d",datos[i]);
		raiz=insertar(raiz,datos[i]);
	}
	printf("\n");

	/***INVOCANDO FUNCIONES***/
	/***Elemento mas pequeño***/
	nodo *numMin=encuentraMenor(raiz);
	printf("\nValor menor dentro del arbol: %d",numMin->ptrInfo->valor);
	printf("\n");

	/***Elemento mas grande***/
    nodo *numMax=encuentraMayor(raiz);
	printf("\nValor mayor dentro del arbol: %d",numMax->ptrInfo->valor);
	printf("\n");

    /***Cantidad de niveles del arbol***/
	int nvl=NivelArbol(raiz);
	printf("\nLa cantidad de niveles del arbol es: %d",nvl);
	printf("\n");

    /***Recorrido InOrden***/
	printf("\nRecorrido In-Orden\n");
	InOrden(raiz);
	printf("\n");
}
