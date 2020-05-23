#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "inputs.h"
#include "autos.h"
#include "servicios.h"
#include "marcas.h"
#include "colores.h"
#include "trabajos.h"
#include "fechas.h"

void mostrarAutosMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    int idMarca;
    char descripcionMarca[20];
    int flag = 0;

    system("cls");
    printf("***** INFORME AUTOS DE UNA MARCA ******\n\n");
    mostrarMarcas(marc, tammarc);
    getInt(&idMarca, "\nIngrese el ID de la marca a listar: ", "Error, ingrese un numero valido.\n", 1000, 1004);
    obtenerDescripcionMarca(descripcionMarca, idMarca, marc, tammarc);

    system("cls");
    printf("***** INFORME AUTOS DE UNA MARCA ******\n\n\n");
    printf("*** Autos de la marca %s ***\n\n", descripcionMarca);
    printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE\n\n");
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty == 0 && aut[i].idMarca == idMarca)
        {
            mostrarAuto(aut[i], marc, tammarc, col, tamcol, cli, tamcli);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("No hay autos.\n\n");
    }

}

void mostrarAutosColor(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    int idColor;
    char descripcionColor[20];
    int flag = 0;

    system("cls");
    printf("***** INFORME AUTOS DE UN COLOR ******\n\n");
    mostrarColores(col, tamcol);
    getInt(&idColor, "\nIngrese el ID del color a listar: ", "Error, ingrese un numero valido.\n", 5000, 5004);
    obtenerDescripcionColor(descripcionColor, idColor, col, tamcol);

    system("cls");
    printf("***** INFORME AUTOS DE UN COLOR ******\n\n");
    printf("*** Autos de color %s ***\n\n", descripcionColor);
    printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE\n\n");
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty == 0 && aut[i].idColor == idColor)
        {
            mostrarAuto(aut[i], marc, tammarc, col, tamcol, cli, tamcli);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("No hay autos.\n\n");
    }

}

void mostrarTrabajosDeAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli)
{
    int idAuto;
    int flag = 0;
    char patente[7];
    system("cls");
    printf("***** INFORME HISTORIAL DE TRABAJOS DE UN AUTO ******\n\n");
    mostrarAutos(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
    if(hayAutos(aut, tamaut))
    {
        printf("\n\nIngrese el ID del auto del cual desea listar los trabajos: ");
        scanf("%d", &idAuto);
        int indice = existeAuto(aut, idAuto, tamaut);
        if (indice == -1)
        {
            printf("\n\nEl auto no existe \n");
        }
        else
        {
            obtenerPatente(patente, idAuto, aut, tamaut);
            system("cls");
            printf("***** INFORME HISTORIAL DE TRABAJOS DE UN AUTO ******\n\n");
            printf("**** Trabajos del auto patente %s ****\n\n", patente);
            printf("ID      PATENTE                 SERVICIO          FECHA\n\n");
            for(int i=0; i<tamtrab; i++)
            {
                if(strcmp(trab[i].patente, patente)==0)
                {
                    mostrarTrabajo(trab[i], serv, tamserv);
                    flag=1;
                }
            }
            if(!flag)
            {
                printf("\nNo se encontraron trabajos realizados para ese auto.\n");
            }

        }
    }

}

void mostrarCostoTrabajosAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli)
{
    int idAuto;
    int flag = 0;
    int costoTotal = 0;
    char patente[7];
    system("cls");
    printf("***** INFORME COSTO DE TRABAJOS DE AUTO ******\n\n");
    mostrarAutos(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
    if(hayAutos(aut, tamaut))
    {
        printf("\n\nIngrese el ID del auto del cual desea conocer el costo: ");
        scanf("%d", &idAuto);
        int indice = existeAuto(aut, idAuto, tamaut);
        if (indice == -1)
        {
            printf("\n\nEl auto no existe \n");
        }
        else
        {
            obtenerPatente(patente, idAuto, aut, tamaut);
            system("cls");
            printf("***** INFORME COSTO DE TRABAJOS DE AUTO ******\n\n");
            printf("**** Costo total del auto patente %s ****\n\n", patente);
            for(int i=0; i<tamtrab; i++)
            {
                if(strcmp(trab[i].patente, patente) == 0)
                {
                    for(int j=0; j<tamserv; j++)
                    {
                        if(serv[j].id == trab[i].idServicio)
                        {
                            costoTotal += serv[j].precio;
                            flag=1;
                        }
                    }
                }
            }
            if(flag)
            {
                printf("El costo total de los trabajos realizados es de $%d\n", costoTotal);
            }
            else
            {
                printf("\nNo se encontraron trabajos realizados para este auto.\n");
            }
        }
    }
}


void mostrarAutoMasViejo(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    int autoViejo;
    int flag = 0;
    system("cls");
    printf("***** INFORME AUTO MAS VIEJO *****\n\n");

    for(int i=0; i<tamaut; i++)
    {
        if(!flag && aut[i].isEmpty == 0)
        {
            flag = 1;
            autoViejo = aut[i].modelo;
        }
        else if(aut[i].isEmpty == 0 && aut[i].modelo < autoViejo)
        {
           autoViejo = aut[i].modelo;
        }
    }
    if (flag)
    {
        system("cls");
        printf("***** INFORME AUTO MAS VIEJO *****\n\n");
        printf("Auto/s mas viejo/s:\n\n");
        printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE\n\n");
        for(int i=0; i<tamaut; i++)
        {
            if(aut[i].isEmpty == 0  && aut[i].modelo == autoViejo)
            {
                mostrarAuto(aut[i] , marc, tammarc, col, tamcol, cli, tamcli);
            }
        }
    }
    else
    {
        printf("\n\nNo se encontraron autos.\n\n");
    }

}

void mostrarListaAutosPorMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    char marca[20];
    int flag;
    system("cls");
    printf("***** LISTA DE AUTOS DE CADA MARCA ******\n\n");
    for(int i=0; i<tammarc; i++)
    {
        flag =0;
        strcpy(marca, marc[i].descripcion);
        printf("\nAutos de la marca %s:\n\n", marca);
        printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE\n\n");
        for(int j=0; j<tamaut; j++)
        {
            if(aut[j].idMarca == marc[i].id && aut[j].isEmpty == 0)
            {
                mostrarAuto(aut[j], marc, tammarc, col, tamcol, cli, tamcli);
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("No hay autos.\n");
        }
        printf("\n---------------------------------------------------------------------------------------\n");
    }
}

void mostrarAutosColorYMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    int idColor;
    char descripcionColor[20];
    int flag = 0;

    int idMarca;
    char descripcionMarca[20];

    system("cls");
    printf("***** INFORME AUTOS DE UNA MARCA Y COLOR ******\n\n");
    mostrarColores(col, tamcol);
    getInt(&idColor, "\nIngrese el ID del color a listar: ", "Error, ingrese un numero valido.\n", 5000, 5004);
    obtenerDescripcionColor(descripcionColor, idColor, col, tamcol);

    mostrarMarcas(marc, tammarc);
    getInt(&idMarca, "\nIngrese el ID de la marca a listar: ", "Error, ingrese un numero valido.\n", 1000, 1004);
    obtenerDescripcionMarca(descripcionMarca, idMarca, marc, tammarc);

    system("cls");
    printf("***** INFORME AUTOS DE UNA MARCA Y COLOR ******\n\n");
    printf("*** Autos de la marca %s y color %s ***\n\n", descripcionMarca, descripcionColor);
    printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE\n\n");
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty == 0 && aut[i].idMarca == idMarca && aut[i].idColor == idColor)
        {
            mostrarAuto(aut[i], marc, tammarc, col, tamcol, cli, tamcli);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("No hay autos.\n\n");
    }
}

