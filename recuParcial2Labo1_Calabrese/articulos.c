/*
 * articulos.c
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "linkedList.h"
#include "parser.h"
#include "articulos.h"

eCompras* newArticulo()
{
	eCompras* newArticulo;

	newArticulo = (eCompras*) malloc(sizeof(eCompras));
	if(newArticulo != NULL)
	{
		newArticulo->id_articulo = 0;
		strcpy(newArticulo->descripcion, "-");
		newArticulo->tipoArticulo= 0;
		newArticulo->precioUnitario = 0;
		newArticulo->cantidad = 0;
		newArticulo->totalBulto = 0;
	}

	return newArticulo;
}

eCompras* articulo_NewParametros(char* idStr ,char* descripcionStr, char* tipoarticuloStr, char* precioUnitarioStr, char* cantidadStr, char* totalBultoStr)
{
	eCompras* articuloNuevo;

	articuloNuevo = newArticulo();
	if(articuloNuevo != NULL)
	{
		if(!(articulo_setId(articuloNuevo, atoi(idStr))
		   && articulo_setDescripcion(articuloNuevo, descripcionStr)
		   && articulo_setTipoArticulo(articuloNuevo, atoi(tipoarticuloStr))
		   && articulo_setPrecioUnitario(articuloNuevo, atof(precioUnitarioStr))
		   && articulo_setCantidad(articuloNuevo, atoi(cantidadStr))
		   && articulo_setTotalBulto(articuloNuevo, atof(totalBultoStr))
		   ))
		   {
				eliminarArticulo(articuloNuevo);
				articuloNuevo = NULL;
		   }
	}
	return articuloNuevo;
}

int articulo_mostrarArticulo(eCompras* unArticulo)
{
	int allOk=0;
	int id_Articulo;
	char descripcion[120];
	int tipoArticulo;
	float precioUnitario;
	int cantidad;
	float totalBulto;

	if(unArticulo != NULL)
	{
		articulo_getId(unArticulo, &id_Articulo);
		articulo_getDescripcion(unArticulo, descripcion);
		articulo_getTipoArticulo(unArticulo, &tipoArticulo);
		articulo_getPrecioUnitario(unArticulo, &precioUnitario);
		articulo_getCantidad(unArticulo, &cantidad);
		articulo_getTotalBulto(unArticulo, &totalBulto);

		printf("%d    %-25s   %d             %.2f                   %-4d             %.2f\n",id_Articulo,descripcion,tipoArticulo,precioUnitario,cantidad,totalBulto);
		allOk=1;
	}

	return allOk;
}


void eliminarArticulo(eCompras* unServicio)
{
	free(unServicio);
}


int articulo_setId(eCompras* unArticulo, int idArticulo)
{
	int todoOk = 0;
	if(unArticulo != NULL && idArticulo > 0)
	{
		unArticulo->id_articulo = idArticulo;
		todoOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return todoOk;
}

int articulo_getId(eCompras* this,int* idArticulo)
{
	int todoOk = 0;
	if(this != NULL && idArticulo != NULL)
	{
		*idArticulo = this->id_articulo;
		todoOk = 1;
	}
	return todoOk;
}

int articulo_setDescripcion(eCompras* this,char* descripcionArticulo)
{
	int allOk=0;

	if(this != NULL && descripcionArticulo != NULL)
	{
		strcpy(this->descripcion,descripcionArticulo);
	}
	allOk=1;

    return allOk;
}

int articulo_getDescripcion(eCompras* this, char* descripcionArticulo)
{
	int allOk = 0;
	if(this != NULL && descripcionArticulo != NULL)
	{
		strcpy(descripcionArticulo, this->descripcion);
		allOk = 1;
	}
	return allOk;
}

int articulo_setTipoArticulo(eCompras* this,int tipoArticulo)
{
	int allOk=0;

	if(this != NULL && tipoArticulo >0)
	{
		this->tipoArticulo = tipoArticulo;
	}
	allOk=1;

    return allOk;
}

int articulo_getTipoArticulo(eCompras* this, int* tipoArticulo)
{
	int allOk = 0;
	if(this != NULL && tipoArticulo >0)
	{
		*tipoArticulo= this->tipoArticulo;
		allOk = 1;
	}
	return allOk;
}

int articulo_setPrecioUnitario(eCompras* this,float precioUnitario)
{
	int allOk=0;

	if(this != NULL && precioUnitario > 0 && precioUnitario <= 1000000000)
	{
		this->precioUnitario= precioUnitario;
	}
	allOk=1;

    return allOk;
}

int articulo_getPrecioUnitario(eCompras* this, float* precioUnitario)
{
    int allOk=0;

    if(this != NULL && precioUnitario != 0)
    {
    	*precioUnitario=this->precioUnitario;
    	allOk=1;
    }

    return allOk;
}

int articulo_setCantidad(eCompras* this,int cantidadArticulo)
{
	int allOk=0;

	if(this != NULL && cantidadArticulo > 0 && cantidadArticulo <= 100)
	{
		this->cantidad= cantidadArticulo;
	}
	allOk=1;

    return allOk;
}

int articulo_getCantidad(eCompras* this, int* cantidadArticulo)
{
    int allOk=0;

    if(this != NULL && cantidadArticulo != 0)
    {
    	*cantidadArticulo=this->cantidad;
    	allOk=1;
    }

    return allOk;
}

int articulo_setTotalBulto(eCompras* this,float totalBulto)
{
	int allOk=0;

	if(this != NULL && totalBulto > 0 && totalBulto <= 1000000000)
	{
		this->totalBulto= totalBulto;
	}
	allOk=1;

    return allOk;
}

int articulo_getTotalBulto(eCompras* this, float* totalBulto)
{
    int allOk=0;

    if(this != NULL && totalBulto != 0)
    {
    	*totalBulto=this->totalBulto;
    	allOk=1;
    }

    return allOk;
}

void* asignarTotales(void* elemento)
{
	eCompras* unArticulo = NULL;
	unArticulo = (eCompras*) elemento;
	int cantidad;
	articulo_getCantidad(unArticulo, &cantidad);
	float precioUnitario;
	articulo_getPrecioUnitario(unArticulo, &precioUnitario);
	int total;

	if(elemento != NULL)
	{
		total=precioUnitario*cantidad;
		articulo_setTotalBulto(unArticulo, total);
	}
	return unArticulo;
}


int articulos_filtrarTipoJugueteria(void* elemento)
{
	eCompras* aux = NULL;
	int todoOk = 0;
	aux = (eCompras*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoArticulo == 1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int articulos_filtrarTipoElectronica(void* elemento)
{
	eCompras* aux = NULL;
	int todoOk = 0;
	aux = (eCompras*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoArticulo == 2)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int articulos_filtrarTipoIndumentaria(void* elemento)
{
	eCompras* aux = NULL;
	int todoOk = 0;
	aux = (eCompras*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoArticulo == 3)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int articulos_filtrarTipoCalzado(void* elemento)
{
	eCompras* aux = NULL;
	int todoOk = 0;
	aux = (eCompras*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoArticulo == 4)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int articulo_SortDescripcion(void* item1, void* item2)
{
	int todoOk = 0;
	eCompras* Articulo1 = NULL;
	eCompras* Articulo2 = NULL;
	char descripcion1[130];
	char descripcion2[130];

	Articulo1 = (eCompras*) item1;
	Articulo2 = (eCompras*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(articulo_getDescripcion(Articulo1, descripcion1)==1 && articulo_getDescripcion(Articulo2, descripcion2)==1)
		{
			if(strcmp(descripcion1, descripcion2)>0)
			{
				todoOk = 1;
			}
			else if(strcmp(descripcion1, descripcion2)<0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}
