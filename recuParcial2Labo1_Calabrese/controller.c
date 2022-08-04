/*
 * controller.c
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>

#include "articulos.h"
#include "parser.h"
#include "linkedList.h"
#include "articulos.h"
#include "input-UTN.h"

int controller_loadFromText(LinkedList* pArrayListaArticulo)
{
	int todoOk = 0;
	FILE* f;
	char path[20];

	if(pArrayListaArticulo != NULL)
	{
	    ll_clear(pArrayListaArticulo);
	    printf("Ingrese el nombre del archivo a cargar. sugerencia: articulos.csv-\n");
        fflush(stdin);
        gets(path);

		f = fopen(path, "r");

        if(f != NULL)
        {
        	parser_articuloFromText(f, pArrayListaArticulo);
            printf("Lista cargada exitosamente!!\n");
            todoOk = 1;
        }
        else
        {
            printf("No existe una lista con ese nombre.\n");
        }
	}

    return todoOk;
}

int controller_MostrarArticulos(LinkedList* pArrayListaArticulo)
{
	int todoOk = 0;
	eCompras* newArticulo ;
	if(pArrayListaArticulo != NULL)
	{
		printf("                         *** Listado de los Articulos ***\n");
		printf("-----------------------------------------------------------------------------------------------------------\n");
		printf("|Id   |descripcion       |Tipo Articulo       |Precio  Unitario       |Cantidad       |Total Bulto      \n");
		printf("-----------------------------------------------------------------------------------------------------------\n");


		for(int i = 0; i < ll_len(pArrayListaArticulo); i++)
		{
			newArticulo = ll_get(pArrayListaArticulo, i);
			if(newArticulo != NULL)
			{
				articulo_mostrarArticulo(newArticulo);
				todoOk = 1;
			}
		}
	}
    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListaArticulos)
{
	int todoOk=0;
	FILE* f;
	int id_Articulo;
	char descripcion[120];
	int tipoArticulo;
	float precioUnitario;
	int cantidad;
	float totalBulto;

	eCompras* nuevoArticulo;

	if(path != NULL && pArrayListaArticulos != NULL)
	{
		f = fopen(path, "w");

		nuevoArticulo = newArticulo();

		fprintf(f, "totalBulto,descripcion,tipoArticulo,precioUnitario,cantidad,totalBulto\n");

		for(int i = 0; i < ll_len(pArrayListaArticulos); i++)
		{
			nuevoArticulo = ll_get(pArrayListaArticulos, i);
			if(nuevoArticulo != NULL)
			{
				articulo_getId(nuevoArticulo, &id_Articulo);
				articulo_getDescripcion(nuevoArticulo, descripcion);
				articulo_getTipoArticulo(nuevoArticulo, &tipoArticulo);
				articulo_getPrecioUnitario(nuevoArticulo, &precioUnitario);
				articulo_getCantidad(nuevoArticulo, &cantidad);
				articulo_getTotalBulto(nuevoArticulo, &totalBulto);

				fprintf(f, "%d,%s,%d,%f,%d,%f\n",id_Articulo,descripcion,tipoArticulo,precioUnitario,cantidad,totalBulto);
				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}


int controller_asignarTotales(LinkedList* pArrayListaArticulos)
{
    int todoOk = 0;

    if(pArrayListaArticulos != NULL)
    {
        ll_map(pArrayListaArticulos, asignarTotales);
        printf("Se asigno correctamente el total calculado a cada servicio\n");
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroTipoJugueteria(LinkedList* pArrayListaArticulos)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaArticulos != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaArticulos, articulos_filtrarTipoJugueteria);
        controller_MostrarArticulos(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoJugueteria.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroTipoElectronica(LinkedList* pArrayListaArticulos)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaArticulos != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaArticulos, articulos_filtrarTipoElectronica);
        controller_MostrarArticulos(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoElectronica.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroTipoIndumentaria(LinkedList* pArrayListaArticulos)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaArticulos != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaArticulos, articulos_filtrarTipoIndumentaria);
        controller_MostrarArticulos(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoIndumentaria.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroTipoCalzado(LinkedList* pArrayListaArticulos)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaArticulos != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaArticulos, articulos_filtrarTipoCalzado);
        controller_MostrarArticulos(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoCalzado.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortDescripcion(LinkedList* pArrayListaServicios)
{
	int todoOk = 0;
	int criterio;


	if(pArrayListaServicios != NULL)
	{
		criterio = menuDeSort();
		if(ll_isEmpty(pArrayListaServicios) == 0)
		{
			ll_sort(pArrayListaServicios, articulo_SortDescripcion, criterio);
            controller_MostrarArticulos(pArrayListaServicios);
            printf("Ordenamiento de manera Ascendente exitoso!!!\n");
            todoOk = 1;
		}
		else
		{
			printf("La lista esta vacia y no se puede ordenar\n");
			todoOk=0;
		}

		ll_deleteLinkedList(pArrayListaServicios);

	}
    return todoOk;
}





