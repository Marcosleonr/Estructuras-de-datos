/*
LIBRERÍA DEL TAD PILA QUE EMPLEA EL TAD LISTA
AUTOR: MARCOS LEÓN REYES (C) ABRIL 2018
VERSIÓN: 1

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. En este caso la memoria 
no queda fija durante la compilación.

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADPilaDL.c
*/

//LIBRERAS
#include<stdlib.h>
#include "TADPilaDL.h"
//DEFINICIÓN DE FUNCIONES

/*
void InitializeS(pila *s);
Descripción: Inicializar pila (Iniciar una pila para su uso)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: Nada
Observaciones: El usuario ha creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void InitializeS(pila *s)
{
	Initialize(&(s->l));//SE inicializa la lista que está contenida dentro de la pila
	return;
}

/*
void PushS(pila *s, elemento e);
Descripción: Empilar (Introducir un elemento a la pila)
Recibe: int *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve: Nada
Observaciones: El usuario ha creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Además no se valida si el malloc() pudo o no apartar memoria, se idealiza que siempre funciona bien 
y no se acaba la memoria
*/
void PushS(pila *s, elemento e)
{
	Insert(&(s->l),NULL,e,TRUE);//Se pone el valor NULL para que inserte al frente
	return;
}

/*
void PopS(pila *s);
Descripción: Desempilar (Extraer un elemento de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: Elemento (Elemento e extraido de la pila)
Observaciones: El usuario ha creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de desempilar (causa error desempilar si esta esta vacía), 
tampoco se valida si free() pudo o no liberar la memoria, se idealiza que siempre funciona bien 
*/
elemento PopS (pila *s)
{
	posicion p1;

	elemento e;
	
	p1 = First(&(s->l));
	
	e = Position(&(s->l),p1);
	
	Remove(&(s->l),p1);
	
	return e;
}


/*boolean EmptyS(pila *s);
Descripción: //Vacia (Preguntar si la pila esta vacia)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE según sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean EmptyS(pila *s)
{
	
	return Empty(&(s->l));	
}
/*
elemento TopS(pila *s);
Descripción: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemnto del tope (causa error si esta esta vacía).
*/
elemento TopS(pila *s)
{
	posicion p1;

	elemento e;
	
	p1 = First(&(s->l));
	
	e = Position(&(s->l),p1);
	
	return e;
}

/*
int SizeS(pila *s);
Descripción: Tamaño de la pila (Obtener el número de elementos en la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: int (Tamaño de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int SizeS(pila *s)
{
	return Size(&(s->l));
}

/*
void DestroyS(pila *s);
Descripción: Elimina pila (Borra a todos los elementos en a la pila de memoria)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
void DestroyS(pila *s)
{
	Destroy(&(s->l));
	return;
}
