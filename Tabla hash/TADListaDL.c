/*
	IMPLEMENTACIONES DE LA LIBRERIA DEL TAD LISTA DOBLEMENTE LIGADA (TADListDL.h)
	AUTORES: MARCOS LEÓN REYES
			 PACHECO HERNÁNDEZ ARIEL AARON
	VERSIÓN: 2 (Mayo 2018)
	
	COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc TADListaDL.c -c 

*/

//LIBRERÍAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "TADListaDL.h"

//DEFINICIÓN DE FUNCIONES

/****************Operaciones de construcción****************/

/*
void Initialize(lista *l)
Descripción: Inicializar lista (Iniciar una lista para su uso)
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Nada
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionará un error.
*/

void Initialize(lista *l) 
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
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionará un error.
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
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionará un error.
*/	

posicion Final(lista *l)
{
	return l->final;
}

/*
posicion First(lista *l)
Descripción: Recibe una lista l y regresa la posición del frente (Recibe una 
lista l y retorna la posición del elemento al frente de esta).
Recibe: lista *l (Referencia a la lista "l" a operar)
Devuelve: Posición del nodo que contiene al elemento del frente de la lista
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, 
si esto no ha pasado se ocasionará un error.
*/

posicion First(lista *l)
{
	return l->frente;
}

/*
posicion Following(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve la posición del 
elemento siguiente de p.
Recibe: lista *l y posicion p (Referencia a la lista "l" a operar y posición válida de la lista)
Devuelve: Posición del nodo siguiente a la posicion dada
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, p es una posición válida de la lista, 
si esto no ha pasado se ocasionará un error.
*/
posicion Following (lista *l,posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->siguiente;
	}	
	else
	{
		printf("ERROR: Función Following (p es inválida)");
		exit(1);
	}
}

/*
posicion Previous(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve la posición del 
elemento anterior de P
Recibe: lista *l y posicion p (Referencia a la lista "l" a operar y posición valida de la lista)
Devuelve: Posición del nodo anterior a la posicion dada
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, p es una posicion válida de la lista, si esto no ha pasado se ocasionará un error.
*/
posicion Previous (lista *l,posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->anterior;
	}	
	else
	{
		printf("ERROR: Función Previous (p es inválida)");
		exit(1);
	}
}

/*
posicion Search(lista *l, elemento e)
Descripción: Recibe una lista l y un elemento e, regresa la posición que coincida exactamente con el elemento e.
Recibe: lista *l y un elemento e (Referencia a la lista "l" a operar y elemento a buscar en la lista)
Devuelve: Posición del elemento en caso de ser encontrado, si no se encuentra se devuelve una posicion inválida
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella el elemento a buscar se compara directamente 
a nivel de bytes. 
*/

posicion Search(lista *l,elemento e)
{
	posicion aux=l->frente;
	while(aux!=NULL)
	{
		
		if(memcmp(&aux->e,&e,sizeof(elemento))==0)
		{
			return aux;			
		}
		aux=aux->siguiente;
	}
	return NULL;
}

posicion SearchAlt(lista *l,char p[51])
{
	posicion aux=l->frente;
	while(aux!=NULL)
	{
		if(strcmp(aux->e.p,p)==0)
		{
			return aux;
		}
		aux=aux->siguiente;
		
	}
	return NULL;
}


/**********Operaciones de consulta****************/

/*
elemento Position(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve el elemento en dicha posición. 
Recibe: lista *l y una posicion p(Referencia a la lista "l" a operar posicion valida en la lista)
Devuelve: Elemento en la posicion dada, si la posicion es invalida se genera error.
Observaciones: La lista l es no vacía y la posición p es una posición valida.
*/

elemento Position (lista *l,posicion p)
{
	elemento e;
	if(ValidatePosition(l,p))
		return p->e;
	else
	{
		printf("\nERROR Position(): La posición es inválida");
		exit(1);
	}
}

