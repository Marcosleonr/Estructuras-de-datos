/*
	IMPLEMENTACIONES DE LA LIBRERIA DEL TAD LISTA (TADListDL.h)
	AUTOR: MARCOS LEÓN REYES (C) 
	VERSIÓN: 1 (Abril 2018)
	
	COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc TADListaDL.c -c 

*/

//LIBRERÍAS
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#include "TADListaDL.h"

//DEFINICIÓN DE FUNCIONES

/****************Operaciones de construcción****************/

/*
void Initialize(lista *l)
Descripción: Inicializar lista (Iniciar una lista para su uso)
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Nada
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/

void Initialize(lista *l)//Se crea un apuntador de tipo lista, el cual guardará la dirección de memoria de un tipo de dato lista ej. 61ff04 
{
	l->frente = NULL; //(*l).frente = NULL
	l->final = NULL; //(*l).final = NULL
	l->tamanio = 0; //(*l).tamanio = 0
	
	return;
}

/*
void Destroy(lista *l)
Descripción: Destruir una lista (Recibe una lista l y la libera completamente)
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Nada
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/

void Destroy(lista *l){

	//Apuntador auxiliar a nodo
	nodo *aux;
	
	//Mientras el apuntador del frente de la lista no sea "NULL"
	while(l->frente != NULL)
	{
		//Guardar la referencia el frente
		aux = l->frente;
		
		//El nuevo frente es el siguiente
		l->frente = l->frente->siguiente;
		
		//Liberar el antiguo frente de memoria
		free(aux);
	}

	//Inicilizar el frente,final y tamanio
	
	Initialize(l);

	return;
}

/**********Operaciones de posicionamiento y búsqueda****************/

/*
posicion Final(lista *l)
Descripción: Recibe una lista l y regresa la posición del final (Recibe una 
lista l y retorna la posición del elemento al final de esta.)
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Posición del nodo que contiene al elemeto final de la lista
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/	

posicion Final(lista *l)
{
	return l->final;
}

/*
posicion First(lista *l)
Descripción: Recibe una lista l y regresa la posición del frente (Recibe una 
lista l y retorna la posición del elemento al frente de esta.)
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Posición del nodo que contiene al elemento del frente de la lista
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/

posicion First(lista *l)
{
	return l->frente;
}

/*
posicion Following(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve la posición del 
elemento siguiente de p
Recibe: lista *l y posicion p (Referencia a la lista "l" a operar y posición valida de la lista)
Devuelve: Posición del nodo siguiente a la posicion dada
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, p es una posicion valida de la lista, 
si esto no ha pasado se ocasionara un error.
*/
posicion Following (lista *l,posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->siguiente;
	}	
	else
	{
		printf("ERROR: Función Following (p es invalida)");
		exit(1);
	}
}

/*
posicion Previous(lista *l, posicion p)
Descripción: Recibe una lista L, una posición P y devuelve la posición del 
elemento anterior de P
Recibe: lista *l y posicion p (Referencia a la lista "l" a operar y posición valida de la lista)
Devuelve: Posición del nodo anterior a la posicion dada
Observaciones: El usuario a creado una lista y l tiene la referencia a ella, p es una posicion valida de la lista, si esto no ha pasado se ocasionará un error.
*/
posicion Previous (lista *l,posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->anterior;
	}	
	else
	{
		printf("ERROR: Función Previous (p es invalida)");
		exit(1);
	}
}





/**********Operaciones de consulta****************/

/*
boolean ValidatePosition(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve TRUE si la posición es una posición p valida en la lista l y FALSE en caso contrario.
Recibe: lista *l y una posicion p(Referencia a la lista "l" a operar y una posicion)
Devuelve: Booleano 
Observaciones:El usuario a creado una lista y l tiene la referencia a ella, y también ha obtenido una posición
si esto no ha pasado se ocasionara un error.
*/

boolean ValidatePosition(lista *l,posicion p)
{
	posicion aux;
	aux=l->frente;
	while(aux!=NULL)
	{		
		if(aux==p) 
			return TRUE;	
		aux=aux->siguiente;		
	}	
	return FALSE;

}
