/*
 * input-UTN.c
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos)
{
	int retorno=-1;
	int bufferInt;

	do{
		if(pResultado != NULL && mensaje != NULL && msjError != NULL && min<= max && reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt>=min && bufferInt<=max){
				*pResultado=bufferInt;
				retorno=0;
				break;
			}else{
				printf("%s", msjError);
				reintentos--;
			}
		}
	}while(reintentos>=0);
	return retorno;
}




int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracterVal1 && caracterIngresado != caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}

int menuDeSort()
{
    int option;

    system("cls");
    printf("        *** Ingrese una opcion***          \n");
    printf("------------------------------------------------\n");
    printf("   1- Ascendant.(A-Z) (0-9)\n");

    scanf("%d", &option);

    return option;
}

int menuDeArticulos()
{
    int option;

    system("cls");
    printf("        *** Ingrese una opcion***          \n");
    printf("------------------------------------------------\n");
    printf("1- Jugueteria   \n");
    printf("2- Electronica  \n");
    printf("3- Indumentaria \n");
    printf("4- Calzado      \n");

    scanf("%d", &option);

    return option;
}
