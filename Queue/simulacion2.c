/*
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
11/04/2018
VERSIÓN: 1

DESCRIPCIÓN: Implementación estática, circular y dinámica de la Cola.
1.- Simulación de la ejecución de procesos en el sistema operativo.

COMPILACIÓN Y EJECUCIÓN:

En Windows
Para compilar el programa: gcc simulacion2.c TADCola(Est/Din/EstCirc).c presentacionWin.c -o simulacion2
Para ejecutar el programa: simulacion2

*/

#include<stdio.h>
#include <windows.h>
#include "TADColaEst.h"
//#include "TADColaDin.h"
#include "presentacion.h"


int main(void){

	int num_procesos = 0;
	int i = 0, j = 0 , k = 0, m = 0;
	int n_ejecuciones = 0;
	unsigned int tiempo=0;
	
	cola c_listo;
	cola c_ejecucion;
	cola c_terminado;
	
	elemento e;
	elemento eaux1,eaux2;
	elemento el,ej,et;
	
	Initialize(&c_listo);
	Initialize(&c_ejecucion);
	Initialize(&c_terminado);
	
	printf("Ingresa el numero de procesos a ejecutar:\n");
	scanf("%d",&num_procesos);
	BorrarPantalla();
	/*Se usa para deshacerse del salto de línea que dejó el scanf(),
	la funcion gets() lo toma como una entrada*/
	getchar(); 
	
	for(i=0;i<num_procesos;i++)
	{
		
		printf("Nombre del proceso %d:\n",i+1);
		gets(e.p);	
		printf("Actividad %d:\n",i+1);
		gets(e.a);
		printf("iD %d:\n",i+1);
		gets(e.i);
		printf("Tiempo %d:\n",i+1);
		scanf("%d",&e.t);
		getchar();//Se deshace del salto de linea que deja el scanf()
		
		e.taux=i; //Se inicializa el tiempo que esperara en la cola
		
		
		/*e.t_ult almacena el tiempo de ejecucion del proceso. Durante el programa ira decrementado ese tiempo hasta llegar a 0.
		Este tiempo se emplea para la visualizacion del proceso anterior*/
		e.t_ult=e.t;
		
		/*e.tsig almacena el tiempo de ejecucion. Durante el programa ira decrementado ese tiempo hasta llegar a 0.
		Este tiempo se emplea para la visualizacion del proceso siguiente*/
		e.t_sig=e.t;
		
		Queue(&c_listo,e);	//Encolar al nuevo proceso
		BorrarPantalla();
	}
	
	while(!Empty(&c_listo))
	{
		
		e = Dequeue(&c_listo); //Se desencola el proceso de la cola listo
		
		e.taux++;//Incrementa el tiempo que va a pasar ejecutandose en la cola ejecucion
		
		e.t_ult--;//Decrementa en tiempo que va a pasar en la cola de ejecucion
		
		Queue(&c_ejecucion,e); //Se encola el proceso en la cola ejecucion
		
		printf("PROCESO EN EJECUCION\n");
		printf("NOMBRE: %s \n",e.p);
		printf("ACTIVIDAD: %s \n",e.a);
		printf("iD: %s \n",e.i);
		printf("TIEMPO EJECUTANDOSE: %ds\n",e.taux);
		
		e = Dequeue(&c_ejecucion);//Se saca de la cola ejecucion
		
		e.t--;
		
		if(n_ejecuciones==0)//Es la primera vez que un proceso entra a ejecucion
		{
			MoverCursor(0,7);
			printf("ULTIMO PROCESO EJECUTADO\n");
			printf("No se ha ejecutado ningun proceso anteriormente\n");
			n_ejecuciones++;
		}
		else
		{
			MoverCursor(0,7);
			printf("ULTIMO PROCESO EJECUTADO:\n");
			printf("iD: %s ",eaux1.i);
			printf("NOMBRE: %s ",eaux1.p);
			if(eaux1.t_ult==0){
				printf("TIEMPO RESTANTE DE EJECUCION: PROCESO TERMINADO \n");
			}
			else
			{
				printf("TIEMPO RESTANTE DE EJECUCION: %ds \n",eaux1.t_ult);
			}	
		}

		eaux1=e;//Este elemento almacena el que sera, en la siguiente iteracion, el proceso anterior ejecutado.
		
		e.t_sig--;//Se decrementa el tiempo de ejecucion para el siguiente proceso
		
		//Revisa cuanto tiempo de ejecucion le falta
		if(e.t==0)//Si t=0, ya termino de ejecutarse
		{	

			if((Empty(&c_listo)))
			{
	
				MoverCursor(0,10);
				printf("SIGUIENTE PROCESO A EJECUTAR\n");
				printf("No hay mas procesos a ser ejecutados\n");
				//printf("\n");
			}
			else
			{
				eaux2=Front(&c_listo);
				MoverCursor(0,10);
				printf("SIGUIENTE PROCESO A EJECUTAR:\n");
				printf("iD: %s ",eaux2.i);
				printf("NOMBRE: %s ",eaux2.p);
				printf("TIEMPO RESTANTE DE EJECUCION: %ds\n",eaux2.t_sig);
				
			}
			
			MoverCursor(0,14);
			printf("************PROCESO FINALIZADO******************\n");
			printf("iD: %s ",e.i);	
			printf("NOMBRE: %s ",e.p);
			printf("TIEMPO TOTAL DE EJECUCION: %ds\n",e.taux);
			
			Queue(&c_terminado,e); //Se encola el proceso en la cola de terminados
			printf("\n");
		}
		else //Si no, se vuelve a enconlar en la cola de listo
		{	
			if((Empty(&c_listo)))
			{
				MoverCursor(0,10);
				printf("SIGUIENTE PROCESO A EJECUTAR:\n");
				printf("iD: %s ",e.i);
				printf("NOMBRE: %s ",e.p);
				printf("TIEMPO RESTANTE DE EJECUCION: %ds \n",e.t_sig);
				printf("\n");
			}
			else
			{
				eaux2=Front(&c_listo);
				MoverCursor(0,10);
				printf("SIGUIENTE PROCESO A EJECUTAR:\n");
				printf("iD: %s ",eaux2.i);
				printf("NOMBRE: %s ",eaux2.p);
				printf("TIEMPO RESTANTE DE EJECUCION: %ds\n",eaux2.t_sig);
				printf("\n");
			}
			
			/*Incrementa el tiempo que va a esperar en la cola
			listo para poder volver a pasar a la cola ejecucion*/ 
			e.taux+=Size(&c_listo);
			Queue(&c_listo,e);
		}
		
		Sleep(1000);
		BorrarPantalla();
		
	}
	
	printf("PROCESOS TERMINADOS \n");
	for(j=1;j<=Size(&c_terminado);j++)
	{
		e=Element(&c_terminado,j);
		printf("iD: %s ",e.i);
		printf("NOMBRE: %s ",e.p);
		printf("TIEMPO TOTAL DE EJECUCION: %ds ",e.taux);
		printf("\n");
	}
	
	
return 0;
}