#include <stdio.h>
#include <stdlib.h>
#include "presentacion.h"
#define SIZE 10
#define num 0
void Imprimir(int (*matriz)[SIZE],int n);
void ColocarReina(int (*matriz)[SIZE],int c,int f);
void QuitarReina(int (*matriz)[SIZE],int c,int f);
int ValidaAtaque(int (*matriz)[SIZE],int c,int f,int tam);
void Reinas(int (*matriz)[SIZE],int c,int f,int tam);
int size(int (*matriz)[SIZE],int tam);
//Contador para realizar la recursividad
int numerodereinas=num;

//Funcion principal
int main()
{
	int n=0;
	int matriz[SIZE][SIZE];
	int i,j,tam;
	printf("Ingresa el numero de reinas: \n");
	scanf("%d",&n);
	tam=n;
	//Se llena la matriz de ceros
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matriz[i][j]=0;
		}
	}
		
	//Se llama a la recursividad

	Reinas(matriz,0,0,tam);

	
	return 0;
} 
//Se utiliza para saber el numero de reinas que hay en la matriz
int size(int (*matriz)[SIZE],int tam)
{
	int i,j;
	int contador=0;
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			if((matriz[i][j])==1)
			{
				contador++;
			}
		}
	}
	return contador;
}

//Funcion Recursiva que recibe la matriz y la columna donde se va a comenzar
void Reinas(int (*matriz)[SIZE],int c,int f,int tam)
{
	//Se coloca la reina en la posicion dada
	ColocarReina(matriz,c,f);
	numerodereinas=size(matriz,tam);
	//Imprime el tablero
	Imprimir(matriz,tam);
	EsperarMiliSeg(500);
	BorrarPantalla();
	
	printf("\n");
	//Si ya no hay reinas por colocar se finaliza la recursividad
	if(tam==numerodereinas && (ValidaAtaque(matriz,c,f,tam))==0)
	{
		printf("Ponganos 10 plox :V\n");
		Imprimir(matriz,tam);
		
		exit(0);
	}
	//Si es atacada entonces llama a la recursividad del espacio que esta a la derecha
	if((ValidaAtaque(matriz,c,f,tam))==0 && c<=tam-1 && f<=tam-1)
	{
		
		Reinas(matriz,0,f+1,tam);
		
		//Si regresa es por que no pudo colocar todas la reinas entonces se debe de quitar con la que se esta probando
		QuitarReina(matriz,c,f);
		//Despues lo intenta pero cambiando a la siguiente fila
		Reinas(matriz,c+1,f,tam);
	
		return;
	}
	//Si es que esta siendo atacada revisa colocando la reina en otra posicion de la misma columna
	else if((ValidaAtaque(matriz,c,f,tam))==1 && c<tam-1 && f<tam-1)
	{
		QuitarReina(matriz,c,f); 
		//Despues de quitar a la reina llama a la recursividad otra vez.
		Reinas(matriz,c+1,f,tam);
		return;		
	}
	//Si esta en algun borde de la matriz revisa si puede seguir aumentando la fila
	else if(c==tam-1 || f==tam-1)
	{
		if((ValidaAtaque(matriz,c,f,tam))==1)
		{
			QuitarReina(matriz,c,f);
			if((c+1)<=(tam-1))
			{
				Reinas(matriz,c+1,f,tam);
			}
			
			return;
		}
		
	}
	
}
//Funcion que revisa todos los posibles casos en que puede ser atacada una reina por el lado izquierdo
int ValidaAtaque(int (*matriz)[SIZE],int c,int f,int tam)
{
	int i=0,j=0;
	for(i=c-1;i>=0;i--)
	{
		if(matriz[i][f]==1)
			return 1;
 	}
	for(i=f-1;i>=0;i--)
	{
		if(matriz[c][i]==1)
			return 1;
 	}
	i=1;
	while(c-i>=0 && f-i>=0)
	{
		if(matriz[c-i][f-i]==1)
		{
			return 1;
		}
		i++;
	}
	i=1;
	while(c+i<=tam-1 && f-i>=0)
	{
		if(matriz[c+i][f-i]==1)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
//Funcion que coloca una reina en la posicion que recibe
void ColocarReina(int (*matriz)[SIZE],int c, int f)
{
	matriz[c][f]=1;
	return;
}
//Funcion que elimina una reina en la posicion que recibe
void QuitarReina(int (*matriz)[SIZE],int c, int f)
{
	matriz[c][f]=0;
	return;
}

//Funcion que imprime el tablero con las reinas
void Imprimir(int (*matriz)[SIZE],int n)
{

	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",matriz[i][j]);
		}
		printf("\n");
	}
	return;
}
