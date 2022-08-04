/*
 * linkedList.c
 *
 *  Created on: 2 ago 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode; //pNodo es la direccion del nodo 0
        for(int i = nodeIndex; i > 0; i--)
        {
            pNodo = pNodo->pNextNode;
        }
    }
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* anterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement;

            nuevoNodo->pNextNode = getNode(this,nodeIndex);
            if(nodeIndex == 0)
            {
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                anterior = getNode(this, nodeIndex - 1);
                anterior->pNextNode = nuevoNodo;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	 return addNode(this,ll_len(this), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo = NULL;

    if(this != NULL && index > 0 && index < (ll_len(this)))
    {
        pNodo = getNode(this, index);
        if(pNodo != NULL)
        {
            returnAux = pNodo->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;

    if(this != NULL && index > 0 && index < ll_len(this))
    {
        pNodo = getNode(this,index);
        if(pNodo != NULL)
        {
            pNodo->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNodeUno=NULL;
    Node* auxNodeDos=NULL;
    if(this != NULL && index >=0 && index < ll_len(this) )
    {
    	auxNodeUno = getNode(this, index);
    	if (auxNodeUno != NULL)
    	{
    		if( index == 0 )
    		{
    			this -> pFirstNode = auxNodeUno->pNextNode;
    			free(auxNodeUno);
    			this -> size --;
    			returnAux=0;
    		}
    		else
    		{
    			auxNodeDos = getNode (this , index - 1);
    			if(auxNodeDos != NULL)
    			{
    				auxNodeDos -> pNextNode = auxNodeUno->pNextNode;
    				free(auxNodeUno);
    				this -> size --;
    				returnAux=0; //repito porque funciona solo si entra aca.
    			}
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        while(ll_len(this))
        {
           returnAux = ll_remove(this, 0);
           if(returnAux)
           {
               break;
           }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i = 0; i < ll_len(this); i++) //no es <= por que tengo 5 elemnt lo que pasa que el indice de cada elemtn arranca en 0 entonces el ultimo es el 4 y si le pongo <= como el len es 5 el ult no existe
        { //si el tama�o es ll_len(this) entonces tiene ll_len(this)-1 indices
            if(ll_get(this, i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux; //me indica segun un element donde esta el elemento , en que indice en que nodo, me indica cual es la posicion
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
       if(ll_len(this))
       {
    	   returnAux = 0;
       }
       else
       {
    	   returnAux = 1;
       }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	return addNode(this, index, pElement);
}


/** \brief elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > 0 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux; //me retorna si existe o no existe el element, el nodo
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;

        for(int i = 0; i < ll_len(this2); i++)
        {
            if(!ll_contains(this, ll_get(this2, i)))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;


    if(this != NULL && from < to && from >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i = from; i < to; i++) //recorro los nodos indicados, el i arranca en el from y que llegue al to por eso es menor al to
            {
            	ll_get(this,i);
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray=NULL;

	if(this!=NULL)
	{
		cloneArray=ll_subList(this, 0, ll_len(this));
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* elementoA = NULL;
    void* elementoB = NULL;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
       {
           int len = ll_len(this);
           for(int i = 0; i < len-1; i++)
           {
               for(int j = i + 1; j < len; j++)
               {
                   elementoA = ll_get(this,i);
                   elementoB = ll_get(this, j);
                   if((order == 1 && pFunc(elementoA, elementoB) == 1) || (order == 0 && pFunc(elementoA, elementoB) == -1))
                   {
                       ll_set(this, i, elementoB);
                       ll_set(this, j, elementoA);
                   }
               }
           }
           returnAux = 0;
       }
    return returnAux;
}

/**
 * @fn LinkedList ll_map*(LinkedList*, void(*)(void*))
 * @brief Completa un campo del elemento, recibiendo como par�metro, la funci�n que sera la encargada de calcular el valor de ese campo.
 *
 * @param this Verificando que tanto el puntero this como el puntero a la funcion
 * @param fn sean distintos de NULL. Retorna la lista completa.
 * @return
 */

void ll_map(LinkedList* this, void* (*fn)(void* element))
{

	if(this != NULL && fn != NULL)
	{
		for(int i=0; i<ll_len(this);i++)
		{
			fn(ll_get(this,i));
		}
	}
}


/*
 * Filtra la lista con una condici�n, recibiendo como par�metro
 * la funci�n que sera la encargada de decidir si cada elemento
 * cumple la condici�n (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista nueva lista filtrada.
 * */

LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{
    LinkedList* filter = NULL;

    if(this != NULL && fn != NULL)
    {
    	filter = ll_newLinkedList();
        if(filter != NULL)
        {
        	for(int i = 0; i < ll_len(this); i++)
            {
                if(fn(ll_get(this, i)))
                {
                    ll_add(filter, ll_get(this, i));
                }
            }
        }
    }
    return filter;
}
