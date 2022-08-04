/*
 ============================================================================
 Name        : recuperatorio2Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "docente.h"
#include "grado.h"
#include "input-UTN.h"

#define TAM 20000

#define TAMD 5

int main(void)
{
	setbuf(stdout, NULL);
	eGrado lista[TAM];
	eDocente listaD[TAMD];
	//eCatastro listaCat[TAMCAT];
	int respuestaMenuPrincipal;
	int opcionElegida;
	int seguir='s';
	int nextId=20000;
	int flag=0;



	if(inicializarGrado(lista , TAM) == -1)
	{
	    printf("Hubo un problema al inicializar la vivienda.");
	}

	inicializarDocentes(listaD);

	do{
		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***Ingrese una de las opciones: *** \n >>1. Alta Grado: \n >>2. Modificar Grado: \n >>3. Baja Grado: \n >>4. Listar Grados:  \n >>5. Listar Docentes: \n >>6. Informes: \n >>7. salir\n", "reingrese la opcion elegida",1,7,3);

		if(respuestaMenuPrincipal==0)
		{
			switch(opcionElegida)
			{
	    		case 1:
	    			if(altaGrados(lista,TAM,&nextId))
	    			{
	    			   mostrarGrados(lista,TAM);
	    			   printf("Alta exitosa!!\n");
	    			   flag=1;
	    			}else
	    			{
	    			   printf("No hay viviendas para registrar\n");
	    			}
		    		break;
	    		case 2:
	    			if(flag==0)
	    			{
	    			   printf("No hay grados para modificar. \n");
	    			}
	    			else
	    			{
	    			    if(modificacionGrado(lista, TAM))
	    			    {
	    			    	printf("Modificacion Exitosa \n");
	    			    }
	    			    else
	    			    {
	    			    	printf("Hubo un problema haciendo la modificacion. \n");
	    			    }
	    			}
	    			break;
	    		case 3:
    				if(flag==0)
    				{
    					printf("No hay grados para dar de Baja \n");
    				}
    				else
    				{
    					if(bajaGrado(lista, TAM))
    					{
    						printf("Baja exitosa. \n");

    					}
    					else
    					{
    						printf("Hubo un problema al hacer la Baja. \n");
    					}
    				}
	    			break;
	    		case 4:
    				if(flag==0)
					{
    					printf("No hay grados para informar. \n");
					}else
					{
						if(listarGradosPorCurso(lista,TAM))
						{

							printf("Lista informada. \n");
						}else
						{
							printf("Hubo un problema al informar. \n");
						}
					}
	    			break;
	    		case 5:
	    			    if(mostrarDocentes(listaD, TAMD))
	    			    {
	    			    	printf("\n Docentes mostrados exitosamente \n");
	    			    }
	    			    else
	    			    {
	    			    	printf("Hubo un problema al mostrar Docentes. \n");
	    			    }
	    			break;
	    		case 6:
    			   if( informarLista(lista, listaD, TAM, TAMD))
    			    {
    			    	printf("la informacion fue mostrado exitosamente \n");
    			    }
    			    else
    			    {
    			    	printf("Hubo un problema al mostrar la informacion. \n");
    			    }
    			flag=1;
	    			break;
	    		case 7:
	    			seguir='n';
	    		break;
	    			default:
	    			printf("opcion invalida\n\n");
	    		}
			}
	    }
	    while(seguir == 's');
		return EXIT_SUCCESS;
}

