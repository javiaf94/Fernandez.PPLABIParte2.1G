#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "colores.h"
#include "marcas.h"
#include "clientes.h"

typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
    int idCliente;
}eAuto;

#endif // AUTOS_H_INCLUDED


/** \brief  Inicializa un vector de autos, poniendo el campo isEmpty de cada indice en 0.
 *
 * \param aut[] eAuto Vector de autos a recorrer.
 * \param tamaut int Tamaño del vector de autos
 * \return void
 *
 */
void inicializarAutos(eAuto aut[], int tamaut);



/** \brief  Obtiene la descripcion de un color correspondiente al ID del mismo pasado por parametro
            y guarda su valor en un vector de caracteres.
 *
 * \param descripcion[] char Vector de caracteres donde se guardará la descripción.
 * \param id int ID del color que se comparará con los ID cargados en el vector de colores, para obtener su descripción.
 * \param col[] eColor Vector de colores a recorrer.
 * \param tamcol int Tamaño del vecto de colores.
 * \return void
 *
 */
void obtenerDescripcionColor(char descripcion[], int id, eColor col[], int tamcol);



/** \brief  Obtiene la descripcion de una marca, correspondiente al ID de la misma pasado por parametro
            y guarda su valor en un vector de caracteres.
 *
 * \param descripcion[] char Vector de caracteres donde se guardará la descripción.
 * \param id int ID de la marca que se comparará con los ID cargados en el vector de marcas, para obtener su descripción.
 * \param marc[] eMarca Vector de marcas a recorrer.
 * \param tammarc int Tamaño del vector de marcas.
 * \return void
 *
 */
void obtenerDescripcionMarca(char descripcion[], int id, eMarca marc[], int tammarc);


/** \brief Obtiene la patente de un auto según su ID y guarda su valor en una variable string
 *
 * \param descripcion[] char variable donde se guardara la cadena de caracteres de la patente
 * \param idAuto int id que se buscara en el vector de autos para obtener su patente
 * \param aut[] eAuto vector de autos.
 * \param tamaut int tamaño del vector de autos.
 * \return void
 *
 */
void obtenerPatente(char descripcion[], int idAuto , eAuto aut[], int tamaut);

void obtenerNombreCliente(char descripcion[], int id, eCliente cli[], int tamcli);


/** \brief Ordena un vector de autos, agrupandolos por marca y ordenandolos alfabeticamente por patente.
 *
 * \param aut[] eAuto Vector de autos que se recorrerá para ser ordenado.
 * \param tamaut int Tamaño del vector de autos.
 * \return void
 *
 */
void ordenarAutos(eAuto aut[], int tamaut);


/** \brief Muestra por pantalla la información de un auto, con sus valores en forma encolumnada.
 *
 * \param aut eAuto Auto que se imprimirá por pantalla
 * \param marc[] eMarca Vector de marcas del cual se obtendrá la descripción asociada al idMarca del auto.
 * \param tammarc int Tamaño del vector de marcas.
 * \param col[] eColor Vector de colores del cual se obtendrá la descripción asociada al idColor del auto.
 * \param tamcol int Tamaño del vector de colores.
 * \return void
 *
 */
void mostrarAuto(eAuto aut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);



/** \brief Recorre un vector de autos e imprime la información del auto ubicado en cada indice.
 *
 * \param aut[] eAuto Vector de autos a recorrer
 * \param tamaut int Tamaño del vector de autos.
 * \param marc[] eMarca Vector de marcas del cual se obtendrá la descripción asociada al idMarca del auto.
 * \param tammarc int Tamaño del vector de marcas.
 * \param col[] eColor Vector de colores del cual se obtendrá la descripción asociada al idColor del auto.
 * \param tamcol int Tamaño del vector de colores.
 * \return void
 *
 */
void mostrarAutos(eAuto aut[] , int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);



/** \brief Recorre un vector de autos verificando si la posición esta libre en cada indice.
 *
 * \param aut[] eAuto Vector de autos a recorrer.
 * \param tamaut int Tamaño del vector de autos.
 * \return int Devuelve -1 si no hay lugares libres, de lo contrario devuelve el indice de la primer posicion libre.
 *
 */
int buscarLibre(eAuto aut[], int tamaut);


