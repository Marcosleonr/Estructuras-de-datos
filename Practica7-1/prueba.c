#include<stdio.h>
typedef struct persona
{
	char nombre[20];
	char apellido[20];
	int edad;
}persona;

int main(void)
{
	persona a[10];
	int i;
	FILE* archivo;
	archivo=fopen("salida.txt","wb");
	fseek(archivo,0,SEEK_SET);
	fread(&a,sizeof(persona),10,archivo);

	for(i=0)
	scanf("%s",&(a.nombre));
	scanf("%s",&(a.nombre));
	scanf("%d",&(a.edad));
	
		
	fwrite(&a,sizeof(persona),1,archivo);
	fclose(archivo);
	
	
	return 0;
}