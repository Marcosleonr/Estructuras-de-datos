/*
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
11/04/2018
VERSIÓN: 1

DESCRIPCIÓN: Implementación estática, circular y dinámica de la Cola.
1.- Simulación de la atención de clientes en un supermercado.

COMPILACIÓN Y EJECUCIÓN:

En Linux
Para compilar el programa: gcc simulacion1.c TADCola(Est/Din/EstCirc).c presentacionLin.c -o simulacion1
Para ejecutar el programa: ./simulacion1

*/

#include <stdio.h>
#include <unistd.h> // Para usar la funcion sleep en linux
#include <time.h>
#include <stdlib.h> // Para usar la funcion srand
#include "TADColaEst.h"
//#include "TADColaDin.h"
#include "presentacion.h"

#define TIEMPO_BASE 200

 int main()
 {
 	char nombre[100];
 	int cajeras,i,j;
 	int acajera[10];
 	int tiempo_cliente;
 	int tam_caj=0;
 	int atendidos=0;
 	unsigned int tiempo=0;
 	unsigned int cliente=0;
 	elemento e;
 	int fila;
 	int vac=0;
 	int cont_pan=0;

 	srand(time(NULL));//Iniciar la función

 	printf("Ingrese el nombre del supermercado:\n");
 	scanf("%s", nombre);
 	printf("Ingrese el numero de cajeras:\n");
 	scanf("%d", &cajeras);

 	
	//Cada cajera tiene tiempo diferente
 	for(i=0;i<cajeras;i++)
 	{
 		printf("Ingrese el tiempo de atencion de la cajera %d \n", i+1);
 		scanf("%d", &acajera[i]);
 	}

 	printf("Ingrese cada cuanto tiempo va a llegar un cliente a las cajas \n");
 	scanf("%d", &tiempo_cliente);//Es un único tiempo
 	BorrarPantalla();
 	cola cajera[cajeras];//Se crean n cantidad de colas de acuerdo al #cajeras
 	for(i=0; i<cajeras; i++)
 	{
 		Initialize(&cajera[i]);//Una por una
 	}
 	while(1)
 	{
 		tiempo=tiempo+10;
 		for(i=0;i<cajeras;i++)
 		{
 			if(tiempo%acajera[i]== 0)
 			{
 				if(!Empty(&cajera[i]))
 				{	
 					e= Dequeue(&cajera[i]);
 					printf("Atendi a: %d en caja %d \n",e.n,i+1);
 					atendidos++;//Se cierra cuando se atendierona a mas de 100 y las cjas estan vacias
 				}
 				else
 				{
 					printf("No hay alguien por atender en caja %d \n",i+1 );

 				}
 			}	
 		}
 		
 		if(tiempo%tiempo_cliente==0)
 		{
 			cliente++;
 			e.n=cliente;
 			fila=rand()%cajeras;//Lo forma aleatoriamente
 			Queue(&cajera[fila], e);
 			printf("Llego el cliente %d a la cola de la caja %d \n", e.n,fila+1);//La función rand te da los valores desde el cero

 		}
 		for(i=0;i<cajeras;i++)//Suma todos los tamaños de todas las cajas
 		{
 			vac=vac+Size(&cajera[i]);
 		} 
 		if(atendidos>=100 && vac==0)
 		{
 			break;
 		}
 		else
 		{
 			vac=0;
 		}

		printf("Se han atendido a %d clientes\n", atendidos);//Numero total de atendidos
		for(i=0;i<cajeras;i++)
        {
			MoverCursor(5,3+cont_pan);
			printf("******");
			MoverCursor(5,4+cont_pan);
			printf("**%d**\t",i+1);
			for(j=1;j<=Size(&cajera[i]);j++)
			{
				e=Element(&cajera[i],j);
				printf("%d\t", e.n);
			}
			MoverCursor(5,5+cont_pan);
			printf("******");
			MoverCursor(0,7+cont_pan);
			cont_pan+=10;
        
       } 
      
       cont_pan=0;
       usleep((TIEMPO_BASE)*1000);
       BorrarPantalla();

 		
 	}
 	printf("********El Supermercado %s ah cerrado********\n", nombre);
 	return 0;


 }
