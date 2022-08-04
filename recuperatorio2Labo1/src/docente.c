/*
 * docente.c
 *
 *  Created on: 1 ago 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"
#include "docente.h"


void inicializarDocentes(eDocente* listaD)
{

	eDocente aux[]= {
					{100, "Ana", 34, "1203-2345"},
					{101, "Juan", 24, "4301-54678"},
					{102, "Sol", 47, "5902-37487"},
					{103, "Sebastian", 28, "4641-35469"},
					{104, "Graciela", 52, "9465-83340"}
					};

	for(int i=0;i<3;i++)
	{
		listaD[i]=aux[i];
	}

}

void mostrarDocente(eDocente unaDocente)
{

	printf(" %4d   %13s     %11d     %14s    \n",
			unaDocente.legajoDocente,
			unaDocente.nombre,
			unaDocente.edad,
			unaDocente.telefono
		);

}

int mostrarDocentes(eDocente* listaD, int tamD)
{
	int allOk=0;

	if(listaD != NULL && tamD>0)
	{
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("               ***LISTADO DOCENTES***                      \n");
		printf("------------------------------------------------------------\n");
		printf("| legajo |     nombre      |     edad     |     telefono    \n");
		for(int i=0; i<tamD; i++)
		{
			mostrarDocente((*(listaD+i)));
		}
		allOk=1;
	}
	return allOk;
}




