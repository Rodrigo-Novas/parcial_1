#include "menu.h"

/**
 * \brief Solicita que el usuario ingrese una opcion del menu
 * \return Opcion que eligio el usuario
 *
 */
int menu()
{
    int option;
    fflush(stdin);
    printf(" *****Menu*****\n"
           " 1. Alta Cliente\n"
           " 2. Modificar Cliente\n"
           " 3. Baja Cliente\n"
           " 4. Crear Pedido de recoleccion\n"
           " 5. Procesar Residuos\n"
           " 6. Imprimir Clientes (+ Cant de pedidos pendientes)\n"
           " 7. Imprimir pedidos pendiente (Cuit del cliente, direccion del cliente, cantidad de kilos a recolectar)\n"
           " 8. Imprimir pedidos procesados (Por tipo)\n"
           " 9. Imprimir cantidad de pedidos pendientes para dicha localidad\n"
           " 10. Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)\n"
           " 11. Clientes con maximo pendientes\n"
           " 12. Imprimir clientes y pedidos por separado\n"
           " 13. Salir\n"
           " Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    while(option <= 0 || option > 13)
    {
        printf(" Por favor, ingrese una opcion del 1 al 11\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf(" *****Menu*****\n"
           " 1. Alta Cliente\n"
           " 2. Modificar Cliente\n"
           " 3. Baja Cliente\n"
           " 4. Crear Pedido de recoleccion\n"
           " 5. Procesar Residuos\n"
           " 6. Imprimir Clientes (+ Cant de pedidos pendientes)\n"
           " 7. Imprimir pedidos pendiente (Cuit del cliente, direccion del cliente, cantidad de kilos a recolectar)\n"
           " 8. Imprimir pedidos procesados (Por tipo)\n"
           " 9. Imprimir cantidad de pedidos pendientes para dicha localidad\n"
           " 10. Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)\n"
           " 11. Clientes con maximo pendientes\n"
           " 12. Imprimir clientes y pedidos por separado\n"
           " 13. Salir\n"
           " Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &option);
    }
    return option;
}
