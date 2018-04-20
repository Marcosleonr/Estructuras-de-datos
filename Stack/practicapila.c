/*LIBRERIA: Cabecera de el TAD PILA DINÁMICA
AUTORES:
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
14/03/2018
VERSIÓN: 1.7

DESCRIPCIÓN: Implementación dinámica y estática de la Pila.
1.- Evalúa que los paréntesis de una expresión dada sean los correctos.
2.- Convierte una expresión infija a postfija.
3.- Obtiene el resultado de evaluar una expresión postfija.

COMPILACIÓN Y EJECUCIÓN:

En windows
Para compilar el programa: gcc practicapila.c TADPila(Est/Din).c -o practica -lm
Para ejecutar el programa: practica

En ubuntu
Para compilar el programa: gcc practicapila.c TADPila(Est/Din).c -o programa -lm
Para ejecutar el programa: ./programa
*/

#include <stdio.h>
#include <stdlib.h>	//Funcion exit()
#include <string.h> //Funcion strlen()
#include <math.h> // Funcion pow()
#include <ctype.h> //Funcion isdigit() e isalpha()
#include "TADPilaEst.h" // Libreria estatica
//#include "TADPilaDin.h" // Librería dinamica

#define TAM_CADENA 101 // Tamaño maximo de la cadena a evaluar

