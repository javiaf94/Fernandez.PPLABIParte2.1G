#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Solicita una marca por teclado, y lista todos los autos de la misma.
 *
 * \param aut[] eAuto Vector de autos que se recorrer� buscando autos de la marca ingresada
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarAutosMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);

/** \brief Solicita un color por teclado, y lista todos los autos de ese color.
 *
 * \param aut[] eAuto Vector de autos que se recorrer� buscando autos del color ingresado
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarAutosColor(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Muestra por pantalla el/los auto/s mas viejo/s de un vector de autos.
 *
 * \param aut[] eAuto Vector de autos que se recorrer� buscando el auto mas viejo.
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarAutoMasViejo(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Muestra por pantalla la cantidad de autos de cada marca
 *
 * \param aut[] eAuto Vector de autos.
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas.
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarListaAutosPorMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Solicita una marca y un color por teclado. Muestra por pantalla todos los autos que cumplan ambas caracteristicas.
 *
 * \param aut[] eAuto Vector de autos que se recorrer� para mostrar los indices que cumplan con el criterio.
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas.
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarAutosColorYMarca(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Muestra por pantalla la/s marca/s mas elegida/s y la cantidad de autos que hay de cada una
 *
 * \param aut[] eAuto Vector de autos que se recorrer� para calcular la cantidad de autos de cada marca.
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas.
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores.
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes.
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarMarcaMasElegida(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli);


/** \brief Solicita un auto por pantalla y muestra todos los trabajos realizados al mismo
 *
 * \param aut[] eAuto Vector de autos para mostrar por pantalla
 * \param tamaut int tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores
 * \param tamcol int Tama�o del vector de colores
 * \param serv[] eServicio Vector de servicios
 * \param tamserv int Tama�o del vector de servicios
 * \param trab[] eTrabajo Vector de trabajos que se recorrer� mostrando los trabajos realizados al auto ingresado
 * \param tamtrab int Tama�o del vector de trabajos
 * \param cli[] eCliente Vector de clientes
 * \param tamcli int Tama�o del vector de clientes
 * \return void
 *
 */
void mostrarTrabajosDeAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli);


/** \brief Pide un auto por teclado y muestra la sumatoria de costos de trabajos realizados a este auto.
 *
 * \param aut[] eAuto Vector de autos para mostrar por pantalla
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores
 * \param tamcol int Tama�o del vector de colores
 * \param serv[] eServicio Vector de servicios
 * \param tamserv int Tama�o del vector de servicios
 * \param trab[] eTrabajo Vector de trabajos que se recorrer� sumando el costo de cada trabajo realizado al auto ingresado
 * \param tamtrab int tama�o del vector de trabajo
 * \param cli[] eCliente Vector de clientes
 * \param tamcli int tama�o del vector de clientes
 * \return void
 *
 */
void mostrarCostoTrabajosAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli);


/** \brief Pide un servicio por pantalla y muestra todos los autos a los que se realiz� el servicio y la fecha del trabajo.
 *
 * \param aut[] eAuto Vector de autos para mostrar por pantalla
 * \param tamaut int Tama�o del vector de autos
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param col[] eColor Vector de colores
 * \param tamcol int Tama�o del vector de colores
 * \param cli[] eCliente Vector de clientes
 * \param tamcli int Tama�o del vector de clientes
 * \param serv[] eServicio Vector de servicios.
 * \param tamserv int Tama�o del vector de servicios
 * \param trab[] eTrabajo Vector de trabajos que se recorrer� para buscar los servicios realizados.
 * \param tamtrab int tama�o del vector de trabajos
 * \return void
 *
 */
void mostrarAutosRealizoServicio(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol, eCliente cli[], int tamcli, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab);


/** \brief Solicita una fecha por teclado. muestra todos los trabajos realizados en la misma.
 *
 * \param trab[] eTrabajo Vector de trabajos que se recorrer� comparando la fecha ingresada y mostrando los trabajos realizados en la misma
 * \param serv[] eServicio Vector de servicios
 * \param tamserv int Tama�o del vector de servicios
 * \param tamtrab int Tama�o del vector de trabajos.
 * \return void
 *
 */
void mostrarTrabajosFecha(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab);


/** \brief Muestra un menu de opciones de informes por pantalla. Seg�n la opcion ingresada por teclado, llamara a la funcion
           correspondiente a cada informe.
 *
 * \param aut[] eAuto Vector de autos
 * \param tamaut int Tama�o del vector de autos
 * \param col[] eColor Vector de colores
 * \param tamcol int Tama�o del vector de colores
 * \param marc[] eMarca Vector de marcas
 * \param tammarc int Tama�o del vector de marcas
 * \param serv[] eServicio Vector de servicios
 * \param tamserv int Tama�o del vector de servicios
 * \param trab[] eTrabajo Vector de trabajos
 * \param tamtrab int Tama�o del vector de trabajos
 * \param cli[] eCliente Vector de clientes
 * \param tamcli int Tama�o de vector de clientes
 * \return void
 *
 */
void menuInformes(eAuto aut[], int tamaut, eColor col[], int tamcol, eMarca marc[], int tammarc, eServicio serv[], int tamserv, eTrabajo trab[], int tamtrab, eCliente cli[], int tamcli);
