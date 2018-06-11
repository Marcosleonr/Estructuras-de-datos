/*TAD Arbol binario
ESTRUCTURAS DE DATOS 1CM7
ABRIL 2017
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "TADArbolBin.h"


/*recibe<-árbol(A); 
Initialize (A)
Efecto: Recibe un árbol binario A y lo inicializa para su trabajo normal.
*/
void InitializeA(arbol_bin *A){
	*A = NULL;
	return;
}

/*recibe<-árbol(A); 
Destroy (A)
Efecto: Recibe un árbol binario A y lo libera completamente.
*/
void DestroyA(arbol_bin *A){
	if(*A == NULL)
		return;
	else
	{
		if((*A)->izq != NULL)
			DestroyA(&((*A)->izq));
		if((*A)->der != NULL)
			DestroyA(&((*A)->der));
		free(*A);
		return;
	}
}

/*recibe<-árbol(A); retorna -> posición
Root (A)
Efecto: Recibe un árbol binario A y retorna la posición de la raíz de A, si el árbol es vacío devuelve una posición nula.
*/
posicionA RootA(arbol_bin *A){
	return *A;
}


/*recibe<-árbol(A), posición(P); retorna -> posición
Parent(A,P)
Efecto: Recibe un árbol binario  A y una posición P, devuelve la posición de padre de p. 
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si P es la raíz se devuelve una posición nula.
*/
posicionA ParentA(arbol_bin *A, posicionA p){
	posicionA r = NULL;
	if(*A == NULL || *A == p)
		return NULL;
	else if ((*A)->izq == p || (*A)->der == p)
		return *A;
	else 
	{
		r = ParentA(&((*A)->izq), p);
		if(r == NULL)
			r = ParentA(&((*A)->der), p);
		return r;
	}
}

/*recibe<-árbol(A), posición(P); retorna -> posición
RightSon(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve la posición del hijo derecho de p. 
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si P no tiene hijo derecho devuelve una posición nula.
*/
posicionA RightSonA(arbol_bin *A, posicionA P)
{
	posicionA r = NULL;
	if(!NullNodeA(A, P))
		r = P -> der;
	
	return r;
}
/*recibe<-árbol(A), posición(P); retorna -> posición
LeftSon(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve la posición del hijo izquierdo de p. 
Requerimientos: El árbol A es no vacío y la posición P es una posición valida. Si P no tiene hijo izquierdo devuelve una posición nula.
*/
posicionA LeftSonA(arbol_bin *A, posicionA P)
{
	posicionA r = NULL;
	if(!NullNodeA(A, P))
		r = P -> izq;
	
	return r;
}


/*recibe<-árbol(A), elemento (E); retorna -> posición
Search(A,E)
Efecto: Recibe un árbol binario A y un elemento E, devuelve la posición del elemento E en el árbol  A.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si E no es encontrado devuelve una posición nula.
*/
posicionA SearchA(arbol_bin *A, elementoA e)
{
	
	posicionA r = NULL;
	if(*A == NULL)
		return NULL;
	else if (memcmp(&((*A)->e),&e,sizeof(elementoA))==0)
		return *A;
	else 
	{
		r = SearchA(&((*A)->izq), e);
		if(r == NULL)
			r = SearchA(&((*A)->der), e);
		return r;
	}

}

/*recibe<-árbol(A); retorna -> booleano
Empty(A)
Efecto: Recibe un árbol binario A y devuelve verdadero en caso de que el árbol A este vacío, devuelve falso en caso contrario.
*/
boolean EmptyA(arbol_bin *A)
{
	boolean r;
	if(*A == NULL)
		r = TRUE;
	else 
		r = FALSE;
	
	return r;
}

/*recibe<-árbol(A), posición (P); retorna -> booleano
NullNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve verdadero si la posición P del árbol A es nula o incorrecta y devuelve falso en caso contrario.
*/
boolean NullNodeA(arbol_bin *A, posicionA p)
{
	boolean r;
	if(*A == NULL)
		return TRUE;
	else if (*A == p)
		return FALSE;	
	
	else 
	{
		r = NullNodeA(&((*A)->izq), p);
		if(r == TRUE)
			r = NullNodeA(&((*A)->der), p);
		return r;
	}
}

