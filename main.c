#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"
#include "informes.h"
int main()
{
    int option;

    int flagClientes=0;
    int idCliente;
    int auxAddCliente;
    int auxPrintCliente;
    int auxPrintClientes;
    char localidad[MAXLEN];
    char auxRemoveOption;
    char auxRemove;
    char auxModifyOption;
    char auxModify;
    char clienteCuit[MAXLEN];
    char clienteDireccion[MAXLEN];
    char clienteLocalidad[MAXLEN];
    char clienteNombre[MAXLEN];

    int auxPrintPedidos;
    int auxPrintPedido;
    int auxPedidoPendiente;
    int auxPedidoProcesadoPorTipo;
    int auxPedidoProcesadosPorLocalidad;
    int auxClienteKiloPromedio;
    int auxPedido;
    int idPedido;
    int flagPedidos = 0;
    int idClientePedidos;
    float kilo;
    int auxPrintMasPendientes;
    int auxPrintMasCompletos;
//    //Mock hardcodeado
    eCliente listClientes[MAXCLIENT]= {{0,FULL,"DADAPHONE","30111221413","SAENZ 1234", "CABA"},
                                            {1,FULL,"FABRIC","30445566776","FALCAO 289","CABA"},
                                            {2,FULL,"MIRAMAR","30882342342","LIBERIA 3232","LANUS"},
                                            {3,FULL,"KICKOFF","305345345345","rocha 784","LANUS"},
                                            {4,FULL,"GUTENBIER","31534534535","Mitre 750","AVELLANEDA"},
                                            {5,FULL,"PALMAS","303534534534","rocha 741","QUILMES"}
                                            };
    ePedido listPedidos[MAXPEDIDOS]= {{0,1,FULL,1000,200,145,230,COMPLETADO},
                                        {1,1,FULL,800,210,45,30,COMPLETADO},
                                        {2,2,FULL,100,0,0,0,PENDIENTE},
                                        {3,2,FULL,300,0,0,0,PENDIENTE},
                                        {4,3,FULL,1500,500,150,270,COMPLETADO},
                                        {5,3,FULL,750,100,50,70,COMPLETADO},
                                        {6,1,FULL,200,0,0,0,PENDIENTE},
                                        {7,3,FULL,30,10,5,3,COMPLETADO},
                                        {8,5,FULL,456,0,0,0,PENDIENTE}};

    int initCl = 0;
    int initPe = 0;

//--------------------------------------------------------

    //Inicializacion sin Mock

//    eCliente listClientes[MAXCLIENT];
//    ePedido listPedidos[MAXPEDIDOS];
//    int initCl = initCliente(listClientes);
//    int initPe = initPedido(listPedidos);



    if(initCl == 0 && initPe == 0){

        do{
            option = menu();

        switch(option){
            case 1:
                    flagClientes++;
                    getString("Ingrese un cuit:\n", clienteCuit);
                    getString("Ingrese una direccion:\n", clienteDireccion);
                    getString("Ingrese una localidad:\n", clienteLocalidad);
                    getString("Ingrese un nombre:\n", clienteNombre);
                    fflush(stdin);
                    auxAddCliente = addCliente(listClientes, clienteNombre, clienteCuit, clienteDireccion, clienteLocalidad);
                    if(auxAddCliente != -1){
                        printf("\n Cliente ingresado con exito!!!!! \n");
                        printClientes(listClientes);
                    }
                    else{
                        printf("Error no pudo ingresarse\n");
                    }
                    system("pause");
                    system("cls");
                    break;
            case 2:
                printClientes(listClientes);
                idCliente = getInt("Ingrese id del cliente a modificar:\n");
                auxPrintCliente = printCliente(listClientes, idCliente);
                if(auxPrintCliente == -1){
                    printf("No se encuentran clientes!\n");
                }
                else{
                    do{
                        auxModifyOption = getChar("Esta seguro? Ingrese S/N (EN MAYUSCULA) si desea modificarlo\n");
                        if(auxModifyOption == 'N'){
                            break;
                        }
                    }while(auxModifyOption != 'S');
                    if(auxModifyOption == 'S'){
                        getString("Ingrese una direccion a cambiar:\n", clienteDireccion);
                        getString("Ingrese una localidad a cambiar:\n", clienteLocalidad);
                        auxModify = modifyEmployee(listClientes, idCliente, clienteLocalidad, clienteDireccion);
                        if (auxRemove == -1){
                            printf("Error. El cliente no pudo ser modificado\n");
                        }
                        else{
                            printf("El Cliente %d fue modificado con exito\n", idCliente);
                        }
                    }
                    else{
                        printf("El cliente %d no va a ser modificado \n", idCliente);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 3:
                printClientes(listClientes);
                idCliente = getInt("Ingrese id del cliente a eliminar:\n");
                auxPrintCliente = printCliente(listClientes, idCliente);
                if(auxPrintCliente == -1){
                    printf("No se encuentran clientes!\n");
                }
                else{
                    do{
                        auxRemoveOption = getChar("Esta seguro? Ingrese S/N (EN MAYUSCULA) si desea eliminarlo\n");
                        if(auxRemoveOption == 'N'){
                            break;
                        }
                    }while(auxRemoveOption != 'S');
                    if(auxRemoveOption == 'S'){
                        auxRemove = removeCliente(listClientes, idCliente);
                        if (auxRemove == -1){
                            printf("Error. El cliente no pudo ser removido\n");
                        }
                        else{
                            printf("El Cliente %d fue eliminado con exito\n", idCliente);
                        }
                    }
                    else{
                        printf("El cliente %d no va a ser eliminado \n", idCliente);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 4:
                flagPedidos++;
                auxPrintClientes = printClientes(listClientes);
                if(auxPrintClientes == -1){
                    printf("No se encuentran clientes, ingrese primero un cliente y luego ingrese el pedido!\n");
                }
                else{
                    idClientePedidos = getInt("Ingrese un id de Cliente\n");
                    if(findClientebyId(listClientes, idClientePedidos) == -1){
                        printf("\nNo se encuentra ese id de cliente!\n");
                    }
                    else{
                        kilo = getFloat("\nCantidad de kilos de cliente:\n ");
                        auxPedido = addPedido(listPedidos, idClientePedidos, kilo);
                        if(auxPedido != -1){
                            printf("\nPedido agregado con exito!!!\n");
                            printPedido(listPedidos, auxPedido);
                        }else{
                            printf("\nError. No pudo agregarse el pedido\n");
                        }
                    }
                }
                system("pause");
                system("cls");
                break;
            case 5:
                auxPrintPedidos=printPedidos(listPedidos);
                if(auxPrintPedidos == -1){
                    printf("\nNo se encuentran pedidos, de alta un pedido primero!\n");
                }
                else{
                    idPedido = getInt("\nIngrese un Id de pedido\n");
                    auxPedido = setPedidos(listPedidos, idPedido);
                    if (auxPedido != -1){
                        printf("\nIngreso del pedido correcto\n");
                        printPedidos(listPedidos);
                    }else{
                        printf("\nError. No pudo ingresarse el pedido\n");
                    }
                }
                system("pause");
                system("cls");
                break;
            case 6:
                printClientesPedidosPendientes(listPedidos, listClientes);
                system("pause");
                system("cls");
                break;
            case 7:
                printf("Lista de pedidos pendientes (con Kilo)\n");
                auxPedidoPendiente = printPedidosPendientes(listPedidos, listClientes);
                if (auxPedidoPendiente == -1){
                    printf("No se encuentran pedidos\n");
                }
                system("pause");
                system("cls");
                break;
            case 8:
                printf("Lista de pedidos completos (separado por TIPO)\n");
                auxPedidoProcesadoPorTipo = printPedidosProcesadosPorTipo(listPedidos, listClientes);
                if (auxPedidoProcesadoPorTipo == -1){
                    printf("No se encuentran pedidos\n");
                }
                system("pause");
                system("cls");
                break;
            case 9:
                printf("Lista de pedidos pendientes (separado por LOCALIDAD)\n");
                getString("Ingrese una localidad: \n", localidad);
                auxPedidoProcesadosPorLocalidad = printPedidosPendientesPorLocalidad(listPedidos, listClientes, localidad);
                if (auxPedidoProcesadosPorLocalidad  == -1){
                    printf("No se encuentran pedidos\n");
                }
                else{
                    printf("\n La cantidad de pedidos pendientes en la localidad %s es: %d\n",localidad , auxPedidoProcesadosPorLocalidad);
                }
                break;
            case 10:
                printf("\nPromedio de kilos PP por cliente: \n\n");
                auxClienteKiloPromedio = printClientesPromedioPP(listPedidos, listClientes);
                if (auxClienteKiloPromedio  == -1){
                    printf("\n Error. No se encuentran clientes con PP\n");
                }
                system("pause");
                system("cls");
                break;
            case 11:
                printf("\n-----Max pedidos pendientes-------\n");
                auxPrintMasPendientes = masPedidosPendientes(listClientes, listPedidos);
                if(auxPrintMasPendientes == -1){
                    printf("No se encuentran clientes!\n");
                }
                system("pause");
                system("cls");
                break;
            case 12:
                printf("\n-----Max pedidos completados-------\n");
                auxPrintMasCompletos = masPedidosCompletados(listClientes, listPedidos);
                if(auxPrintMasCompletos  == -1){
                    printf("No se encuentran clientes!\n");
                }
                system("pause");
                system("cls");
                break;
            case 13:
                printf("\n-----Clientes-------\n");
                auxPrintClientes = printClientes(listClientes);
                if(auxPrintClientes == -1){
                    printf("No se encuentran clientes!\n");
                }
                printf("\n-----Pedidos-------\n");
                auxPrintPedidos = printPedidos(listPedidos);
                if(auxPrintPedidos == -1){
                    printf("\nNo se encuentran Pedidos!\n");
                }
                system("pause");
                system("cls");
                break;
            case 14:
                printf (" Gracias por utilizar el sistema! \n");
                break;

            default:
                printf (" Error. Ingrese nuevamente el comando del 1 al 11.\n");
                system("pause");
                break;
                }
        }while(option!=14);
        return option;
    }
}
