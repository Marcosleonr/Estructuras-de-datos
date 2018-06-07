#include<stdio.h>
#include<string.h>

#define NUM_ELEMENT 256
//#include "TADArbolBin.h"

//Definición de nuevo tipo de elemento
typedef struct elementos
{
	int sum;
	char c;
}elementos;

void Merge(elementos e[],int p, int q, int r);
void Merge_Sort(elementos e[],int p,int r);

elementos pair[NUM_ELEMENT];

void Frecuencia(char cadena[1001])
{
	
	int tam,i,cast;
	tam = strlen(cadena);
	for(i=0;i<tam;i++)
	{
		cast = (int)cadena[i];
		if(!(cast==10)){
			pair[cast].sum++;
			pair[cast].c = cadena[i];
		}	
	}
}

int main(void)
{
	int i;
	char c;
	char nom[51];//Nombre del archivo que se va a leer
	char cad[1001];//Se modifica segun la longitud de cada linea
	
	FILE *file;
	
	printf("CODIFICACION HUFFMAN\n");
	printf("Ingresa la ruta del archivo\n");
	gets(nom);
	file=fopen(nom,"r");
	if(file==NULL)
	{
		printf("Error durante el manejo del archivo\n");
	}
	else
	{
		while(fgets(cad,1001,file))
		{
			Frecuencia(cad);
		}
		fclose(file);
		printf("Se cargo exitosamente el archivo\n");
	}
	
	Merge_Sort(pair,0,255);
	
	for(i=0;i<256;i++)
	{
		printf("%d %c %d\n",i,pair[i].c,pair[i].sum);
	}
	
return 0;
}

void Merge(elementos e[],int p, int q, int r)
{
	int n1,n2,i,j,k;
	
	n1 = q-p+1;//# de elementos que tendrá el arreglo izquierdo
	n2 = r-q;//# de elementos que tendrá el arreglo derecho 
	
	//Se agrega un elemento en cada arreglo auxiliar, ya que se utilizará como bandera
	int L[n1+1],R[n2+1]; 
	char c[n1+1],d[n2+1];

	
	for(i=1;i<=n1;i++)
	{
		L[i]=e[p+i-1].sum;
		c[i]=e[p+i-1].c;
	}
	for(j=1;j<=n2;j++)
	{
		R[j]=e[q+j].sum;
		d[j]=e[q+j].c;
	}
	
	L[n1+1]=10000002;
	R[n2+1]=10000002;
	
	i=1;
	j=1;
	
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			e[k].sum=L[i];
			e[k].c=c[i];
			i++;
		}
		else
		{
			e[k].sum=R[j];
			e[k].c=d[j];
			j++;
		}
	}
}

void Merge_Sort(elementos e[],int p,int r)
{
	int q;
	if(p<r)
	{
		q = ((p+r)/2);
		Merge_Sort(e,p,q);
		Merge_Sort(e,q+1,r);
		Merge(e,p,q,r);
	}
}
