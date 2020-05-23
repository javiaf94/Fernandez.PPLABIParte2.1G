#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "autos.h"
#include "colores.h"
#include "marcas.h"
#include "fechas.h"
#include "trabajos.h"
#include "clientes.h"
void obtenerDescripcionServicio(char descripcion[], int id, eServicio serv[], int tamserv)
{
    for(int i =0; i<tamserv; i++)
    {
        if(id == serv[i].id)
        {
            strcpy(descripcion, serv[i].descripcion);
        }
    }

}


void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamserv)
{
    char descripcion[20];
    obtenerDescripcionServicio(descripcion, trab.idServicio, serv, tamserv);
    printf("%4d     %6s          %15s      %02d/%02d/%4d\n", trab.id, trab.patente, descripcion, trab.fecha.dia, trab.fecha.mes, trab.fecha.anio);

}

void mostrarTrabajos(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab)
{
    printf("**** LISTA DE TRABAJOS ****\n\n\n");
    printf("ID      PATENTE                 SERVICIO          FECHA\n\n");
    for(int i=0; i<tamtrab; i++)
    {

        mostrarTrabajo(trab[i], serv, tamserv);

    }
}

int altaTrabajo(int id, eAuto aut[], int tamaut, eColor col[], int tamcol, eMarca marc[], int tammarc, eServicio serv[], int tamserv, int indice, eTrabajo trab[], eCliente cli[], int tamcli)
{
    eTrabajo auxTrab;
    int auxId;
    int encontroAuto;
    int fechaCorrecta;
    int exito = 0;

    auxTrab.id = id;

    do
    {
        system("cls");
        printf("***** MENU ALTA DE TRABAJOS *****\n\n\n");
        mostrarAutos(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
        printf("\n\nIngrese el ID del auto que desea seleccionar: ");
        scanf("%d", &auxId);
        encontroAuto = existeAuto(aut, auxId, tamaut);
        if(encontroAuto > -1)
        {
            strcpy(auxTrab.patente, aut[encontroAuto].patente);
        }
        else
        {
            printf("\nEl ID no corresponde al de ningun auto. Ingrese un ID valido.\n\n");
            system("pause");
        }
    }while(encontroAuto == -1);

    mostrarServicios(serv,tamserv);
    getInt(&auxTrab.idServicio, "\n\nIngrese el ID del servicio que desea seleccionar: " , "Error, ingrese un ID valido.\n" ,20000, 20003);


    do
    {
      fechaCorrecta = obtenerFecha(&auxTrab.fecha);
    }while (!fechaCorrecta);

    printf("\n\nID      PATENTE                 SERVICIO          FECHA\n\n");
    mostrarTrabajo(auxTrab, serv, tamserv);

    if(getYesOrNo("\n\nConfirma dar de alta el trabajo?(s/n)", "\nError si o no."))
    {
        trab[indice] = auxTrab;
        exito = 1;
    }

    return exito;
}

