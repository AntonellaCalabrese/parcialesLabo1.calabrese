/*
 * grado.h
 *
 *  Created on: 1 ago 2022
 *      Author: antonella
 */
#include "docente.h"
#ifndef GRADO_H_
#define GRADO_H_

typedef struct{
	int  tipoGrado;
	char descripcion[20];
}eTipoGrado;

typedef struct{
	int idGrado;
	char curso[25];
	int capacidad;
	int cantidadPc;
	int tipoGrado;
	int legajoDocente;
	int isEmpty;
}eGrado;

#endif /* GRADO_H_ */
/**
 * @fn int inicializarGrado(eGrado*, int)
 * @brief funcion de tipo entero que recibe por parametro la estructura de grado y el tamaño
 *
 * @param lista
 * @param tam
 * @return devuelve 0 si todo salio bien
 */
int inicializarGrado(eGrado* lista, int tam);

/**
 * @fn int buscarLibre(eGrado*, int)
 * @brief funcion de tipo entero para buscar un espacio libre en memoria para un grado
 *
 * @param lista
 * @param tam
 * @return retorna el indice de donde encontro una estructura libre
 */
int buscarLibre(eGrado* lista, int tam);

/**
 * @fn void mostrarGrado(eGrado)
 * @brief
 *
 * @param unGrado
 */
void mostrarGrado(eGrado unGrado);

/**
 * @fn int mostrarGrados(eGrado*, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @return
 */
int mostrarGrados(eGrado* lista, int tam);

/**
 * @fn int altaGrados(eGrado*, int, int*)
 * @brief funcion de tipo entero para dar de alta un grado
 *
 * @param lista
 * @param tam
 * @param pId puntero a id
 * @return retorna 1 si todo salio bien
 */
int altaGrados(eGrado* lista, int tam , int* pId);

/**
 * @fn int buscarGradoId(eGrado*, int, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @param idVivienda
 * @return
 */
int buscarGradoId(eGrado* lista, int tam, int idVivienda);

/**
 * @fn int menuModificacion()
 * @brief
 *
 * @return
 */
int menuModificacion();

/**
 * @fn int modificacionGrado(eGrado*, int)
 * @brief funcion para que el usuario modifique los datos de uno de los campos de la estructura grado
 *
 *
 * @param lista
 * @param tam
 * @return retorna 1 si todo salio bien
 */
int modificacionGrado(eGrado* lista, int tam);

/**
 * @fn int bajaGrado(eGrado*, int)
 * @brief funcion para dar de baja un grado
 *
 * @param lista
 * @param tam
 * @return retorna 1 si todo salio bien
 */
int bajaGrado(eGrado* lista, int tam);

/**
 * @fn int listarGradosPorCurso(eGrado*, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @return
 */
int listarGradosPorCurso(eGrado* lista,int tam);

/**int ordenarGradoPorCurso(eGrado* lista, int tam, int orden);
 * @fn int submenuListado()
 * @brief
 *
 * @return
 */

int submenuListado();
int submenuTipoGrado();
int submenuTipoDocente();

/**
 * @fn int elegirTipoGrado(eGrado*, eDocente*, int, int)
 * @brief
 *
 * @param lista
 * @param listaD
 * @param tam
 * @param tamD
 * @return
 */
int elegirTipoGrado(eGrado* lista, eDocente* listaD,int tam , int tamD);

/**
 * @fn int listadoDeGradosYdocentes(eGrado*, int, eDocente*, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @param listaD
 * @param tamD
 * @return
 */
int listadoDeGradosYdocentes(eGrado* lista, int tam , eDocente* listaD, int tamD);

/**
 * @fn int cantDeGrados(eGrado*, eDocente*, int, int)
 * @brief
 *
 * @param lista
 * @param listaD
 * @param tam
 * @param tamD
 * @return
 */
int cantDeGrados(eGrado* lista,eDocente* listaD,int tam,int tamD);

/**
 * @fn int elegirTipoDocente(eGrado*, eDocente*, int, int)
 * @brief
 *
 * @param lista
 * @param listaD
 * @param tam
 * @param tamD
 * @return
 */
int elegirTipoDocente(eGrado* lista, eDocente* listaD,int tam , int tamD);

/**
 * @fn int cantDeGradosTipoAudit(eGrado*, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @return
 */
int cantDeGradosTipoAudit(eGrado* lista,int tam);

/**
 * @fn int cantDePcAula(eGrado*, int)
 * @brief
 *
 * @param lista
 * @param tam
 * @return
 */
int cantDePcAula(eGrado* lista,int tam);

/**
 * @fn int informarLista(eGrado*, eDocente*, int, int)
 * @brief
 *
 * @param lista
 * @param listaD
 * @param tam
 * @param tamD
 * @return
 */
int informarLista(eGrado* lista, eDocente* listaD, int tam, int tamD);




