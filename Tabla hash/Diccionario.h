/*
LIBRERÍA DICCIONARIO

AUTORES:
LEÓN REYES MARCOS
PACHECO HERNÁNDEZ ARIEL AARON
FECHA: 
16/05/2018
VERSIÓN: 1

DESCRIPCIÓN: Operaciones que permiten interactuar con un diccionario basado en una tabla hash.

*/



#include "TADListaDL.h"

void Agregar(lista l[101],char palabra[442]);
elemento Buscar(lista l[101],char p[51]);
int BuscarIndice(lista l[101],elemento e);
void Modificar(lista l[101],elemento e,char d[391]);
void Eliminar(lista l[101],char p[51],elemento e);
void Salir();

//Función hash
int hash(char p[51]);