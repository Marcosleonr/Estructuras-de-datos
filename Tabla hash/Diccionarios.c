/*
IMPLEMENTACION DE LA LIBRERIA Diccionario.h

AUTORES:
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
16/05/2018
VERSIÓN: 1

DESCRIPCIÓN: Operaciones que permiten interactuar con un diccionario basado en una tabla hash.

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c Diccionarios.c
*/

#include<stdio.h>
#include<string.h>
#include "Diccionario.h"

int hash(char p[51])
{
	int i=0,cont =0;
	
	for(i=0;i<strlen(p);i++)
		cont+=(int)p[i];
	
	return cont%101;
}

/*int hash(char p[51])
{
	int i=0,cont =0;
	
	for(i=0;i<strlen(p);i++)
		cont+=(int)p[i]*i;
	
	
	return cont%101;
}*/

void Agregar(lista l[101],char palabra[442])
{
	int j=0,k=0,m=0,n=0,q=0;
	int cont=0,tamcad=0, contp =0, pal = 0,def = 0;
	int fhash=0;
	char p[51],d[391];
	
	elemento e;
	
	posicion r;
	
	tamcad=strlen(palabra);
	
	for(j=0;j<tamcad;j++)
	{
		if(palabra[j]!=':' && cont==0)
		{
			p[j]=palabra[j];
			pal++;
		
		}
		else if (palabra[j]==':')
		{
			p[j]=':';
			pal++;
			cont++;
		}
		else if(palabra[j]!=':' && cont>0)
		{
			d[contp]=palabra[j];
			contp++;
			def++;
		}
	}
	
	//Elimina el salto de liea que agrega fgets cuando lee un archivo
	if(d[def-1]=='\n')
	{
		d[def-1]='\0';
	}
	
	//Se rellenan los espacios sobrantes del vector con caracteres vacíos para que no se guarde basura
	for(k=pal;k<51;k++)
	{
		p[k]='\0';
	}
	
	for(m=def;m<391;m++)
	{
		d[m]='\0';
	}
	
	//Se obtiene el numero de lista en la que se va a guardar
	fhash=hash(p);
	
	printf("El hasheo de la palabra es: %d\n",fhash);
	
	for(n=0;n<51;n++)
	{
		e.p[n]=p[n];
	}
	
	for(q=0;q<391;q++)
	{
		e.d[q]=d[q+1];
	}
	
	//Devuelve NULL en caso de que no encuentre nada en la lista
	r=Search(&l[hash(p)],e);
	
	if(r==NULL)
	{	printf("Numero de saltos: %d\n",2+Size(&l[hash(p)]));
		Insert(&l[hash(p)],NULL,e, FALSE);
	}
	else
	{
		printf("La palabra ya fue ingresada\n");
		printf("Numero de saltos: %d \n",1+BuscarIndice(l,e));
	}
	
}

elemento Buscar(lista l[101],char p[51])
{
	int tam=0, n=0,k=0,m=0,q=0;
	
	elemento e;
	posicion r;

	tam=strlen(p);
	p[tam]=':';

	
	for(q=tam+1;q<51;q++){
		p[q]='\0';
	}
	
	r = SearchAlt(&l[hash(p)],p);
	
	for(k=0;k<391;k++){
		e.d[k]='\0';
	}
	
	if(r==NULL)
	{
		return e;
	}
	else
	{		
		return Position(&l[hash(p)],r);	
	}
	
}

int BuscarIndice(lista l[101],elemento e)
{
	int cont=0;
	posicion p,fi;
	
	p=SearchAlt(&l[hash(e.p)],e.p);	
	if(p==NULL)
	{
		return Size(&l[hash(e.p)]);
	
	}else{
		while(p!=NULL)
		{
			cont++;
			p=p->siguiente;
		}
	}
	return cont;
}

void Modificar(lista l[101],elemento e,char d[391])
{
	int m = 0, n = 0;
	posicion p;
	
	p=Search(&l[hash(e.p)],e);
	
	for(m=strlen(d);m<391;m++)
	{
		d[m]='\0';
	}	
	for(n=0;n<391;n++)
	{
		e.d[n]=d[n];
	}
	//printf("%s\n",e.p);
	Replace(&l[hash(e.p)],p,e);
}

void Eliminar(lista l[101],char p[51], elemento e)
{
	posicion r;
	
	if(strlen(e.d)==0)
	{
		printf("No se encontro la palabra que deseas eliminar\n");
	}
	else
	{		
		r=SearchAlt(&l[hash(p)],p);
		Remove(&l[hash(p)],r);
		printf("Se elimino correctamente\n");
	}
	return;
}