#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "fechas.h"



int obtenerFecha(eFecha *ptrFecha)
{
    int exito = 1;
    eFecha auxFecha;
    getInt(&auxFecha.dia, "\nIngrese dia en el que se llevo a cabo el servicio (1-31): ", "\nError, ingrese un dia valido.", 1, 31);
    getInt(&auxFecha.mes, "\nIngrese mes en el que se llevo a cabo el servicio (1-12): ", "\nError, ingrese un mes valido.", 1, 12);
    printf("\nIngrese anio en el que se llevo a cabo el servicio: ");
    scanf("%d", &auxFecha.anio);
    if((auxFecha.mes == 4 || auxFecha.mes == 6 || auxFecha.mes == 9 || auxFecha.mes == 11) && auxFecha.dia > 30)
    {
        printf("\nError, el mes ingresado solo tiene 30 dias.\n");
        exito = 0;
    }
    else if(auxFecha.anio % 4 == 0 && (auxFecha.anio % 100 != 0 || auxFecha.anio % 400 == 0) && auxFecha.mes == 2 && auxFecha.dia > 29)
    {
        printf("\nError, el mes seleccionado solo tiene 29 dias.\n");
        exito = 0;
    }
    else if(auxFecha.mes == 2 && auxFecha.dia > 28)
    {
        printf("\nError, el mes seleccionado solo tiene 28 dias.\n");
        exito = 0;
    }
    if(exito)
    {
        *ptrFecha = auxFecha;
    }
    return exito;
}
