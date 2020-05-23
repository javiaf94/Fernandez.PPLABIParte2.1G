#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "fechas.h"
#include "servicios.h"
#include "marcas.h"

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED


/** \brief Obtiene la descripcion del servicio relacionada al ID y guarda el valor en una cadena de caracteres.
 *
 * \param descripcion[] char Cadena de caracteres donde se guarda la descripci�n.
 * \param id int  ID del servicio del cual se buscar� la descripcion
 * \param serv[] eServicio  Array de servicios a recorrer
 * \param tamserv int  tama�o del array de servicios.
 * \return void
 *
 */
void obtenerDescripcionServicio(char descripcion[], int id, eServicio serv[], int tamserv);



/** \brief Muestra por pantalla los datos de un trabajo en forma encolumnada.
 *
 * \param trab eTrabajo Trabajo a mostrar.
 * \param serv[] eServicio  Vector de servicios de donde se buscara la descripcion para ser mostrada por pantalla
 * \param tamserv int  Tama�o del vector de servicios.
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamserv);



/** \brief Recorre un vector de trabajos, imprimiendo los datos de cada indice.
 *
 * \param trab[] eTrabajo Vector de trabajos a recorrer
 * \param serv[] eServicio  Vector de servicios de donde se buscara la descripcion para ser mostrada por pantalla
 * \param tamserv int Tama�o del vector de servicios a recorrer

 * \param tamtrab int Tama�o Del vector de trabajos.
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab);



/** \brief Permite el alta de un nuevo trabajo, solicitando el ingreso de los datos por teclado y pidiendo confirmacion
 *
 * \param id int ID ID del tipo autoincremental que se pasar� por parametro
 * \param aut[] eAuto Vector de autos utilizado para mostrar informaci�n del auto al que se asociar� el trabajo
 * \param tamaut int Tama�o del vector de autos
 * \param col[] eColor Vector de autos utilizado para mostrar lista de colores
 * \param tamcol int Tama�o del vector de colores
 * \param marc[] eMarca Vector de autos utilizado para mostrar lista de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param serv[] eServicio Vector de autos utilizado para mostrar lista de servicios
 * \param tamserv int Tama�o del vector de servicios
 * \param indice int Indice autoincremental donde se iran almacenando los nuevos trabajos.
 * \param trab[] eTrabajo Vector de trabajos donde se almacenar�n los nuevos trabajos
 * \return int Retorna 1 si el trabajo se carg� exitosamente, 0 si se abort� la carga.
 *
 */
int altaTrabajo(int id, eAuto aut[], int tamaut, eColor col[], int tamcol, eMarca marc[], int tammarc, eServicio serv[], int tamserv, int indice, eTrabajo trab[], eCliente cli[], int tamcli);

