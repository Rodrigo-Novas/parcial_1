#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "pedidos.h"
#include "cliente.h"

int printPedidosPendientes(ePedido* listPedidos, eCliente* listClientes);
void printClientesPedidosPendientes(ePedido* listPedidos, eCliente* listClientes);
int cantRecoleccionPendiente(ePedido* listPedidos);
int printPedidosProcesadosPorTipo(ePedido* listPedidos, eCliente* listClientes);
int printPedidosPendientesPorLocalidad(ePedido* listPedidos, eCliente* listClientes, char* localidad);
int printClientesPromedioPP(ePedido* listPedidos, eCliente* listClientes);
void orderClientByName(ePedido* arrayAux);
int masPedidosPendientes(eCliente* listCliente, ePedido* listPedidos);
int masPedidosCompletados(eCliente* listCliente, ePedido* listPedidos);
#endif // INFORMES_H_INCLUDED