/*
boolean ValidatePosition(lista *l, posicion p)
Descripción: Recibe una lista l, una posición p y devuelve TRUE si la posición es una posición p válida en la lista l y FALSE en caso contrario.
Recibe: lista *l y una posicion p(Referencia a la lista "l" a operar y una posición)
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

/*
elemento Element(lista *l, int n)
Descripción: Recibe una lista y un índice (entre 1 y el tamaño de la lista) y devuelve el elemento que se encuentra en la lista en ese índice partiendo del frente de este =1 hacia atrás.
Recibe: lista *l y una entero
Devuelve: Elemento 
Observaciones: Si la cola esta vacía o el índice se encuentra fuera del tamaño de la lista se produce error.
*/
elemento Element(lista *l, int n)
{
	elemento r;
	nodo *aux;
	int i;
	//Si el elemento solicitado está entre 1 y el tamaño de la lista
	if (n>0&&n<=Size(l))
	{
		//Obtener el elemento en la posición n
		aux=l->frente;
		for(i=2;i<=n;i++)
			aux=aux->siguiente;
		r=aux->e;
	}
	else
	{
		printf("\nERROR (Element): Se intenta acceder a elemento %d inexistente",n);
		exit(1);		
	}
	return r;	
}

/*
posicion ElementPosition(lista *l, int n)
Descripción: Recibe una lista y un índice (entre 1 y el tamaño de la lista) y devuelve la posicion del elemento que se encuentra en la lista en ese índice partiendo del frente de este =1 hacia atrás.
Recibe: lista *l y una entero
Devuelve: Posicion 
Observaciones: Si la cola esta vacía o el índice se encuentra fuera del tamaño de la lista se produce error.
*/
posicion ElementPosition(lista *l, int n)
{
	posicion aux=NULL;
	int i;
	//Si el elemento solicitado está entre 1 y el tamaño de la lista
	if (n>0&&n<=Size(l))
	{
		//Obtener el elemento en la posición n
		aux=l->frente;
		for(i=2;i<=n;i++)
			aux=aux->siguiente;
		return aux;
	}
	else
	{
		printf("\nERROR (ElementPosition): Se intenta acceder a posición %d inexistente",n);
		exit(1);		
	}
	return aux;			
}

/*
int Size(lista * l);
Descripción: Recibe una lista y devuelve el número de elemento que se encuentran en esta.
Recibe: lista *l (Referencia a la lista "l")
Devuelve: int (Tamaño de la lista)
Observaciones: El usuario ha creado una lista,la lista fue correctamente inicializada.
*/

int Size(lista *l)
{
	return l->tamanio;
}

/*
boolean Empty(lista * l);
Descripción: Recibe una lista l y devuelve TRUE en caso de que la lista este vacía y FALSE en caso contrario.
Recibe: lista *l (Referencia a la lista "l")
Devuelve: boolean (TRUE o FALSE)
Observaciones: El usuario a creado una lista,la lista fue correctamente inicializada.
*/

boolean Empty(lista *l)
{	
	return (l->tamanio==0) ? TRUE:FALSE;	
}

/**********Operaciones de modificación****************/

