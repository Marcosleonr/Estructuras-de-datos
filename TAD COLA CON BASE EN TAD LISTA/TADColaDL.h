/*
AUTOR: MARCOS LEÓN REYES (C) Abril 2018
VERSIÓN: 1.0

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa.  
*/

#include "TADListaDL.h"
//Definir una cola (Se modela con una estructura que incluye una lista como único elemento )

typedef struct cola
{
	lista l;
} cola;

//DECLARACIÓN DE FUNCIONES
void InitializeC(cola * c);			//Inicializar cola (Initialize): Recibe una cola y la inicializa para su trabajo normal.
void QueueC(cola * c, elemento e);	//Encolar (Queue): Recibe una cola y agrega un elemento al final de ella. 
elemento DequeueC(cola * c);			//Desencolar (Dequeue): Recibe una cola y remueve el elemento del frente retornándolo.
boolean EmptyC(cola * c);			//Es vacía (Empty): Recibe la cola y devuelve verdadero si esta esta vacía.
elemento FrontC(cola * c);			//Frente (Front): Recibe una cola y retorna el elemento del frente.	
elemento FinalC(cola * c);			//Final (Final): Recibe una cola y retorna el elemento del final.
elemento ElementC(cola *c, int i); 	// Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
int SizeC(cola *c);					//Tamaño (Size): Retorna el tamaño de la cola 	
void DestroyC(cola * c);				//Eliminar cola (Destroy): Recibe una cola y la libera completamente.
