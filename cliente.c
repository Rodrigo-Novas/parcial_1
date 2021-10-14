#include "cliente.h"



/** \brief Genera un id unico
 *
 * \return id unico autoincremental
 */
static int generateNextId(){ //static para que solo sea visible en clientes.c no necesita estar en el .h (simil private en POO)

    static int id = -1;

    id ++;

    return id;
}


/** \brief Inicializa el array de clientes en 0
 *
 * \param eCliente* listClientes
 * \return Retorna (0) en caso de inicializar correctamente o (-1) en caso de error
 *
 */
int initCliente(eCliente* listClientes){

    int retorno = -1;
    if(listClientes != NULL){ //Si apunta a null significa que no existe
        for (int i=0; i< MAXCLIENT; i++){
            listClientes[i].isEmpty = EMPTY; //1
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief CONSIGUE UN ESPACIO LIBRE
 *
 * \param eCliente* listClientes
 * \return Retorna el indice del espacio libre sino -1
 *
 */
int freeSpaceCliente(eCliente* listCliente){
    int retorno = -1;
    if(listCliente != NULL){
        for(int i=0; i<MAXCLIENT; i++ ){
            if(listCliente[i].isEmpty == EMPTY){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief añade cliente
 *
 * \param eCliente* listClientes
 * \param eCliente* listClientes
 * \param int id
 * \param char localidad
 * \param char direccion
 * \return Retorna id en caso de añadir correctamente o (-1) en caso de error
 *
 */
int addCliente(eCliente* listCliente,char* nombre, char* cuit, char* direccion, char* localidad){
    int retorno = -1;
    int clienteLibre = freeSpaceCliente(listCliente);
    if (listCliente != NULL){
        if (clienteLibre != -1){
            strcpy(listCliente[clienteLibre].cuit, cuit);
            strcpy(listCliente[clienteLibre].nombre, nombre);
            strcpy(listCliente[clienteLibre].direccion, direccion);
            strcpy(listCliente[clienteLibre].localidad, localidad);
            listCliente[clienteLibre].isEmpty = FULL;
            listCliente[clienteLibre].id = generateNextId();
            retorno = listCliente[clienteLibre].id;
        }
    }
    return retorno;
}

/** \brief imprime cliente por ID
 *
 * \param eCliente* listClientes
  * \param int id
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */

int printCliente(eCliente* listClientes, int id)
{
    int retorno=-1;
    if (listClientes!=NULL)
    {
        if(listClientes[id].isEmpty== FULL)
        {
            printf("%5d %20s %20s %20s %20s \n", listClientes[id].id, listClientes[id].cuit, listClientes[id].nombre, listClientes[id].direccion, listClientes[id].localidad);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief imprime todos los clientes
 *
 * \param eCliente* listClientes
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */
int printClientes(eCliente* listClientes)
{
    int retorno=-1;
    if (listClientes!=NULL)
    {
        printf("\n%5s %20s %20s %5s %20s \n", "ID","Cuit","Nombre","Direccion","Localidad");
        for ( int i=0; i<MAXCLIENT; i++)
        {
            if(listClientes[i].isEmpty == FULL)
            {
                printCliente(listClientes, listClientes[i].id);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief encuentra cliente por id
 *
 * \param eCliente* listClientes
  * \param int id
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */
int findClientebyId(eCliente* listCliente, int id){

    int retorno = -1;
    printf("%d\n", id);
    if(listCliente!=NULL){
        for(int i=0; i<MAXCLIENT; i++){
            if(listCliente[i].id == id && listCliente[i].isEmpty==FULL){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief remueve clientes
 *
 * \param eCliente* listClientes
  * \param int id
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */

int removeCliente(eCliente* listCliente, int id){

    int retorno = -1;
    int posicionCliente;
    if(listCliente != NULL){
        posicionCliente = findClientebyId(listCliente, id);
        if (posicionCliente != -1){
            if(listCliente[id].isEmpty == FULL){
                listCliente[id].isEmpty=EMPTY;
                retorno = 0;
            }
        }
    }
    return retorno;
}
/** \brief modifica clientes
 *
 * \param eCliente* listClientes
 * \param int id
 * \param char localidad
 * \param char direccion
 * \return Retorna (0) en caso de añadir correctamente o (-1) en caso de error
 *
 */

int modifyEmployee(eCliente* listCliente, int id, char* localidad, char* direccion){
    int retorno = -1;
    int posicionCliente;
    if(listCliente != NULL){
        posicionCliente = findClientebyId(listCliente, id);
        if (posicionCliente != -1){
            if(listCliente[id].isEmpty == FULL){
                strcpy(listCliente[id].direccion, direccion);
                strcpy(listCliente[id].localidad, localidad);
                retorno = 0;
            }
        }
    }
    return retorno;
}

