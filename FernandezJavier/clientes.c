#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void mostrarClientes(eCliente cli[], int tamcli)
{
    printf("\n*** CLIENTES ***\n\n");
    printf("ID               NOMBRE       SEXO\n\n");
    for(int i=0; i<tamcli; i++)
    {
        printf("%2d %20s          %c\n", cli[i].id, cli[i].nombre, cli[i].sexo);
    }
}
