#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eCliente;

#endif // CLIENTES_H_INCLUDED


/** \brief Muestra por pantalla el listado de clientes con sus datos encolumnados.
 *
 * \param cli[] eCliente Vector de clientes a recorrer
 * \param tamcli int Tamaño del vector clientes
 * \return void
 *
 */
void mostrarClientes(eCliente cli[], int tamcli);
