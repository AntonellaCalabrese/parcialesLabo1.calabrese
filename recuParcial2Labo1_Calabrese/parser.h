/*
 * parser.h
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "linkedList.h"


#endif /* PARSER_H_ */
/**
 * @fn int parser_articuloFromText(FILE*, LinkedList*)
 * @brief  Parsea los datos los datos de los articulos desde el archivo articulos.csv
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListArticulos puntero a la lista de servicios.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_articuloFromText(FILE* pFile , LinkedList* pArrayListArticulos);