void mostrarMarcaMasElegida(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli)
{
    system("cls");
    printf("***** INFORME MARCA MAS ELEGIDA ******\n\n");
    int contador[5] = {0,0,0,0,0};
    int id[5] = {1000,1001,1002,1003,1004};
    int marcaPopular = 0;
    char descripcionMarca[20];
    int flag = 0;
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty == 0 && aut[i].idMarca == 1000)
        {
            contador[0]++;
        }
        else if(aut[i].isEmpty == 0 && aut[i].idMarca == 1001)
        {
            contador[1]++;
        }
        else if(aut[i].isEmpty == 0 && aut[i].idMarca == 1002)
        {
            contador[2]++;;
        }
        else if(aut[i].isEmpty == 0 && aut[i].idMarca == 1003)
        {
            contador[3]++;
        }
        else if(aut[i].isEmpty == 0 && aut[i].idMarca == 1004)
        {
            contador[4]++;
        }
    }

    for(int i=0; i<5; i++)
    {
        if(!flag)
        {
            flag = 1;
            marcaPopular = contador[i];
        }
        else
        {
            if(contador[i]>marcaPopular)
            {
                marcaPopular = contador[i];
            }
        }
    }

    printf("\n*** Marcas Mas elegidas ***\n");

    if(marcaPopular==0)
    {
        printf("\nNo se encontraron autos.\n");
    }
    else
    {
        for(int i=0; i<5; i++)
        {
            obtenerDescripcionMarca(descripcionMarca, id[i], marc, tammarc);

            if(contador[i] == marcaPopular)
            {
               printf("\n%s (elegida %d veces).\n", descripcionMarca, marcaPopular);
            }
        }
    }

    printf("\n");
}

