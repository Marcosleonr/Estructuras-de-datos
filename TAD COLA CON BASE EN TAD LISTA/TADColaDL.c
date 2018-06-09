/*
AUTOR: MARCOS LEÓN REYES (C) ABRIL 2018
VERSIÓN: 1

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADColaDin.c
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>
#include "TADColaDL.h"
/*
void InitializeC(cola *c);
Descripción: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void InitializeC(cola * c)
{
	Initialize(&(c->l));
}

/*
void QueueC(cola * c, elemento e);
Descripción: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void QueueC(cola * c, elemento e)
{
	posicion p1;
	
	p1 =Final(&(c->l));
	
	Insert(&(c->l),p1,e,FALSE);

	return;
}

/*
elemento DequeueC(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al 
frente de esta, quitándolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado una cola y la cola tiene elementos, si no 
se genera un error y se termina el programa.
*/
elemento DequeueC(cola * c)
{
	
	posicion p1;
	elemento e;
	
	p1 = ElementPosition(&(c->l),1); //Aquí se obtiene la posición del elemento

	e = Element(&(c->l),1);//Aquí se obtiene el elemento
	
	Remove(&(c->l),p1);//Aquí se quita el elemento
	
	if(Size(&(c->l))==0){
		Initialize(&(c->l));
	}
	
	return e;	
}


/*
boolean EmptyC(cola * c);
Descripción: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean EmptyC(cola * c)
{
	return Empty(&(c->l));
}

/*
elemento FrontC(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento FrontC(cola * c)
{
	posicion p1;
	elemento e;
	
	p1 = ElementPosition(&(c->l),1); //Aquí se obtiene la posición del elemento

	e = Element(&(c->l),1);//Aquí se obtiene el elemento
	
	return e;	
}

/*
elemento FinalC(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento FinalC(cola * c)
{

	posicion p1;
	elemento e;
	
	p1 = Final(&(c->l));
	
	e = Position (&(c->l),p1);
	
	return e;
}

/*
int SizeC(cola * c);
Descripción: Recibe una cola y devuelve el número de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tamaño de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
*No se modifica el TAD
*/
int SizeC(cola * c)
{
	return Size(&(c->l));
}

/*
void ElementC(cola * c, int i);
Descripción: Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
Devuelve: elemento en la posicion i de la cola
Observaciones: El número i debera estar entre 1 y el tamaño de la cola, si esta es vacia o mas pequeña se provoca un error.
*/
elemento ElementC(cola * c, int i)
{
	elemento e;
	
	e = Element(&(c->l),i);
	
	return e;
}

/*
void DestroyC(cola * c);
Descripción: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void DestroyC(cola * c)
{
	Destroy(&(c->l));
}
