/*
 * grado.c
 *
 *  Created on: 1 ago 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"
#include "grado.h"
#include "docente.h"

// ///////////////////ALTA GRADO/////
int inicializarGrado(eGrado* lista, int tam)
{
	int allOk = -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	(*(lista+i)).isEmpty=1;
	        }
	        allOk = 0;
	    }
	return allOk;
}

int buscarLibre(eGrado* lista, int tam)
{
	int indice= -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	            if((*(lista+i)).isEmpty)
	            {
	                indice = i;
	                break;
	            }
	        }
	    }
	return indice;
}


void mostrarGrado(eGrado unGrado)
{
	eTipoGrado tipos[4]={{1,"Aula"},{2,"Laboratorio"},{3,"Auditorio"},{4,"Salon"}};

	for(int i=0;i<4;i++)
	{
		if(unGrado.tipoGrado == tipos[i].tipoGrado)
		{
			printf(" %3d   %14s    %19d     %15d     %23s     %22d      \n",
					unGrado.idGrado,
					unGrado.curso,
					unGrado.capacidad,
					unGrado.cantidadPc,
					tipos[i].descripcion,
					unGrado.legajoDocente
					);
		}
	}
}



int mostrarGrados(eGrado* lista, int tam)
{
	int allOk=0;
	int flag=1;

	if(lista != NULL && tam>0)
	{
		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
		printf("                                                    ***LISTA GRADOS***                                                     \n");
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente     \n");
		for(int i=0; i<tam; i++)
		{
			if(!(*(lista+i)).isEmpty)
			{
				mostrarGrado((*(lista+i)));
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay grados para dar el alta. \n");
		}
		allOk=1;
	}
	return allOk;
}



int altaGrados(eGrado* lista, int tam , int* pId)
{
	int allOk=0;
	int indice;
	eGrado auxGrado;


		if(lista != NULL && tam>0 && pId != NULL)
		{
			system("cls");
			printf("-----------------------------\n");
			printf("         ALTA GRADOS       \n");
			printf("-----------------------------\n");

			indice=buscarLibre(lista, tam);
			if(indice== -1)
			{
				printf("No hay espacio en el sistema\n");
			}
			else
			{
				auxGrado.idGrado=*pId;
				(*pId)++;

				pedirCadena(auxGrado.curso, "ingrese curso : \n");

				pedirEntero(&auxGrado.capacidad, "Ingrese la capacidad: \n", "error, reingrese capacidad", 1,100);

				pedirEntero(&auxGrado.cantidadPc, "Ingrese cantidad de PC: \n", "error, reingrese cantidad de pc",1,500);

				pedirEntero(&auxGrado.tipoGrado, "Ingrese tipo de Grado: 1: Aula - 2: Laboratorio - 3: Auditorio - 4: Salon \n", "error, reingrese el tipo de grado", 1,4);

				pedirEntero(&auxGrado.legajoDocente,"ingrese numero de legajo: 100/ana - 101/juan - 102/sol 103/Sebastian - 104/graciela \n","el docente ingresado no existe",100,104);

				auxGrado.isEmpty=0;

				lista[indice]=auxGrado;

			}

			allOk=1;
		}
	return allOk;
}

// ///////// MODIFICAR GRADO //////////

int buscarGradoId(eGrado* lista, int tam, int idVivienda)
{
	int indice=-1;

	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	if((*(lista+i)).idGrado == idVivienda && lista[i].isEmpty == 0)
	        	{
	        		indice = i;
	        		break;
	        	}
	        }
	    }
	return indice;
}

int menuModificacion()
{
	int opcion;
	printf("----------------------------------------------\n");
	printf("  Ingrese una de las opciones para modificar \n");
	printf("----------------------------------------------\n");
	printf("1. Curso \n");
	printf("2. Capacidad \n");
	printf("3. Cantidad de PC's \n");
	printf("4. Tipo de grado\n");

	scanf("%d", &opcion);
	return opcion;
}


int modificacionGrado(eGrado* lista, int tam)
{
	int allOk=0;
	int indice;
	char confirma;

	int idGrado;
	char auxCurso[25];
	int auxCapacidad;
	int auxCantidadPc;
	int auxTipoGrado ;


	if(lista!=NULL && tam>0)
	{
		system("cls");
		mostrarGrados(lista, tam);
		printf("  Ingrese el ID del grado para modificar: \n");
		scanf("%d", &idGrado);
		indice=buscarGradoId(lista, tam, idGrado);
		if(indice==-1)
		{
			printf("no hay grados con ID ingresado. %d\n", idGrado);
		}else
		{
			mostrarGrado(lista[indice]);

			printf("confirma modificacion?: s/n \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma=='s')
			{
				switch(menuModificacion())
				{
					case 1:
						pedirCadena(auxCurso, "ingrese nuevo curso : \n");
						strcpy((*(lista+indice)).curso, auxCurso);
						break;
					case 2:
						pedirEntero(&auxCapacidad, "Ingrese la nueva capacidad: \n", "error, reingrese capacidad", 1,100);
						(*(lista+indice)).capacidad=auxCapacidad;
						break;
					case 3:
						pedirEntero(&auxCantidadPc, "Ingrese nueva cantidad de PC: \n", "error, reingrese cantidad de pc",1,500);
						(*(lista+indice)).cantidadPc=auxCantidadPc;
						break;

					case 4:
						pedirEntero(&auxTipoGrado, "Ingrese nuevo tipo de Grado: 1: Aula - 2: Laboratorio - 3: Auditorio - 4: Salon \n", "error, reingrese el tipo de grado", 1,4);
						(*(lista+indice)).tipoGrado= auxTipoGrado;
						break;
					default:
						printf("opcion invalida. \n");
				}
				allOk=1;
			}else{
				printf("la modificacion se ha cancelado. \n");
			}
		}
	}
	return allOk;
}


// /////////// BAJA GRADO ///////////////////

int bajaGrado(eGrado* lista, int tam)
{
	int allOk;
	int id;
	int indice;
	char confirma;

	if(lista!=NULL && tam>0)
	{
		system("cls");

		printf("Ingrese ID: \n");
		scanf("%d", &id);

		indice=buscarGradoId(lista, tam, id);

		if(indice==-1)
		{
			printf("No hay grados ingresados con ID %d\n", id);
		}else
		{
			mostrarGrado(*(lista+indice));
			printf("confirma Baja?: s/n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if(confirma=='s')
		{
			(*(lista+indice)).isEmpty=1;
			allOk=1;
		}else
		{
			printf("La baja ha sido cancelada.");
		}

	}
	return allOk;
}

// //////////// LISTAR GRADOS ////////////

// LISTAR GRADOS: Hacer un único listado de todos los grados ordenados por curso y ante igualdad de curso por capacidad.

int ordenarGradoPorCurso(eGrado* lista, int tam, int orden)
{
	eGrado auxGrado;
	int allOk=0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(orden==1)
				{
					if((strcmp((*(lista+i)).curso , (*(lista+j)).curso )>0) || (strcmp((*(lista+i)).curso, (*(lista+j)).curso)==0 && (*(lista+i)).capacidad >(*(lista+j)).capacidad))
					{
						auxGrado=(*(lista+i));
						(*(lista+i))=(*(lista+j));
						(*(lista+j))=auxGrado;
					}
				}else
				{
					if(orden==0)
					{
						if((strcmp((*(lista+i)).curso, (*(lista+j)).curso)<0) || (strcmp((*(lista+i)).curso, (*(lista+j)).curso)==0 && (*(lista+i)).capacidad<(*(lista+j)).capacidad))
						{
							auxGrado=(*(lista+i));
							(*(lista+i))=(*(lista+j));
							(*(lista+j))=auxGrado;
						}
					}
				}
			}
		}mostrarGrados(lista,tam);

		allOk=1;
	}
	return allOk;
}
int listarGradosPorCurso(eGrado* lista,int tam)
{
	int allOk=0;
	int order;

	if(lista != NULL && tam>0 )
	{
		system("cls");
		printf("--------------------------------------------\n");
		printf("     ****Listar datos de Catastro.****      \n");
		printf("--------------------------------------------\n");

		printf("Elija una opcion: \n");
		printf("1- orden ascendente. \n");
		printf("0- orden descendente. \n");

		scanf("%d", &order);

		switch(order)
		{
			case 1:
				ordenarGradoPorCurso(lista, tam,order);
				break;
		}allOk=1;
	}
	return allOk;
}



int submenuListado()
{
	int opcion;

	printf("Elija una opcion: \n");
	printf("1- orden ascendente. \n");
	printf("0- orden descendente. \n");

	scanf("%d", &opcion);

	return opcion;
}

int submenuTipoGrado()
{
	int opcion;

	printf("Elija una opcion:  \n");
	printf("1- Aula.           \n");
	printf("2- Laboratorio.    \n");
	printf("3- Auditorio.      \n");
	printf("4- Salon.          \n");

	scanf("%d", &opcion);

	return opcion;
}

int submenuTipoDocente()
{
	int opcion;

	printf("Elija una Docente:  \n");
	printf("1- Ana/100.       \n");
	printf("2- Juan/101.      \n");
	printf("3- Sol/102.       \n");
	printf("4- Sebastian/103. \n");
	printf("5- Graciela/104.  \n");


	scanf("%d", &opcion);

	return opcion;
}

int informarLista(eGrado* lista, eDocente* listaD, int tam, int tamD)
{
	int allOk;
	int opcion;



	if(lista != NULL && tam>0 )
	{
		system("cls");
		printf("-------------------------\n");
		printf("     ****INFORMES****     \n");
		printf("-------------------------\n");
		printf(">>  1. Elegir un tipo de grado y mostrar todos los datos del grado con el nombre del docente del tipo seleccionado: \n");
		printf(">>  2. Mostrar un listado de los grados con sus docentes ordenados por capacidad de menor a mayor. \n");
		printf(">>  3. Cantidad de grados del docente 101.\n");
		printf(">>  4. Elegir un docente y mostrar todos los grados donde da clases.\n");
		printf(">>  5. Cantidad de grados de tipo “AUDITORIO”. \n");
		printf(">>  6. Cantidad de Pc’s en total de todos los grados de tipo “AULA”.\n");

		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				elegirTipoGrado(lista, listaD, tam , tamD);
				break;
			case 2:
				listadoDeGradosYdocentes(lista, tam , listaD, tamD);
				break;
			case 3:
				cantDeGrados(lista,listaD, tam, tamD);
				break;
			case 4:
				elegirTipoDocente(lista,listaD,tam , tamD);
				break;
			case 5:
				cantDeGradosTipoAudit(lista, tam);
				break;
			case 6:
				cantDePcAula(lista,tam);
				break;
		}allOk=1;
	}
	return allOk;
}

// 1-Elegir un tipo de grado y mostrar todos los datos del grado con el nombre del docente del tipo seleccionado.

int elegirTipoGrado(eGrado* lista, eDocente* listaD,int tam , int tamD)
{
	int allOk=0;

	switch(submenuTipoGrado())
	{
		case 1:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).tipoGrado == 1 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

					mostrarGrado(lista[i]);

					printf("nombre del Docente del tipo seleccionado: %s \n",
					(*(listaD+i)).nombre);

					}
				}
			}
		break;
		case 2:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).tipoGrado == 1 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado(lista[i]);

					printf("nombre del Docente del tipo seleccionado: %s \n",
							(*(listaD+i)).nombre);

					}
				}
			}
			break;
		case 3:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).tipoGrado == 1 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado(lista[i]);

					printf("nombre del Docente del tipo seleccionado: %s \n",
							(*(listaD+i)).nombre);

					}
				}
			}
			break;
		case 4:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).tipoGrado == 1 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado(lista[i]);

					printf("nombre del Docente del tipo seleccionado: %s \n",
							(*(listaD+i)).nombre);

					}
				}
			}
			break;
	}allOk=1;

	return allOk;

}

// Mostrar un listado de los grados ordenado por docentes y ante igualdad de docen por capacidad de menor a mayor


int listadoDeGradosYdocentes(eGrado* lista, int tam , eDocente* listaD, int tamD)
{
	int allOk=0;
	eDocente auxDocente;

	if(lista!=NULL && tam>0 && listaD !=NULL  && tamD>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tamD; j++)
			{
				if((strcmp((*(listaD+i)).nombre , (*(listaD+j)).nombre )>0) || (strcmp((*(listaD+i)).nombre, (*(listaD+j)).nombre)==0 && (*(lista+i)).capacidad >(*(lista+j)).capacidad))
				{
					auxDocente=(*(listaD+i));
					(*(listaD+i))=(*(listaD+j));
					(*(listaD+j))=auxDocente;
				}
			}
		}
		mostrarGrados(lista,tam);
		allOk=1;
	}
	return allOk;
}

// Cantidad de grados del docente 101.

int cantDeGrados(eGrado* lista,eDocente* listaD,int tam,int tamD)
{
	int allOk=0;

	int contadorDocente=0;

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tamD; j++)
		{
			if((*(lista+i)).curso > 0  && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente == (*(listaD+j)).legajoDocente)
			{
				if((*(lista+i)).legajoDocente == 101)
				{
					contadorDocente++;
				}

			}
		}
	}printf("La cantidad de grados del docente 101 son: %d \n",contadorDocente);

	return allOk;
}

// 4-Elegir un docente y mostrar todos los grados donde da clases.

int elegirTipoDocente(eGrado* lista, eDocente* listaD,int tam , int tamD)
{
	int allOk=0;

	switch(submenuTipoDocente())
	{
		case 1:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).legajoDocente == 100 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado((*(lista+i)));

					}
				}
			}
		break;
		case 2:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).legajoDocente == 101 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado((*(lista+i)));

					}
				}
			}
			break;
		case 3:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).legajoDocente == 102 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado((*(lista+i)));

					}
				}
			}
			break;
		case 4:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).legajoDocente == 103 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado((*(lista+i)));

					}
				}
			}
			break;
		case 5:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamD; j++)
				{
					if((*(lista+i)).legajoDocente == 104 && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoDocente==(*(listaD+j)).legajoDocente)
					{
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA GRADOS***                                                        \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Grado   |     Curso     |     capacidad      |     capacidad PC     |    tipo Grado     |     Legajo Docente            \n");

						mostrarGrado((*(lista+i)));

					}
				}
			}
			break;
	}allOk=1;

	return allOk;

}

//   5. Cantidad de grados de tipo “AUDITORIO”


int cantDeGradosTipoAudit(eGrado* lista,int tam)
{
	int allOk=0;
	int contadorGradosTipoAuditorio=0;

	for(int i=0; i<tam; i++)
	{
			if((*(lista+i)).tipoGrado == 3 && (*(lista+i)).isEmpty==0)
			{
				contadorGradosTipoAuditorio++;

			}

	}printf("la cantidad de grados de tipo “AUDITORIO” son: %d \n",contadorGradosTipoAuditorio);

	return allOk;
}

// 6. Cantidad de Pc’s en total de todos los grados de tipo “AULA”.

int cantDePcAula(eGrado* lista,int tam)
{
	int allOk=0;
	int contadorPCs=0;

	for(int i=0; i<tam; i++)
	{
			if( (*(lista+i)).tipoGrado == 1 && (*(lista+i)).isEmpty==0)
			{
				contadorPCs+=(*(lista+i)).cantidadPc;

			}

	}printf("la cantidad de Pc’s en total de todos los grados de tipo “AULA” son: %d \n",contadorPCs);

	return allOk;
}














