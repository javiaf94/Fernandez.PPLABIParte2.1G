#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED


/** \brief Muestra los datos de cada servicio de un vector de servicios en forma encolumnada.
 *
 * \param serv[] eServicio Vector de servicios a recorrer.
 * \param tamserv int Tamaño del vector de servicios.
 * \return void
 *
 */
void mostrarServicios(eServicio serv[], int tamserv);
