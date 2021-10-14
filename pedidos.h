#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include "utn.h"
#define PENDIENTE 1
#define COMPLETADO 0
#define MAXPEDIDOS 9


typedef struct{

    int id;
    int idCliente;
    int isEmpty;
    float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int pedido; // 1 PENDIENTE && 0 COMPLETADO
}ePedido;


int initPedido(ePedido* listaPedido);

int freeSpacePedido(ePedido* listPedido);

int addPedido(ePedido* listPedido,int idCliente, float kilo);

int printPedidos(ePedido* listPedido);

int printPedido(ePedido* listPedido, int id);

int findPedidoById(ePedido* listPedido, int id);

int setPedidos(ePedido* listPedido, int id);



#endif // PEDIDOS_H_INCLUDED
