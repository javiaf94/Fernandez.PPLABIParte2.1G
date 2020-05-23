#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCAS_H_INCLUDED


/** \brief Muestra los datos de cada marca de un vector de marcas en forma encolumnada.
 *
 * \param marc[] eMarca Vector de marcas a recorrer.
 * \param tammarc int Tamaño del vector de marcas.
 * \return void
 *
 */
void mostrarMarcas(eMarca marc[], int tammarc);
