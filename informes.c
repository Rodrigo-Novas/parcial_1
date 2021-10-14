#include "informes.h"

/** \brief imprime clientes y cantidad de pedidos pendientes
 *
 * \param ePedido* listPedido
 * \param eCliente* listClientes
 * \return void
 *
 */
void printClientesPedidosPendientes(ePedido* listPedidos, eCliente* listClientes){

    int cantidadPendientes = cantRecoleccionPendiente(listPedidos);
    printClientes(listClientes);
    printf("La cantidad de pedidos con estado pendiente es de: %d\n", cantidadPendientes);

}

/** \brief imprime pedidos pendientes
 *
 * \param ePedido* listPedido
 * \param eCliente* listClientes
 * \return Retorna (0) en caso de estar correctamente o (-1) en caso de error
 *
 */
int printPedidosPendientes(ePedido* listPedidos, eCliente* listClientes){

    int retorno=-1;
    if (listPedidos!=NULL && listClientes!=NULL)
    {

        for ( int i=0; i<MAXPEDIDOS; i++)
        {
            for ( int j=0; j<MAXCLIENT; j++){
                if(listPedidos[i].isEmpty == FULL && listClientes[j].isEmpty == FULL)
                {
                    if(listClientes[j].id == listPedidos[i].idCliente){
                        if(listPedidos[i].pedido == PENDIENTE){
                            printf("Cuit: %s\t Direccion: %s\t Kilos: %.2f \n", listClientes[j].cuit, listClientes[j].direccion, listPedidos[i].kilo);
                            retorno = 0;
                        }

                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief imprime pedidos pendientes
 *
 * \param ePedido* listPedido
 * \param eCliente* listClientes
 * \return Retorna (0) en caso de estar correctamente o (-1) en caso de error
 *
 */
int printPedidosProcesadosPorTipo(ePedido* listPedidos, eCliente* listClientes){

    int retorno=-1;
    if (listPedidos!=NULL && listClientes!=NULL)
    {

        for ( int i=0; i<MAXPEDIDOS; i++)
        {
            for ( int j=0; j<MAXCLIENT; j++){
                if(listPedidos[i].isEmpty == FULL && listClientes[j].isEmpty == FULL)
                {
                    if(listClientes[j].id == listPedidos[i].idCliente){
                        if(listPedidos[i].pedido == COMPLETADO){
                            printf("Cuit: %s\t Direccion: %20s\t Kilo HDPE: %.2f \n Kilo LDPE: %.2f \n Kilo PP: %.2f \n", listClientes[j].cuit, listClientes[j].direccion, listPedidos[i].HDPE, listPedidos[i].LDPE, listPedidos[i].PP);
                            retorno = 0;
                        }

                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief imprime pedidos pendientes
 *
 * \param ePedido* listPedido
 * \param eCliente* listClientes
 * \return Retorna contador en caso de estar correctamente o (-1) en caso de error
 *
 */
int printPedidosPendientesPorLocalidad(ePedido* listPedidos, eCliente* listClientes, char* localidad){

    int retorno=-1;
    int contador=0;
    if (listPedidos!=NULL && listClientes!=NULL)
    {

        for ( int i=0; i<MAXPEDIDOS; i++)
        {
            for ( int j=0; j<MAXCLIENT; j++){
                if(listPedidos[i].isEmpty == FULL && listClientes[j].isEmpty == FULL)
                {
                    if(listClientes[j].id == listPedidos[i].idCliente){
                        if(listPedidos[i].pedido == PENDIENTE){
                            if(strcmp(localidad, listClientes[j].localidad) == 0){
                                printPedido(listPedidos, i);
                                contador++;
                                retorno = contador;
                            }
                        }

                    }
                }
            }
        }
    }
    return retorno;
}
/** \brief imprime promedio por cliente
 *
 * \param ePedido* listPedido
 * \param eCliente* listClientes
 * \return Retorna (0) en caso de estar correctamente o (-1) en caso de error
 *
 */

int printClientesPromedioPP(ePedido* listPedidos, eCliente* listClientes){

    int retorno=-1;
    int flagUnaVez = 1;
    ePedido auxPedido[MAXPEDIDOS];
    char nombreCliente[MAXLEN];
    int contadorPP=0;
    float sumaKilos = 0;
    float promedio=0;

    if (listPedidos!=NULL && listClientes!=NULL){
        for(int j=0; j<MAXCLIENT; j++){
            if(listClientes[j].isEmpty == FULL){
            for(int n=0; n<MAXPEDIDOS; n++){
                if(listPedidos[n].idCliente==listClientes[j].id){
                    if(listPedidos[n].pedido == COMPLETADO && (int)listPedidos[n].PP > 0){
                            flagUnaVez =0;
                            sumaKilos = listPedidos[n].PP + sumaKilos;
                            contadorPP++;
                            retorno = 0;
                        }
               }
            }

                if(flagUnaVez==0){
                    promedio = sumaKilos / contadorPP;
                    printf("Para el cliente %s con la cantidad de %d pedidos,  se obtuvieron la cantidad de kilos de %f y el promedio fue %f\n", listClientes[j].nombre, contadorPP, sumaKilos, promedio);
                    sumaKilos =0;
                    contadorPP=0;
                    flagUnaVez=1;

                }

        }

    }
}
    return retorno;
}

/** \brief ordena por idCliente
 *
 * \param ePedido* arrayAux
 * \return void
 *
 */

void orderClientByName(ePedido* arrayAux){

    for (int j = 0; j < MAXPEDIDOS - 1; j++) {
        for (int i = j + 1; i < MAXPEDIDOS; i++) {
            if (arrayAux[j].idCliente>= arrayAux[i].idCliente) {
                int temp;
                temp = arrayAux[j].idCliente;
                arrayAux[j].idCliente = arrayAux[i].idCliente;
                arrayAux[i].idCliente = temp;
            }
        }
    }
}
/** \brief obtiene la cantidad de pedidos pendientes
 *
 * \param ePedido* listPedido
 * \return cantidad de pedidos
 *
 */
int cantRecoleccionPendiente(ePedido* listPedidos){

    int contador=0;
    if (listPedidos!=NULL)
    {
        for ( int i=1; i<=MAXPEDIDOS; i++)
        {
            if(listPedidos[i].isEmpty == FULL)
            {
                if(listPedidos[i].pedido == PENDIENTE){
                contador ++;
                }
            }
        }
    }
    return contador;
}





