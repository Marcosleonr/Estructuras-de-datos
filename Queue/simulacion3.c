/*
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
11/04/2018
VERSIÓN: 1

DESCRIPCIÓN: Implementación estática, circular y dinámica de la Cola.
1.- Simulación de la atención en un banco con prioridades.

COMPILACIÓN Y EJECUCIÓN:

En Linux
Para compilar el programa: gcc simulacion3.c TADCola(Est/Din/EstCirc).c presentacionLin.c -o simulacion3
Para ejecutar el programa: ./simulacion3

*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "TADColaEst.h"
//#include "TADColaDin.h"
#include "presentacion.h"
#define TIEMPO_BASE 200

int main(void)
{
	int i,disp=0;
	int j,cont_pan=0;
	cola preferente, cliente, usuario;
	elemento e;
	int cajeros;
	int atcajero;
	int t_usuario,t_cliente,t_pref;
	unsigned int tiempo=0;
	int c_usuario=0,c_cliente=0,c_pref=0;
	int atendidos=0,atendidosp=0;

	Initialize(&preferente);
	Initialize(&cliente);
	Initialize(&usuario);


	printf("Ingresa el numero de cajeros disponibles:\n");
	scanf("%d", &cajeros);
	printf("Ingresa el tiempo de atencion de cada caja:\n");
	scanf("%d", &atcajero);
	printf("Ingresa el tiempo de llegada de los usuarios del banco:\n");
	scanf("%d", &t_usuario);
	printf("Ingresa el tiempo de llegada de los clientes del banco:\n");
	scanf("%d", &t_cliente);
	printf("Ingresa el tiempo de llegada de los clientes preferentes:\n");
	scanf("%d", &t_pref);

	BorrarPantalla();


	while(1)
	{
		//usleep((TIEMPO_BASE)*1000);
		tiempo+=10;
		
		if(tiempo%t_usuario==0)
		{
			c_usuario++;
			e.n=c_usuario;
			Queue(&usuario, e);
			printf("LLego el usuario U%d\n", c_usuario);			
		}
		if(tiempo%t_cliente==0)
		{
			c_cliente++;
			e.n=c_cliente;
			Queue(&cliente, e);
			printf("LLego el cliente C%d\n", c_cliente);
		}
		if(tiempo%t_pref==0)
		{
			c_pref++;
			e.n=c_pref;
			Queue(&preferente, e);
			printf("LLego el cliente preferente P%d\n", c_pref);
		}
		printf("\n\n%d clientes en fila de usuarios: [",Size(&usuario));
		for(j=1;j<Size(&usuario);j++)
		{
			e=Element(&usuario,j);
			printf("U%d\t", e.n);

		}
		printf("]");
		printf("\n");
		printf("\n\n%d clientes en fila de clientes: [",Size(&cliente));
		for(j=1;j<Size(&cliente);j++)
		{
			e=Element(&cliente,j);
			printf("C%d\t", e.n);
			
		}
		printf("]");
		printf("\n");
		printf("\n\n%d clientes en fila de clientes preferentes: [",Size(&preferente));
		for(j=1;j<Size(&preferente);j++)
		{
			e=Element(&preferente,j);
			printf("P%d\t", e.n);
			
		}
		printf("]");
		printf("\n");
		if(tiempo%atcajero==0)
		{
			for(i=0;i<cajeros; i++)
			{				
				if(Size(&preferente)>0 && atendidos<5 && atendidosp<2)
				{
					e=Dequeue(&preferente);
					printf("Atendi a: P%d en la caja %d\n", e.n, i+1);
					if(Size(&usuario)>0)
					{
						atendidos++;
					}
					if(Size(&cliente)>0)
					{
						atendidosp++;
					}
					disp=1;
				}
				else if(Size(&cliente)>0 && atendidos<5 && disp==0)
				{
					e=Dequeue(&cliente);
					printf("Atendi a: C%d en la caja %d\n", e.n, i+1);
					if(Size(&usuario)>0)
					{
						atendidos++;
					}
					atendidosp=0;
					disp=1;

				}
				else if(Size(&usuario)>0 && disp==0)
				{
					e=Dequeue(&usuario);
					printf("Atendi a: U%d en la caja %d\n", e.n, i+1);
					atendidos=0;
				}
				
				
				else 
 				{
 					printf("No hay alguien por atender en caja %d \n",i+1 );

 				}
 				disp=0;
			} 
      
		}
		for(j=0;j<cajeros;j++)
       {
        MoverCursor(5+cont_pan,3);
        printf("*CAJA*");
        MoverCursor(5+cont_pan,4);
        printf("**%d**",j+1);
        MoverCursor(5+cont_pan,5);
        printf("******");
        MoverCursor(0,7);
        cont_pan+=10;
        
       } 
        cont_pan=0;

		usleep((TIEMPO_BASE)*1000);
		BorrarPantalla();	

	}
	return 0;


}
