/*
 * docente.h
 *
 *  Created on: 1 ago 2022
 *      Author: antonella
 */

#ifndef DOCENTE_H_
#define DOCENTE_H_

typedef struct{
	int legajoDocente;
	char nombre[25];
	int edad;
	char telefono[15];
	int isEmpty;
}eDocente;

#endif /* DOCENTE_H_ */

/**
 * @fn void inicializarDocentes(eDocente*)
 * @brief funcion de tipo entero que recibe por parametro la estructura de docentes y el tamaño
 *
 * @param listaD
 */
void inicializarDocentes(eDocente* listaD);

/**
 * @fn void mostrarDocente(eDocente)
 * @brief
 *
 * @param unaDocente
 */
void mostrarDocente(eDocente unaDocente);

/**
 * @fn int mostrarDocentes(eDocente*, int)
 * @brief
 *
 * @param listaD
 * @param tamD
 * @return
 */
int mostrarDocentes(eDocente* listaD, int tamD);
