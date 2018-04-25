#include<stdio.h>
int main(void){
	
	/*
	int a = 0;
	char b[10];
	char c;
	printf("%d\n",sizeof(char));
		
	scanf("%c",&b[0]);
	
	printf("Address of var1 variable: %x\n", &b[0]);
	
	c = getchar();
	
    scanf("%c",&b[1]);
	printf("Address of var1 variable: %x\n", &b[1]);
	
	c = getchar();
	scanf("%c",&b[2]);
	printf("Address of var1 variable: %x\n", &b[2]);
	*/
	
	/*int *p;

	int valor = 10;
	
	p = &valor;
	
	printf("%x\n",p);
	
	printf("%d",*p);
	*/
	
	int arr[10];
	
	int *p;
	
	p=&arr[0];
	
	printf("%x\n",p);
	
	printf("%x\n",++p);
	
	return 0;
}