/*
void Insert (lista * l, posicion p, elemento e, boolean b);
Descripción: Inserta un elemento e en la lista, este deberá agregarse al frente de p si b es verdadero y atrás de p en caso contrario.
Recibe: lista *l (Referencia a la lista "l"), posición p (Posición válida o inválida en la lista), 
elemento e (Elemento a insertar en la lita), boolean b (Indicador de inserción antes de p=TRUE o después de p =FALSE)
Devuelve: Nada
Observaciones: El usuario a creado una lista,la lista fue correctamente inicializada, si P es no válida o NULL, 
se insertará a e al frente de la lista.
*/
void Insert (lista * l, posicion p, elemento e, boolean b)
{
	
	nodo *aux1,*auxc,*aux2,*aux3;
	
	//Crear el nodo	
	aux1=malloc(sizeof(nodo));
	
	//Si no se puede reservar memoria para el nuevo nodo (ERROR de lista) 
	if(aux1==NULL)
	{
		printf("\nERROR (Insert): No se puede crear un nuevo nodo");
		exit(1);
		
	}
	
	//Introducir a e en el nuevo nodo
	aux1->e=e;	
	
	//Se valida la posición dada
	if(!ValidatePosition(l,p))
	{
		//Si es invalida insertar al frente de la lista
		if(l->final!=NULL) //Si la lista no esta vacia
		{
		
			aux1->siguiente=l->frente;//Aquí el nuevo nodo apunta al que ya estaba
		
			l->frente->anterior = aux1;//Aquí se enlaza el nodo que ya estaba con el nuevo nodo.
			
			l->frente=aux1; //Aquí el frente apunta al nuevo nodo
		
		}
		else//Si está vacía
		{
			//Tanto el siguiente nodo como anterior apuntan a nulo
			aux1->siguiente=NULL;
			aux1->anterior=NULL;
			
			//Ambos punteros (frente y final) apuntan al único nodo
			l->frente=aux1;
			l->final=aux1;
			
		}
	}
	else
	{//Si la posición (p) es válida
		//Si p es FALSE deberá agregarse después de la posición p
		if(b==FALSE)
		{
			//Si p no es el elemento final
			if(p!=l->final)
			{
				//Este auxc alamacena el elemento que va después de la posición dada
				auxc = p->siguiente;
			
				//Aquí el nuevo nodo apunta al siguiente que estará después de él
				aux1->siguiente=auxc;
				
				//Aquí el nodo que va a recorrer hacia atrás, apunta al nuevo nodo
				p->siguiente = aux1;
				
				//El nodo que se va a recorrer apunta (en su apuntador anterior) al nuevo nodo
				auxc->anterior = aux1;
				
			
				//Aquí el nodo en su apuntador anterior, apunta al elemento que va a estar detrás de él
				aux1->anterior=p;		
			
			}
			else //Si p es el final
			{	
		
				//El elemento que se va a recorrer apunta al nuevo nodo
				p->siguiente=aux1;
				
				//El nuevo nodo apunta en su parate anterior al elemento  que se recorrió
				aux1->anterior=p;
				
				//El nuevo nodo va a apuntar a null
				
				aux1->siguiente=NULL;
				
				//EL apuntador final apunta al nuevo nodo
				l->final = aux1;
			}
		}
		else
		{//Si p es TRUE deberá agregarse antes de la posición p
		
			aux2=Previous(l,p);
			
			//Si aux2 no existe (p es el frente)
			if(aux2==NULL)
			{
				//El nuevo nodo apunta al elemento que estaba al incio
				aux1->siguiente=p;
				
				//El nodo que estaba hasta en frente, ahora apunta en su parte anterior al nuevo nodo
				p->anterior = aux1;

				//El nuevo anodo apunta en su apuntador anterior a NUll
				aux1->anterior = NULL;
				
				//El frente apunta al nuevo nodo
				l->frente=aux1;
			}
			//Insertar despues de aux2
			else
			{
				//El nuevo nodo apunta en el apuntador siguiente a la posición dada p
				aux1->siguiente=p;
				
				//El nodo que ya estaba apunta en el apuntador siguiente al nuevo nodo
				aux2->siguiente=aux1;
				
				//El nodo en la posición dada apunta en su apuntador anterior al nuevo nodo
				p->anterior=aux1;
				
				//El nuevo nodo apunta en su apuntador anterior al nodo que se recorrió hacia atrás
				aux1->anterior=aux2;
			}
		}
	}
	//Aumentar el tamanio de la lista
	l->tamanio++;
	return;
}

/*
void Add (lista *l,elemento e);
Descripción: Recibe una lista l y un elemento e, se agrega a e al final de la lista l.
Recibe: lista *l (Referencia a la lista "l"), elemento e (Elemento a insertar en la lita)
Devuelve: Nada
Observaciones: El usuario a creado una lista,la lista fue correctamente inicializada.
*/

