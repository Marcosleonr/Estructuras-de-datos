/*
LIBRERÍA: Cabecera de el TAD PILA que emplea el TAD LISTA
AUTOR: MARCOS LEÓN REYES (C) Abril 2018
VERSIÓN: 1.0

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementoSs se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. En este caso la memoria 
no queda fija durante la compilación y se logrará este dinamismo 
a travez del modelo "nodoS" el cuál se reservará dinamicamente logrando 
modelar una pila.
*/
#include "TADListaDL.h"

//Definir una pila (Se modela con una estructura que unicamente incluye una lista")
typedef struct pila
{		
	lista l;
}pila;

//DECLARACIÓN DE FUNCIONES
void InitializeS(pila *s);			//Inicializar pila (Iniciar una pila para su uso)
void PushS(pila *s, elemento e);		//Empilar (Introducir un elementoS a la pila)
elemento PopS (pila *s);				//Desempilar (Extraer un elementoS de la pila)
boolean EmptyS(pila *s);				//Vacia (Preguntar si la pila esta vacia)
elemento TopS(pila *s);				//Tope (Obtener el "elementoS" del tope de la pila si extraerlo de la pila)
int SizeS(pila *s);					//Tamaño de la pila (Obtener el número de elementoSs en la pila)
void DestroyS(pila *s);				//Elimina pila (Borra a todos los elementoSs y a la pila de memoria)

//La terminación S significa son funciones propias de la Pila (Stack)