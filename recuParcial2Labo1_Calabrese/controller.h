/*
 * controller.h
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "linkedList.h"


#endif /* CONTROLLER_H_ */

/**
 * @fn int controller_loadFromText(LinkedList*)
 * @brief Carga los datos de las compras desde el archivo .csv (modo texto).
 *
 * @param pArrayListaArticulo LinkedList* Puntero a la lista de compras.
 * @return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_loadFromText(LinkedList* pArrayListaArticulo);

/**
 * @fn int controller_MostrarArticulos(LinkedList*)
 * @brief Funcion para listar todos las compras.
 *
 * @param pArrayListaArticulo LinkedList* Puntero a la lista de compras.
 * @return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_MostrarArticulos(LinkedList* pArrayListaArticulo);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief  Funcion que guarda como un archivo como texto.
 *
 * @param path char* nombre del archivp
 * @param pArrayListaArticulos  LinkedList* Puntero a la lista de compras.
 * @return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListaArticulos);

/**
 * @fn int controller_asignarTotales(LinkedList*)
 * @brief  Funcion que asigna precios totales
 *
 * @param pArrayListaArticulos  LinkedList* Puntero a la lista de compras.
 * @return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_asignarTotales(LinkedList* pArrayListaArticulos);

/**
 * @fn int controller_FiltroTipoJugueteria(LinkedList*)
 * @brief funcion que filtra todas las compras de tipo jugueteria
 *
 * @param pArrayListaArticulos LinkedList* Puntero a la lista de compras.
 * @return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_FiltroTipoJugueteria(LinkedList* pArrayListaArticulos);

int controller_FiltroTipoElectronica(LinkedList* pArrayListaArticulos);

int controller_FiltroTipoIndumentaria(LinkedList* pArrayListaArticulos);

int controller_FiltroTipoCalzado(LinkedList* pArrayListaArticulos);

/**
 * @fn int controller_sortDescripcion(LinkedList*)
 * @brief funcion que ordena las compras
 *
 * @param pArrayListaServicios LinkedList* Puntero a la lista de compras.
 * @return  int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_sortDescripcion(LinkedList* pArrayListaServicios);