/** \brief Recibe una cadena de caracteres (se espera que sea una patente), y pasa a mayusculas los 3 primeros caracteres.
 *
 * \param patente[] char Vector de caracteres al que se le pasaran a mayusculas sus 3 primeros caracteres.
 * \return void
 *
 */
void pasarPatenteMayuscula(char patente[]);

/** \brief Solicita por pantalla los datos de un nuevo auto, los almacena en un auxiliar de tipo auto y permite agregarlo a un vector autos.
 *
 * \param aut[] eAuto Vector de autos donde se agregará el nuevo auto.
 * \param tamaut int Tamaño del vector de autos.
 * \param id int ID del nuevo auto (en este caso pasaremos un id autoincremental por parametro).
 * \param col[] eColor Vector de colores que se mostrará por pantalla para seleccionar el color del nuevo auto.
 * \param tamcol int Tamaño del vector de colores.
 * \param marc[] eMarca Vector de marcas que se mostrará por pantalla para seleccionar la marca del nuevo auto.
 * \param tammarc int Tamaño del vector de marcas
 * \return int Retorna 0 si no hay lugar libre en el vector o si se no se confirma el alta. Retorna 1 si se realizó el alta correctamente.
 *
 */
int altaAuto(eAuto aut[], int tamaut, int id, eColor col[] , int tamcol, eMarca marc[], int tammarc, eCliente cli[], int tamcli);



/** \brief Recorre un vector de autos comparando un ID ingresado como parametro y verificando si existe en dicho vector.
 *
 * \param aut[] eAuto Vector de autos que se recorrerá
 * \param id int ID que se comparará en cada indice.
 * \param tamaut int Tamaño del vector de autos.
 * \return int Retorna -1 si el ID no se encontró en el vector. De lo contrario retorna la posición donde se encontro el ID.
 *
 */
int existeAuto(eAuto aut[], int id, int tamaut);



/** \brief Muestra por pantalla las opciones del menu modificar. Solicita ingresar por teclado la opcion a la que desea acceder.
 *
 * \return int Retorna el numero de opcion seleccionado.
 *
 */
int menuModificar();



/** \brief Solicita el ID de un auto y permite modificar su color o modelo.
 *
 * \param aut[] eAuto Vector de autos donde se buscará el ID ingresado por teclado.
 * \param marc[] eMarca Vector de marcas utilizado para mostrar la descripción asociada a su ID.
 * \param tammarc int Tamaño del vector de marcas.
 * \param col[] eColor Vector de colores utilizado para mostrar la lista de colores.
 * \param tamcol int Tamaño del vector de colores.
 * \param tamaut int Tamaño del vector de autos.
 * \return void
 *
 */
void modificarAuto(eAuto aut[], eMarca marc[], int tammarc, eColor col[], int tamcol, int tamaut, eCliente cli[], int tamcli);



/** \brief Permite hacer la baja logica de un auto. Ingresando el ID del auto a borrar por teclado.
 *
 * \param aut[] eAuto Vector de autos donde se buscara el ID ingresado por teclado.
 * \param tamaut int Tamaño del vector de autos.
 * \param marc[] eMarca Vector de marcas utilizado para conseguir la descripción asociada a su ID
 * \param tammarc int Tamaño del vector de marcas.
 * \param col[] eColor Vector de colores utilizado para conseguir la descripción asociada a su ID
 * \param tamcol int Tamño del vector de colores.
 * \return int Retorna 0 si el ID ingresado no existe, o no se confirma la baja. Retorna 1 si se borro correctamente.
 *
 */
int bajaAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Obtiene el ID de auto asociado a una patente y lo guarda en una variable.
 *
 * \param aut[] eAuto Vector de autos que se recorrera buscando coincidencia de patente
 * \param tamaut int tamaño del vector de autos
 * \param patente[] char Patente que se comparara con cada indice del vector de autos
 * \param pID int* Variable donde se guardará el ID encontrado.
 * \return void
 *
 */
void obtenerIDdePatente(eAuto aut[], int tamaut, char patente[], int *pID);



/** \brief Recorre un vector de autos. y verifica si hay autos cargados.
 *
 * \param aut[] eAuto Vector de autos a recorrer
 * \param tamaut int Tamaño del vector de autos
 * \return int Retorna 0 en caso de que no haya autos cargados. Retorna 1 si encontró algun auto.
 *
 */
int hayAutos(eAuto aut[], int tamaut);
