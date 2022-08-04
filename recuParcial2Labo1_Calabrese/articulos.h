/*
 * articulos.h
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */

#ifndef ARTICULOS_H_
#define ARTICULOS_H_

typedef struct{
	int id_articulo;
	char descripcion[120];
	int tipoArticulo;
	float precioUnitario;
	int cantidad;
	float totalBulto;
	int isEmpty;
}eCompras;


#endif /* ARTICULOS_H_ */
/**
 * @fn eCompras newArticulo*()
 * @brief  Funcion constructura para crear un nuevo articulo con valores inicializados en 0.
 *
 * @return  Retorna el articulo creado si tuvo exito.
 */
eCompras* newArticulo();

/**
 * @fn eCompras articulo_NewParametros*(char*, char*, char*, char*, char*, char*)
 * @brief Funcion constructora para crear un nuevo articulo a partir de parametros establecidos.
 *
 * @param idStr Puntero a char que contiene el ID que se le quiere asignar al articulo.
 * @param descripcionStr Puntero a char que contiene la descripcion que se le quiere asignar al articulo
 * @param tipoarticuloStr Puntero a char que contiene el tipo que se le quiere asignar al articulo
 * @param precioUnitarioStr Puntero a char que contiene el precio unitario que se le quiere asignar al articulo.
 * @param cantidadStr Puntero a char que contiene la cantidad que se le quiere asignar al articulo.
 * @param totalBultoStr  Puntero a char que contiene el total bruto que se le quiere asignar al articulo.
 * @return eCompras* Retorna la compra creado si tuvo exito.
 */
eCompras* articulo_NewParametros(char* idStr ,char* descripcionStr, char* tipoarticuloStr, char* precioUnitarioStr, char* cantidadStr, char* totalBultoStr);
int articulo_mostrarArticulo(eCompras* unArticulo);
void eliminarArticulo(eCompras* unServicio);

/**
 * @fn int articulo_setId(eCompras*, int)
 * @brief carga el id de un articulo
 *
 * @param unArticulo puntero a la compra del articulo
 * @param idArticulo id a buscar
 * @return Retorna 1 si esta todo OK y 0 si no.
 */
int articulo_setId(eCompras* unArticulo, int idArticulo);
/** \brief busca el id de una compra
 *
 * \param this eCompras* puntero a la compra
 * \param idArticulo int* idArticulo a buscar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int articulo_getId(eCompras* this,int* idArticulo);
int articulo_setDescripcion(eCompras* this,char* descripcionArticulo);
int articulo_getDescripcion(eCompras* this, char* descripcionArticulo);
int articulo_setTipoArticulo(eCompras* this,int tipoArticulo);
int articulo_getTipoArticulo(eCompras* this, int* tipoArticulo);
int articulo_setPrecioUnitario(eCompras* this,float precioUnitario);
int articulo_getPrecioUnitario(eCompras* this, float* precioUnitario);
int articulo_setCantidad(eCompras* this,int cantidadArticulo);
int articulo_getCantidad(eCompras* this, int* cantidadArticulo);
int articulo_setTotalBulto(eCompras* this,float totalBulto);
int articulo_getTotalBulto(eCompras* this, float* totalBulto);

/** \brief funcion que asigna totales al total bulto
 *
 * \param elemento void* elemento a asignar el total
 * \return void*
 *
 */
void* asignarTotales(void* elemento);


int articulos_filtrarTipoJugueteria(void* elemento);
int articulos_filtrarTipoElectronica(void* elemento);
int articulos_filtrarTipoIndumentaria(void* elemento);
int articulos_filtrarTipoCalzado(void* elemento);

/** \brief funcion que decide un criterio para luego ser ordenado
 *
 * \param item1 void* primer item a comparar
 * \param item2 void* segundo item a comparar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int articulo_SortDescripcion(void* item1, void* item2);
