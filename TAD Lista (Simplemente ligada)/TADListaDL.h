#ifndef __TADLista_H//--------------------------duda
#define __TADLista_H
/*
	IMPLEMENTACIONES DEL TAD LISTA (TADListaDL.h)
	AUTOR: MARCOS LEÓN REYES (C) ABRIL 2018
	VERSIÓN: 1

	EL CODIGO QUE IMPLEMENTA LAS FUNCIONES ES EL ARCHIVO: TADListaDL.c
*/
#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct elemento
{
	/*Aquí se agregan los tipos de datos que
	se desea que almacene el elemento*/
	
	int n;
	
}elemento;

//Estructura de un nodo doblemente ligado
typedef struct nodo
{
	
	elemento e;
	
	//Relación con el nodo anterior
	struct nodo *anterior; //Va a guardar la dirección de memoria de un tipo de dato nodo ej. 61ff04 
	//Relación con el siguiente nodo
	struct nodo *siguiente;	

}nodo;
	
//Se define una posicion como un apuntador a nodo
typedef nodo *posicion; //-------------------------------duda
	
struct lista{
	
	int tamanio;
	posicion frente; 
	posicion final;	
	
}lista;

//DECLARACIÓN DE FUNCIONES

//Efecto: Recibe una lista l y la inicializa para su trabajo normal.
void Initialize (lista *l);

//Efecto: Recibe una lista l y la libera completamente
void Destroy (lista *l);

//Efecto: Recibe una lista l y retorna la posición del elemento al final de esta.
posicion Final (lista *l);

//Efecto: Recibe una lista l y devuelve la posición del elemento al inicio de esta.
posicion First (lista *l);

//Efecto: Recibe una lista l, una posición p y devuelve la posición del elemento siguiente de p.
posicion Following (lista *l,posicion p);

//Efecto: Recibe una lista l, una posición p y devuelve la posición del elemento anterior a p.
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
posicion Previous (lista *l,posicion p);






//Efecto: Recibe una lista l, una posición p y devuelve TRUE si la posición es una posición p valida en la lista l y FALSE en caso contrario.
boolean ValidatePosition (lista *l,posicion p);



#endif    // __TADLista_H