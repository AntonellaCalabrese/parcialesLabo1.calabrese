/*
 * parser.c
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "articulos.h"

int parser_articuloFromText(FILE* pFile , LinkedList* pArrayListArticulos)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eCompras* newArticulos=NULL;
	int r=0;

	pFile=fopen("articulos.csv","r");
	if(pFile==NULL)
	{
		printf("El archivo es nulo");
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);

	while(!feof(pFile))
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
		if(r<6)
		{
			break;
		}
		newArticulos = articulo_NewParametros(var1,var2,var3,var4,var5,var6);

		if(newArticulos!=NULL)
		{
			ll_add(pArrayListArticulos,newArticulos);
			allOk=1;
		}
	}
	fclose(pFile);

	return allOk;
}
