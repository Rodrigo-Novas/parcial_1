#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"

#define MAXLEN 51
#define MAXCLIENT 6

typedef struct{
    char localidadAux[MAXLEN];

} eLocalidad;


typedef struct{
    int id;
    int isEmpty;
    char nombre[MAXLEN];
    char cuit[MAXLEN];
    char direccion[MAXLEN];
    eLocalidad localidad;
} eCliente;



int initCliente(eCliente* listClientes);
int freeSpaceCliente(eCliente* listCliente);
int addCliente(eCliente* listCliente,char* nombre, char* cuit, char* direccion, char* localidad);
int printCliente(eCliente* listClientes, int id);
int printClientes(eCliente* listClientes);
int findClientebyId(eCliente* listCliente, int id);
int removeCliente(eCliente* listCliente, int id);
int modifyEmployee(eCliente* listCliente, int id, char* localidad, char* direccion);
#endif // CLIENTE_H_INCLUDED