int main()
{
	int i,j,m,n,p;
	int tam_cadena = 0;//Guarda el tamaño de la cadena dada
	int cont_pos = 0; //Sirve como el índice del arreglo de la expresión postfija
	
	char cadena[TAM_CADENA]; //Almacena la expresión que ingresa el usuario
	char postfijo[TAM_CADENA]; //Guarda la expresión en postfijo
	double resultado[TAM_CADENA]; //Almacena el valor de las variables ingresadas
	
	//Ayudan a guardar los valores de las variables y evitan que se vuelvan a pedir 
	double cad_aux[91];
	double cad_aux1[91];
	
	int var_cast = 0; //Almacenar el valor en ASCII de la variable ingresada 
	
	//Llena el arreglo auxiliar con ceros para que no tenga basura
	for(int k = 0;k<91;k++)
	{
		cad_aux[k]=0;
	}
	for(int k = 0;k<91;k++)
	{
		cad_aux1[k]=0;
	}
	
	pila pila_cad; // Declaracion de pila para evaluar paréntesis y armar la expresion postfija 
	elemento e1; // Declaracion de elemento para pila_cad

	pila pila_r; //Declaracion de pila para guardar el resultado de la cadena evaluada
	elemento e2;//Declaracion de elementos para pila_r
	elemento e3;//Declaracion de elementos para pila_r
	elemento e4;//Declaracion de elementos para pila_r

	
	Initialize(&pila_cad); // Se incicializa la pila_cad

	printf("Ingrese la cadena a evaluar: \n");
	scanf("%s", cadena);

	tam_cadena=strlen(cadena);

	for(i=0;i<tam_cadena;i++)
	{
		//Si el caracter es ( introducirlo a la pila
		if(cadena[i]=='(')
		{
			e1.c='(';
			Push(&pila_cad,e1); 
		}
		else if(cadena[i]==')')//Si el caracter es ) realizar un Pop a la pila
		{
			//Si se intenta extraer un elemento y la pila es vacia Error
			if(Empty(&pila_cad))
			{
				printf("ERROR: Existen mas parentesis que cierran de los que abren\n");
				exit(1); //Salir del programa con error
			}
			e1=Pop(&pila_cad);
		}
	}
	//Si al terminar de revisar la expresionn aun hay elementos en la pila Error
	if(!Empty(&pila_cad))
	{
		printf("ERROR: Existen mas parentesis que abren de los que cierran\n");
		exit(1); //Salir del programa con error
	}
	
	//Si la ejecucion termina de manera correcta
	printf("EXCELENTE: Expresion correcta\n");
	
	//Destruir los elementos de la pila_cad
	Destroy(&pila_cad);

	Initialize(&pila_cad);//Se inicializa la pila_cad
	
	//Recorre la cadena para reconocer que elementos ingresó
	for(m=0;m<tam_cadena;m++)
	{
		//Si hay un parentesis que abre se mete a la pila directamente
		if(cadena[m]=='('){	
			e1.c='(';
			Push(&pila_cad,e1);
			
		}
		//Si hay un parentesis que cierra, saca todo de la pila 
		else if(cadena[m]==')')
		{
			//Mientras no encuetre un paréntesis que abre en la pila, saca los elementos
			while (e1.c!='(')
			{
				postfijo[cont_pos]=e1.c; //Guarda el valor del tope en la cadena postfija
				cont_pos++;//Aumenta el valor del índice de la expresión|
				e1=Pop(&pila_cad);//Saca el tope de la pila
				
				//Después de hacer el pop, revisa que el elemento del tope paréntesis que abre
				e1=Top(&pila_cad); 
				//En caso de que el tope sea un parentesis, hace un break para no seguir sacando elementos.
				if(e1.c=='(')
				{
					break;
				}
			}
			
			e1=Pop(&pila_cad);// Saca el paréntesis que está en el tope de la pila
			
			//Si la pila no está vacía, asigna al elemento el tope de la pila|
			if (!Empty(&pila_cad))
			{ 
				e1=Top(&pila_cad);
			}
		}
		else if(cadena[m]=='^')
		{
			//Si el tope de la  pila no es una potencia o está vacía, hace push de la potencia a la pila
			if(e1.c!='^'||(Size(&pila_cad))==0)
			{
				e1.c='^';
				Push(&pila_cad,e1);
			}
			else if(e1.c=='^')
			{
				//Agrega el elemento a la cadena postfija y después lo saca de la pila 
				postfijo[cont_pos]=e1.c;
				cont_pos++;
				e1=Pop(&pila_cad);
				//Agrega a la pila la potencia que venía de la cadena
				e1.c='^';
				Push(&pila_cad,e1);
			}
		}
		else if(cadena[m]=='*')
		{
	
			//Revisa que el tope de la pila sea igual + , -, ( o esté vacío
			if((Size(&pila_cad))==0 || e1.c=='+' || e1.c=='-' || e1.c=='(')
			{
				//Agrega directamente la multiplicación a la pila
				e1.c='*';
				Push(&pila_cad,e1);
			}else{
				
				postfijo[cont_pos]=e1.c;
				cont_pos++;
				e1=Pop(&pila_cad);
				if(!Empty(&pila_cad))
				{
					e1=Top(&pila_cad);
					
					/*Si el elemento del tope después de hacer el pop es * o /, 
					vuelve a hacer el pop mientras no encuentre algo diferente*/
					while(e1.c== '*' || e1.c=='/')
					{
						postfijo[cont_pos]=e1.c;
						cont_pos++;
						e1=Pop(&pila_cad);
						//Revisa que esté vacía y en caso de que no guarda el valor del tope de la pila
						if(Empty(&pila_cad))
						{
							break;
						}else{
							e1=Top(&pila_cad);
						}
					}
				}
				e1.c='*';
				Push(&pila_cad,e1);
			}

		}
		//El funcinamiento cuando encuentra una división es exactamene igual al de la multiplicación 
		else if(cadena[m]=='/')
		{
	
			if((Size(&pila_cad))==0 || e1.c=='+' || e1.c=='-' || e1.c=='(')
			{
				e1.c='/';
				Push(&pila_cad,e1);
			}else{
				postfijo[cont_pos]=e1.c;
				cont_pos++;
				e1=Pop(&pila_cad);
				
				if(!Empty(&pila_cad))
				{	
					e1=Top(&pila_cad);	
					while(e1.c== '*' || e1.c=='/')
					{
						postfijo[cont_pos]=e1.c;
						cont_pos++;
						e1=Pop(&pila_cad);
						if(Empty(&pila_cad))
						{
							break;
						}else{
							e1=Top(&pila_cad);
						}
					}
				}
				e1.c='/';
				Push(&pila_cad,e1);
			}
		}
		else if(cadena[m]=='+')
		{
			if((Size(&pila_cad))==0 || e1.c=='(')
			{
				//Agrega directamente la suma a la pila
				e1.c='+';
				Push(&pila_cad,e1);
			}else{
				
				postfijo[cont_pos]=e1.c;
				cont_pos++;
				e1=Pop(&pila_cad);
				
				if(!Empty(&pila_cad))
				{
					e1=Top(&pila_cad);
					
					/*Si el elemento del tope después de hacer el pop es +, -, *, /, 
					vuelve a hacer el pop mientras no encuentre algo diferente*/
					
					while(e1.c== '*' || e1.c=='/' || e1.c=='+' || e1.c=='-')
					{
						postfijo[cont_pos]=e1.c;
						cont_pos++;
						e1=Pop(&pila_cad);
						//Revisa que esté vacía y en caso de que no guarda el valor del tope de la pila
						if(Empty(&pila_cad))
						{
							break;
						}else{
							e1=Top(&pila_cad);
						}
					}
				}
				
				e1.c='+';
				
				Push(&pila_cad,e1);
			}
		//El funcinamiento cuando encuentra una resta es exactamene igual al de la suma 
		}
		else if(cadena[m]=='-')
		{
			
			if((Size(&pila_cad))==0 || e1.c=='(')
			{
				e1.c='-';
				Push(&pila_cad,e1);
			}else{
				postfijo[cont_pos]=e1.c;
				cont_pos++;
				e1=Pop(&pila_cad);
				
				if(!Empty(&pila_cad))
				{
					e1=Top(&pila_cad);
					
					while(e1.c== '*' || e1.c=='/' || e1.c=='+' || e1.c=='-')
					{
						postfijo[cont_pos]=e1.c;
						cont_pos++;
						e1=Pop(&pila_cad);
						if(Empty(&pila_cad))
						{
							break;
						}else{
							e1=Top(&pila_cad);
						}
					}
				}
				e1.c='-';
				Push(&pila_cad,e1);
			}
		}
		//Cuando encuentra una letra la mete directo a la expresión postfija sin hacer ninguna operación sobre la pila
		else if(cadena[m]>='A' || cadena[m]<='Z')
		{
			postfijo[cont_pos]=cadena[m];
			cont_pos++;
		}
	}
	
	//Si se acaba de recorrer el arreglo y quedan elementos en la pila, se sacan y se agregan a la cadena postfija
		
	while(!Empty(&pila_cad))
	{ 
		postfijo[cont_pos]=e1.c;
		cont_pos++;
		e1=Pop(&pila_cad);
		if(!Empty(&pila_cad))
		{
			e1=Top(&pila_cad);
		}
	}

	//Se imprime la expresión postfija que se almacenó en el arreglo postfijo
	printf("EXPRESION POSTFIJA: ");
	for(j=0;j<cont_pos;j++)
	{
		printf("%c", postfijo[j]);
	}
	
	printf("\n");
	//Destruir los elementos de la pila_cad
	Destroy(&pila_cad);

	//Se inicializa la pila_r
	Initialize(&pila_r);
	
	//Recorre la cadena postfijo para ir evaluando la expresión
	for(n=0;n<cont_pos;n++)
	{	
		//Al encontrar un operador suma dentro de la cadena
		if(postfijo[n]=='+')
		{
			e3=Pop(&pila_r);//Se hace pop del último elemento que esté en la pila(A,B,C,...) y se mantiene el valor en e3
			e4=Pop(&pila_r);//Se hace pop del último elemento que esté en la pila(A,B,C,...) y se mantiene el valor en e4
			/*Se realiza la operación suma entre los dos elementos que fueron sacados de la pila 
			previamente y se almacena el resultado en e2*/
			e2.d=e4.d+e3.d; 
			Push(&pila_r, e2);//El resultado de la operación anterior se agrega a la pila	
		
		}
		//Al encontrar un operador resta dentro de la cadena
		else if(postfijo[n]=='-')
		{
			//Las siguientes dos líneas de código realizan exactamente la misma función que cuando se encuentra un operador suma
			e3=Pop(&pila_r);
			e4=Pop(&pila_r);
			/*Se realiza la operación resta entre los dos elementos
			que fueron sacados de la pila previamente y se almacena el resultado en e2*/
			e2.d=e4.d-e3.d; 
			Push(&pila_r, e2);//El resultado de la operación anterior se agrega a la pila
		
		}
		//Al encontrar un operador multiplicación dentro de la cadena
		else if(postfijo[n]=='*')
		{
			//Las siguientes dos líneas de código realizan exactamente la misma función que cuando se encuentra un operador suma
			e3=Pop(&pila_r);
			e4=Pop(&pila_r);
			e2.d=e4.d*e3.d;//Se realiza la operación multiplicación entre los dos elementos que fueron sacados de la pila previamente y se almacena el resultado en e2
			Push(&pila_r, e2);//El resultado de la operación anterior se agrega a la pila
		
		}
		//Al encontrar un operador división dentro de la cadena
		else if(postfijo[n]=='/')
		{
			//Las siguientes dos líneas de código realizan exactamente la misma función que cuando se encuentra un operador suma
			e3=Pop(&pila_r);
			e4=Pop(&pila_r);
			e2.d=(e4.d)/(e3.d);//Se realiza la operación división entre los dos elementos que fueron sacados de la pila previamente y se almacena el resultado en e2
			Push(&pila_r, e2);//El resultado de la operación anterior se agrega a la pila
		
		}
		//Al encontrar un operador potencia dentro de la cadena
		else if(postfijo[n]=='^')
		{
			//Las siguientes dos líneas de código realizan exactamente la misma función que cuando se encuentra un operador suma
			e3=Pop(&pila_r);
			e4=Pop(&pila_r);
			e2.d=pow(e4.d,e3.d);//Se eleva el segundo elemento que fue sacado de la pila al valor del primer elemento que fue sacado de la pila y se almacena el resultado en e2
			Push(&pila_r, e2);//El resultado de la operación anterior se agrega a la pila
		
		}
		//Al encontrar un operando dentro de la cadena (A,B,C,....)
		//La función isalpha retorna un valor diferente de cero cuando el caracter que está evaluando pertenece al alfabeto
		else if(isalpha(postfijo[n])!=0)
		{
			/*La letra que reciba la pasa a su valor entero en ASCII, en caso de que 
			  se reciba una letra minúscula, también la pasa a mayúscula.
			*/
			var_cast =toupper(postfijo[n]);
			
			/*El valor que recibe var_cast se emplea como posición del arreglo cad_aux
			  Esa posición del arreglo se va a reservar únicamente para las letras
			  que tengan como valor en ASCII el mismo que var_cast(Siempre va a ser una misma letra)
			  Para efectos prácticos se llenó, en la parte superior del código, todo el arreglo de ceros.
			*/
			
			if(cad_aux[var_cast]==0)
			//Si cad_ aux en la posición var_cast == 0 significa que no hay ningún valor almacenado previamente
			{				
				//Se pide el valor que será introducido a la pila
				printf("Cuanto vale %c:",postfijo[n]);
				scanf("%lf",&resultado[n]);
				
				//Si el valor que recibe es igual a 0
				if(resultado[n]==0)
				{
					/*Se guardará un 1 en dos arreglos distintos
					para que si vuelve a aparecer la letra, no se pida nuevamente el valor*/
					cad_aux[var_cast]=1;//Se guardara un 1 en el arreglo cad_aux para denotar que esa posición ya se ocupó
					cad_aux1[var_cast]=1;
					
					e2.d=resultado[n];//Se iguala e2 con el valor que ingresó el usuario (en este caso con 0)
					Push(&pila_r,e2);//Se ingresa el valor a la pila
					
				//Si el valor que recibe es dintinto de 0
				}else{
					/*Se guardara el valor ingresado en el arreglo cad_aux, en la posición de la letra en ASCII 
					para que si vuelve a aparecer la letra, no se pida nuevamente el valor*/
					cad_aux[var_cast]=resultado[n];
					e2.d=resultado[n];//Se iguala e2 con el valor que ingresó el usuario
					Push(&pila_r,e2);//Se ingresa el valor a la pila
				}
			//Si cad_ aux en la posición var_cast != 0 significa que ya se tiene un valor almacenado previamente
			}else{
				/*Esta parte del código compara si el valor cero ya estaba almacenado.
				  Si ambos auxiliares son iguales a 1 significa que el valor reservado 
				  previamente en el arreglo cad_aux en la posición var_aux corresponde a un 0*/
				if(cad_aux[var_cast]==1 && cad_aux1[var_cast]==1)
				{
					e2.d = 0;//Se iguala e2 a 0
					Push(&pila_r,e2);//Se ingresa el valor a la pila
				
				//Se busca el valor que ya se tenía guardado dentro de cad_aux en la posición var_cast
				}else{
					
					e2.d = cad_aux[var_cast];//Se iguala e2 al valor que se tenía almacenado previamente
					Push(&pila_r,e2);//Se ingresa el valor a la pila
				}
			}
		//Al encontrar un valor numérico dentro de la cadena
		//La función isdigit retorna un valor diferente de cero cuando el caracter que está evaluando es un dígito
		}else if(isdigit(postfijo[n])!=0)
		{
			//Pasa el número que está representado en char a su valor numérico
			e2.d = (double)postfijo[n]-48;//Se le restan 48 al casteo para que el valor en ascii concuerde con el valor numérico que se dectectó en la cadena
			Push(&pila_r,e2);//Se ingresa el valor a la pila
		}
	}
	//Se obtiene el último elemento que se encuentra en la pila, el cual es el resultado de evaluar la espresión postfija
	e2=Pop(&pila_r);
	printf("El resultado es: ");
	printf("%lf\n", e2.d);
	
	//Destruir los elementos de la pila_r
	Destroy(&pila_r);

	
	return 0;
}