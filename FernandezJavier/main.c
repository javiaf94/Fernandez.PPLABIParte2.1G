#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputs.h"
#include "autos.h"
#include "servicios.h"
#include "marcas.h"
#include "colores.h"
#include "trabajos.h"
#include "fechas.h"
#include "informes.h"
#include "clientes.h"

#define TAMAUT 500
#define TAMTRAB 500
#define TAMMARC 5
#define TAMCOL 5
#define TAMSERV 4
#define TAMCLI 5


char mostrarMenu();



int main()
{
    eColor colores[TAMCOL] = { {5000, "Negro"},  {5001, "Blanco"},  {5002, "Gris"},  {5003, "Rojo"},  {5004, "Azul"} };
    eServicio servicios[TAMSERV] = { {20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600} };
    eMarca marcas[TAMMARC] = { {1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"} };
    eAuto autos[TAMAUT]; // =  { {100, "ABC123", 1000, 5000, 1994, 0, 10} , {101, "ACD345", 1001, 5002, 2001, 0, 11} , {102, "CBD324", 1004, 5004, 2000, 0, 12}, {103, "ZXC456", 1004, 5003, 1994, 0, 13}, {104, "CBS203", 1000, 5000, 2001, 0, 14}};
    eTrabajo trabajos[TAMTRAB]; // = { {4000, "ABC123" , 20002 , {2, 7, 1994} } , {4001 , "ACD345", 20002 , {12,12,2014} } , {4002, "CBD324", 20003, {13,4,2018} } , {4003, "ACD345", 20000, {5,2,2018} } , {4004, "CBS203", 20003, {13,1,2015} } , {4005, "ABC123", 20002, {7,11,2018} } , {4006, "CBD324", 20002, {15,5,2019} } , {4007, "ABC123", 20003, {23,12,2017} } , {4008, "ACD345", 20003, {19,4,2018} } , {4009, "ACD345", 20002, {8,10,2018} } , {4010, "CBD324", 20000, {30,6,2016} } };
    eCliente clientes[TAMCLI] = { {10, "Javier", 'm'}, {11, "Nicolas", 'm'}, {12, "Lujan", 'f'}, {13, "Pablo", 'm'}, {14, "Carla",'f'} };

    inicializarAutos(autos, TAMAUT);

    int idProxAut = 100;    //En caso de utilizar hardcodeo de autos, inicializar esta variable en 105
    int idProxTrab = 4000; //En caso de utilizar hardcodeo de trabajos, inicializar esta variable en 4011
    int flagAltaAuto = 0;
    int flagAltaTrabajo = 0;
    int cantidadAutos = 0;
    int cantidadTrabajos = 0;
    int continuar = 1;
    do
    {
        switch(mostrarMenu())
        {

        case 'a':
            system("cls");
            printf("***** MENU ALTA AUTO *****\n\n\n");
            if(altaAuto(autos, TAMAUT, idProxAut, colores, TAMCOL, marcas, TAMMARC, clientes, TAMCLI))
            {
                printf("\nSe cargo el auto con exito.\n");
                idProxAut++;
                flagAltaAuto = 1;
                cantidadAutos++;
            }
            else
            {
                printf("\nNo se completo la carga del auto.\n");
            }
            system("pause");
            break;


        case 'b':
            if(!flagAltaAuto||cantidadAutos==0)
            {
                printf("\nDebe realizarse por lo menos el alta de un auto para poder acceder al menu de modificaciones.\n\n");
            }
            else
            {
                modificarAuto(autos, marcas, TAMMARC, colores, TAMCOL, TAMAUT, clientes, TAMCLI);
            }

            system("pause");
            break;


        case 'c':
            if(!flagAltaAuto||cantidadAutos==0)
            {
                printf("\nDebe realizarse por lo menos el alta de un auto para poder acceder al menu de bajas.\n\n");
            }
            else
            {
                system("cls");
                printf("***** MENU BAJA AUTO*****\n\n\n");
                if(bajaAuto(autos, TAMAUT, marcas, TAMMARC, colores, TAMCOL, clientes, TAMCLI))
                {
                    printf("El auto fue borrado con exito.\n");
                    cantidadAutos--;
                }
                else
                {
                    printf("No se borro al auto.\n");
                }
            }
            system("pause");
            break;


        case 'd':
            if(!flagAltaAuto||cantidadAutos==0)
            {
                printf("\nDebe realizarse por lo menos el alta de un auto para poder acceder al menu listar autos.\n\n");
            }
            else
            {
                system("cls");
                ordenarAutos(autos, TAMAUT);
                mostrarAutos(autos, TAMAUT, marcas, TAMMARC, colores, TAMCOL, clientes, TAMCLI);
            }

            system("pause");
            break;


        case 'e':
            system("cls");
            printf("***** MENU LISTAR MARCAS *****\n");
            mostrarMarcas(marcas, TAMMARC);
            system("pause");
            break;


        case 'f':
            system("cls");
            printf("***** MENU LISTAR COLORES *****\n\n\n");
            mostrarColores(colores, TAMCOL);
            system("pause");
            break;


        case 'g':
            system("cls");
            printf("***** MENU LISTAR SERVICIOS *****\n\n");
            mostrarServicios(servicios, TAMSERV);
            system("pause");
            break;


        case 'h':
            if(!flagAltaAuto||cantidadAutos==0)
            {
                printf("\nDebe cargarse un auto antes de poder cargar un trabajo.\n");
            }
            else if(cantidadTrabajos == TAMTRAB)
            {
                printf("\nHa alcanzado el máximo de trabajos posibles.\n");
            }
            else
            {
                system("cls");
                if(altaTrabajo(idProxTrab, autos, TAMAUT, colores, TAMCOL, marcas, TAMMARC, servicios, TAMSERV, cantidadTrabajos, trabajos, clientes, TAMCLI))
                {
                    printf("El trabajo se dio de alta correctamente.\n");
                    flagAltaTrabajo = 1;
                    idProxTrab++;
                    cantidadTrabajos++;
                }
                else
                {
                    printf("No se concreto el alta del trabajo.\n");
                }
            }
            system("pause");
            break;


        case 'i':
            if(!flagAltaTrabajo)
            {
                printf("\nDebe cargarse un trabajo antes de poder acceder al menu de listar  trabajos.\n\n");
            }
            else
            {
                system("cls");
                printf("***** MENU LISTAR TRABAJOS *****\n\n\n");
                mostrarTrabajos(trabajos, servicios, TAMSERV, cantidadTrabajos);
            }

            system("pause");
            break;


        case 'j':
            menuInformes(autos, TAMAUT, colores, TAMCOL, marcas, TAMMARC, servicios, TAMSERV, trabajos, TAMTRAB, clientes, TAMCLI);
            break;

        case 'k':
            continuar = 0;
            printf("\nDecidio salir.\n");
            break;



        default:
            printf("Ingrese una opcion valida (letra de opcion en minusculas)\n");
            system("pause");
            break;

        }
    }while(continuar);

    return 0;
}

char mostrarMenu()
{
    char opcion;
    system("cls");
    printf("**** MENU GESTION LAVADERO DE AUTOS****\n\n");
    printf("a. Alta de auto\n\n");
    printf("b. Modificar auto\n\n");
    printf("c. Baja auto\n\n");
    printf("d. Listar autos\n\n");
    printf("e. Listar marcas\n\n");
    printf("f. Listar colores\n\n");
    printf("g. Listar servicios\n\n");
    printf("h. Alta trabajo\n\n");
    printf("i. Listar trabajos\n\n");
    printf("j. Menu informes\n\n");
    printf("k. Salir\n\n");
    printf("\n Ingrese la letra de la opcion del menu al que quiere acceder: ");
    fflush(stdin);
    scanf("%c" ,&opcion);
    return opcion;
}