/*recibe<-árbol(A), posición (P); retorna -> elemento
ReadNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve el elemento en la posición P del árbol A.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida..
*/
elementoA ReadNodeA(arbol_bin *A, posicionA p)
{
	elementoA r;
	
	if(!NullNodeA(A, p)){
		r = p->e;
	}
	else
	{
		printf("Error: ReadNode");
		exit(1);
	}
	
	return r;
}

/*recibe<-árbol(A), posición (P), elemento E; 
NewRightSon(A,P,E)
Efecto: Recibe un árbol binario A, una posición P y un elemento E, se añade un nodo que contenga E como hijo derecho del nodo con posición P.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si el árbol A es vacío se agrega a un nodo raíz con E. si P ya tiene un hijo derecho, se cancela la operación.
*/
void NewRightSonA(arbol_bin *A, posicionA p, elementoA e)
{
	if(EmptyA(A))
	{
		*A = malloc(sizeof(nodoA));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNodeA(A, p))
	{
		if(p->der != NULL){
			printf("Error: NewRightSon: ya existe");
			exit(1);
		}
		else
		{
			p->der = malloc(sizeof(nodoA));
			p->der->e = e;
			p->der->izq = NULL;
			p->der->der = NULL;
		}
	}else{
		printf("Error: NewRightSon");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P), elemento E; 
NewLeftSon(A,P,E)
Efecto: Recibe un árbol binario A, una posición P y un elemento E, se añade un nodo que contenga E como hijo izquierdo del nodo con posición P.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si el árbol A es vacío se agrega a un nodo raíz con E; si P ya tiene un hijo Izquierdo, se cancela la operación.
*/
void NewLeftSonA(arbol_bin *A, posicionA p, elementoA e)
{
	if(EmptyA(A))
	{
		*A = malloc(sizeof(nodoA));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNodeA(A, p))
	{
		if(p->izq != NULL){
			printf("Error: NewLeftSon: ya existe");
			exit(1);
		}
		else
		{
			p->izq = malloc(sizeof(nodoA));
			p->izq->e = e;
			p->izq->izq = NULL;
			p->izq->der = NULL;
		}
	}else{
		printf("Error: NewLeftSon");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P);
DeleteRightSon(A,P)
Efecto: Recibe un árbol binario A y una posición se elimina al hijo derecho y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida y tiene un hijo derecho.
*/
void DeleteRightSonA(arbol_bin *A, posicionA p)
{
	if(!NullNodeA(A, p))
	{
		DestroyA(&(p->der));
	}
	else
	{
		printf("Error: DeleteRightSon");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P);
DeleteLeftSon(A,P)
Efecto: Recibe un árbol binario A y una posición se elimina al hijo izquierdo y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida y tiene un hijo izquierdo.
*/
void DeleteLeftSonA(arbol_bin *A, posicionA p)
{
	if(!NullNodeA(A, p))
	{
	DestroyA(&(p->izq));
	}
	else
	{
		printf("Error: DeleteLeftSon");
		exit(1);
	}
	return;
}


/*recibe<-árbol(A), posición (P);
DeleteNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, se elimina al nodo con posición  P  y todos sus descendientes.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida. 
*/
void DeleteNodeA(arbol_bin *A, posicionA p)
{
	if(!NullNodeA(A, p))
	{
		DestroyA(&p);
	}
	else
	{
		printf("Error: Delete");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P), elemento (E);
ReplaceNode(A,P)
Efecto: Recibe un árbol binario A, una posición P y un elemento E, se remplaza a E del nodo con posición P en A.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. 
*/
void ReplaceNodeA(arbol_bin *A, posicionA p, elementoA e)
{
	if(!NullNodeA(A, p))
	{
		p->e = e;
	}
	else
	{
		printf("Error: ReplaceNode");
		exit(1);
	}
	return; 
}

