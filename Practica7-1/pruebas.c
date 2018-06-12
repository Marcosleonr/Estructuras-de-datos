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
	archivo=fopen("salida.txt","rb");
	
	fread(&a,sizeof(persona),10,archivo);
	for(i=0;i<9;i++)
		printf("Nombre: %s \tApellido: %s \nEdad: %d",&(a.nombre),&(a.apellido),&(a.edad));
	
	fseek(archivo,0,SEEK_SET);
	fwrite(&a,sizeof(persona),1,archivo);
	fclose(archivo);
	
	
	return 0;
}