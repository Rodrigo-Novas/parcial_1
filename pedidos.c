#include "pedidos.h"



/** \brief Genera un id unico
 *
 * \return id unico autoincremental
 */
static int generateNextId(){ //static para que solo sea visible en pedidos.c no necesita estar en el .h (simil private en POO)

    static int id = -1;

    id ++;

    return id;
}


/** \brief Inicializa el array de pedidos en 0
 *
 * \param ePedido* listPedido
 * \return Retorna (0) en caso de inicializar correctamente o (-1) en caso de error
 *
 */
int initPedido(ePedido* listPedido){

    int retorno = -1;
    if(listPedido != NULL){ //Si apunta a null significa que no existe
        for (int i=0; i< MAXPEDIDOS; i++){
            listPedido[i].isEmpty = EMPTY; //1
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief CONSIGUE UN ESPACIO LIBRE
 *
 * \param ePedido* listPedido
 * \return Retorna el indice del espacio libre sino -1
 *
 */
int freeSpacePedido(ePedido* listPedido){
    int retorno = -1;
    if(listPedido != NULL){
        for(int i=0; i<MAXPEDIDOS; i++ ){
            if(listPedido[i].isEmpty == EMPTY){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief añade pedido
 *
 * \param ePedido* listPedido
 * \param int idCliente
 * \param float kilo
 * \return Retorna ID en caso de añadir correctamente o (-1) en caso de error
 *
 */
int addPedido(ePedido* listPedido,int idCliente, float kilo){
    int retorno = -1;
    int pedidoLibre = freeSpacePedido(listPedido);
    if (listPedido != NULL){
        if (listPedido != -1){
            listPedido[pedidoLibre].idCliente = idCliente;
            listPedido[pedidoLibre].kilo = kilo;
            listPedido[pedidoLibre].isEmpty = FULL;
            listPedido[pedidoLibre].id = generateNextId();
            listPedido[pedidoLibre].pedido = PENDIENTE;
            retorno = listPedido[pedidoLibre].id;
        }
    }
    return retorno;
}






/** \brief ingresa los kilos por tipo
 *
 * \param ePedido* listPedido
 * \param int id
 * \return Retorna ID en caso de añadir correctamente o (-1) en caso de error
 *
 */
int setPedidos(ePedido* listPedido, int id)
{
    int retorno=-1;
    int i;

    if(listPedido!=NULL)
    {
    	if(findPedidoById(listPedido, id)==-1)
    	{
    		printf("\nNo existe el ID del pedido\n");
    	}
    	else
    	{
    		if(listPedido[id].pedido==PENDIENTE)
    		 {
    			listPedido[id].HDPE = getFloat("\nCantidad de kilos de HDPE:\n ");
    			listPedido[id].LDPE = getFloat("\nCantidad de kilos de LPDE:\n ");
    			listPedido[id].PP = getFloat("\nCantidad de kilos de PP:\n ");


    			listPedido[id].pedido=COMPLETADO;
    		    printf("\n ID: %d\tCantidad de kilos: %.2f\nCantidad de kilosHDPE: %.2f\nCantidad de kilosLDPE: %.2f\nCantidad de kilosPP: %.2f\nEstado: Completado",
						listPedido[id].id,listPedido[id].kilo,listPedido[id].HDPE,listPedido[id].LDPE,listPedido[id].PP);

                retorno = 0;
    		 }

    		else
    		{
    			printf("El pedido ya fue procesado");
    		}
    	}

    }


    return retorno;
}



/** \brief imprime pedido por ID
 *
 * \param ePedido* listPedido
  * \param int id
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */

int printPedido(ePedido* listPedido, int id)
{
    int retorno=-1;
    char estadoAux[10] = "PENDIENTE";
    if (listPedido!=NULL)
    {
        if(listPedido[id].isEmpty== FULL)
        {
            if(listPedido[id].pedido == COMPLETADO){
                strcpy(estadoAux, "COMPLETOS");
            }
            printf("\n---------------------------- \nID Cliente: %d\nID Pedido: %d\nCant Kilos Totales: %.2f\n Estado: %s\n"
                   , listPedido[id].idCliente,listPedido[id].id,listPedido[id].kilo, estadoAux);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief imprime todos los pedidos
 *
 * \param ePedido* listPedido
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */
int printPedidos(ePedido* listPedido)
{
    int retorno=-1;
    if (listPedido!=NULL)
    {

        for ( int i=0; i<MAXPEDIDOS; i++)
        {
            if(listPedido[i].isEmpty == FULL)
            {
                printPedido(listPedido, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief encuentra pedido por id
 *
 * \param ePedido* listPedido
  * \param int id
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */
int findPedidoById(ePedido* listPedido, int id){

    int retorno = -1;
    printf("%d\n", id);
    if(listPedido!=NULL){
        for(int i=0; i<MAXPEDIDOS; i++){
            if(listPedido[i].id == id && listPedido[i].isEmpty==FULL){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