void mostrarAutosRealizoServicio(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab)
{

    int idServicio;
    char descripcionServ[20];
    int indice;
    int flag=0;
    int idAuto;
    system("cls");
    printf("***** INFORME AUTOS A LOS QUE SE LES REALIZO SERVICIO ******\n\n");
    mostrarServicios(serv,tamserv);
    getInt(&idServicio, "\n\nIngrese el ID del servicio que desea seleccionar: " , "Error, ingrese un ID valido.\n" ,20000, 20003);
    obtenerDescripcionServicio(descripcionServ, idServicio, serv, tamserv);
    system("cls");
    printf("***** INFORME AUTOS A LOS QUE SE LES REALIZO SERVICIO ******\n\n");
    printf("\n\n*** Autos a los que se les realizo servicio %s***\n\n", descripcionServ);
    printf("ID      PATENTE                MARCA             COLOR      MODELO              NOMBRE CLIENTE     \n\n");
    for (int i=0; i<tamtrab; i++)
    {
        if(trab[i].idServicio == idServicio)
        {
            flag = 1;
            obtenerIDdePatente(aut, tamaut, trab[i].patente, &idAuto);
            indice = existeAuto(aut, idAuto, tamaut);
            mostrarAuto(aut[indice] , marc, tammarc, col, tamcol, cli, tamcli);
            printf("Fecha de trabajo %s realizado a patente %s: %02d/%02d/%4d. \n\n" , descripcionServ, trab[i].patente, trab[i].fecha.dia, trab[i].fecha.mes, trab[i].fecha.anio);
        }
    }
    if(!flag)
    {
        printf("No se encontraron trabajos con este servicio.\n\n");
    }
}

void mostrarTrabajosFecha(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab)
{
    system("cls");
    printf("***** INFORME TRABAJOS REALIZADOS EN UNA FECHA ******\n\n");

    eFecha auxFecha;
    obtenerFecha(&auxFecha);

    int flag=0;

    system("cls");
    printf("***** INFORME TRABAJOS REALIZADOS EN UNA FECHA ******\n\n");
    printf("*** TRABAJOS REALIZADOS EL %02d/%02d/%04d ***\n\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
    printf("ID      PATENTE                 SERVICIO          FECHA\n\n");

    for(int i=0; i<tamtrab; i++)
    {
        if(auxFecha.dia == trab[i].fecha.dia && auxFecha.mes == trab[i].fecha.mes && auxFecha.anio == trab[i].fecha.anio)
        {
            flag = 1;
            mostrarTrabajo(trab[i] , serv, tamserv);
        }
    }
    if(!flag)
    {
        printf("\nNo se realizaron trabajos en esta fecha.\n\n");
    }
}

void menuInformes(eAuto aut[], int tamaut, eColor col[], int tamcol, eMarca marc[], int tammarc, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli)
{
    int opcion;
    do
    {
        system("cls");
        printf("***** MENU INFORMES *****\n\n");
        printf("\nInforme  1. Mostrar todos los autos de un color\n");
        printf("\nInforme  2. Mostrar todos los autos de una marca\n");
        printf("\nInforme  3. Mostrar el/los autos mas viejos\n");
        printf("\nInforme  4. Mostrar listado autos separado por marcas\n");
        printf("\nInforme  5. Mostrar cantidad de autos de un color y marca\n");
        printf("\nInforme  6. Mostrar la/s marca/s mas elegida/s\n");
        printf("\nInforme  7. Mostrar todos los trabajos realizados a un auto\n");
        printf("\nInforme  8. Mostrar el costo total de trabajos de un auto\n");
        printf("\nInforme  9. Mostrar autos a los que se les realizo un tipo servicio\n");
        printf("\nInforme 10. Mostrar trabajos realizados en una fecha \n");
        printf("\nSalir   11. \n");

        getInt(&opcion,"\ningrese numero de opcion: ", "\nError ingrese un numero entre 1 y 11\n.", 1 , 11 );

        switch(opcion)
        {
            case 1:

                mostrarAutosColor(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 2:

                mostrarAutosMarca(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 3:

                mostrarAutoMasViejo(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 4:

                mostrarListaAutosPorMarca(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 5:

                mostrarAutosColorYMarca(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 6:

                mostrarMarcaMasElegida(aut, tamaut, marc, tammarc, col, tamcol, cli, tamcli);
                system("pause");
                break;

            case 7:

                mostrarTrabajosDeAuto(aut, tamaut, marc, tammarc, col, tamcol, serv, tamserv, trab, tamtrab,cli, tamcli);
                system("pause");
                break;

            case 8:

                mostrarCostoTrabajosAuto(aut, tamaut, marc, tammarc, col, tamcol, serv, tamserv, trab, tamtrab, cli, tamcli);
                system("pause");
                break;

            case 9:

                mostrarAutosRealizoServicio(aut, tamaut, marc, tammarc,col, tamcol, cli, tamcli, serv, tamserv, trab, tamtrab);
                system("pause");
                break;

            case 10:

                mostrarTrabajosFecha(trab, serv, tamserv, tamtrab);
                system("pause");
                break;

            case 11:
                printf("\nVolvio al menu principal.\n");
                system("pause");
                break;

        }
    }while (opcion!= 11);
}