void Add (lista *l,elemento e)
{
	posicion aux;	
	aux=malloc(sizeof(nodo));
	
	//Si no se puede reservar memoria para el nuevo nodo (ERROR de lista) 
	if(aux==NULL)
	{
		printf("\nERROR (Add): No se puede crear un nuevo nodo");
		exit(1);
	}
	
	/*Las siguientes operaciones funcionan igual que las de insertar, específicamente en el caso
	  en donde se va a insertar un nuevo elemento del lado derechó del último elemento de la lista*/
	
	//Agregar el elemento al nodo
	aux->e=e;
	
	//Si la lista está vacía
	if(l->final==NULL&&l->frente==NULL&&l->tamanio==0)
	{
		aux->siguiente=NULL;
		aux->anterior=NULL;
		l->frente=aux;
		l->final=aux;								
	}
	//Si la lista no está vacia
	else
	{
		aux->anterior=l->final;
		l->final->siguiente=aux;
		aux->siguiente=NULL;
		l->final=aux;
	}
	//Incrementar el tamaniode la lista	
	l->tamanio++;
	return;
}

/*
void Remove (lista *l,posicion p);
Descripción: Recibe una lista l y una posición p, el elemento en la posición p será removido.
Recibe: lista *l (Referencia a la lista "l"), posicion p (posicion a eliminar en la lista)
Devuelve: Nada
Observaciones: El usuario a creado una lista,la lista fue correctamente inicializada, la posicion p es valida.
*/

void Remove (lista *l,posicion p)
{
	posicion aux,auxf,auxp;
	//Si p es valida
	if(ValidatePosition(l,p))
	{
		//Si la p es frente y final (Solo hay uno en la lista)
		if(p==l->final&&p==l->frente)
		{
			free(p);
			Initialize(l);
		}		
		//Si la p es el final
		else if(p==l->final)
		{
			aux=Previous(l,p);
			//El nodo anterior al último apunta en su apuntador siguiente a NULL
			aux->siguiente=NULL;
			//El apuntador final apunta al nodo anterior al últio
			l->final=aux;
			//Se decrementa el tamaño de la lista
			l->tamanio--;
			//Se libera la memoria del nodo eliminado
			free(p);
		}
		//Si la p es el frente
		else if(p==l->frente)
		{
			aux = Following(l,p);
			
			aux->anterior = NULL;
			
			l->frente = aux;
			
			free(p);
			
			l->tamanio--;
		}
		else//Si p esta en medio
		{
			//Se obtienen los valores que se tienen a los costados
			auxp=Previous(l,p);
			auxf=Following(l,p);
			
			auxp->siguiente=auxf;
			auxf->anterior=auxp;
			l->tamanio--;
			free(p);
		}		
	}
	else
	{
		printf("\nERROR: Remove p es invalida");
		exit(1);
	}
	
	return;
}

/*
void Replace (lista *l,posición p, elemento e);
Descripción: Recibe una lista l, una posición p y un elemento e, el elemento en la posición p será sustituido por e
Recibe: lista *l (Referencia a la lista "l"), posición p (posicion a remplazar en la lista), elemento e (elemento que remplazará al existente en p)
Devuelve: Nada
Observaciones: El usuario a creado una lista,la lista fue correctamente inicializada, la posición p es válida.
*/
void Replace (lista *l,posicion p, elemento e)
{
	//Si la posicion p existe
	if(ValidatePosition(l,p))
	{
		p->e=e; //Remplazar a e
	}
	else
	{
		printf("\nERROR: Replace : No se puede remplazar una posicion invalida");
		exit(1);
	}
	return;
}

void VerLigasLista(lista *l)
{
	posicion aux;	
	aux=l->frente;	
	printf("\n*************************************************************");
	while(aux!=NULL)
	{
		printf("\nPosicion=%p\tSiguiente=%p",aux,aux->siguiente);
		aux=aux->siguiente;
	}
	printf("\n*************************************************************");

	return;
}

