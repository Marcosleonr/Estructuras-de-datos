/*
AUTORES:
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
16/05/2018
VERSIÓN: 1

DESCRIPCIÓN: Implementación de tabla hash mediante un arreglo de listas.
1.- Diccionario con operaciones básicas

COMPILACIÓN Y EJECUCIÓN:

En Windows
Para compilar el programa: gcc practica3.c Diccionarios.c TADListaDL.c presentacionWin.c -o practica
Para ejecutar el programa: practica

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "presentacion.h"
#include "Diccionario.h"

void Menu(void)
{
	printf("******Diccionario Hash******\n");
	printf("1.- Cargar un archivo de definiciones.\n");
	printf("2.- Agregar una palabra y su definicion.\n");
	printf("3.- Buscar una palabra y ver su definicion.\n");
	printf("4.- Modificiar una definicion.\n");
	printf("5.- Eliminar una palabra.\n");
	printf("6.- Salir.\n");
	
	return;
}

void Estadisticas(lista l[101])
{
	int i,cont=0,contv=0,conts=0, contd=0, ordenm = 0;
	int vec[101];
	
	
	for(i=0;i<101;i++)
	{
		
		conts+=(Size(&l[i]));
		if((Size(&l[i]))>1)
		{
			cont+=(Size(&l[i])-1);
		}
		else if((Size(&l[i]))==0)
		{
			contv++;
		}
	}	
	printf("Numero de colisiones: %d\n",cont);
	printf("Numero de listas vacias: %d\n",contv);
	printf("Tamanio de tabla: %d\n",conts);
	printf("\n");
	return;
}

int OrdenM(lista l[101])
{
	int i =0,ordenm=0;
	for(i=0;i<101;i++)
	{
		if(i==0)
			ordenm=Size(&l[i]);
		else
		{
			if(Size(&l[i])>ordenm)
				ordenm= Size(&l[i]);
		}
	}
	return ordenm;
}

int main(void)
{
	int i = 0, j = 0;
	char c,d;
	char palabra[442];
	char modific[391];
	char pal[51];
	char def[442];
	char nom[51];//Nombre del archivo que se va a leer
	elemento e;
	
	FILE *file;

	lista l[101];
	
	for(j=0;j<101;j++){
		Initialize(&l[j]);
	}
	
	Menu();
	
	while(scanf("%d",&i))
	{
		BorrarPantalla();
		switch(i) {
			
			case 1:
				printf("Ingresa el nombre del archivo:\n");
				c=getchar();
				gets(nom);
				file=fopen(nom,"r");
				
				if(file==NULL)
				{
					printf("Error durante el manejo del archivo\n");
				}else
				{
					while(fgets(def,442,file))
					{
						Agregar(l,def);
					}
					fclose(file);
					printf("Se cargo exitosamente el archivo\n");
				}
				Estadisticas(l);
			break;
			
			case 2:
				
				printf("Ingresa la palabra y su definicion:\n");
				c=getchar();
				gets(palabra);
				Agregar(l,palabra);
				Estadisticas(l);
			break;
			
			case 3:
				printf("Orden maximo de busqueda: %d\n",1+OrdenM(l));
				
				printf("Ingrese la palabra que desea buscar:\n");
				c=getchar();
				gets(pal);
				e=Buscar(l,pal);
				if(strlen(e.d)==0)
				{
					printf("No se encontro la palabra\n");
				}
				else
				{				
					printf("%s\n",e.d);
					printf("Numero de saltos: %d\n",1+BuscarIndice(l,e));
				}
				Estadisticas(l);
				
            break;
			
			case 4:
				printf("Ingresa la palabra que desear modificar:\n");
				c=getchar();
				gets(pal);
				e=Buscar(l,pal);
				if(strlen(e.d)==0){
					printf("No se encontro la palabra\n");
				}else{ 
					printf("Ingresa la nueva definicion:\n");
					//d=getchar();
					gets(modific);
					Modificar(l,e,modific);
					printf("La palabra fue modificada exitosamente\n");
					printf("Numero de saltos: %d\n",2+BuscarIndice(l,e));
				}
				Estadisticas(l);
            break;
			
			case 5:
				printf("Ingrese la palabra que desea eliminar\n");
				c=getchar(); 
				gets(pal);
				e=Buscar(l,pal);
				Eliminar(l,pal,e);
				Estadisticas(l);
			break;
			
			case 6:
				exit(-1);
            break;
			
		default :
        printf("Caso invalido\n" );
		}
		Menu();
	}

	return 0;

}