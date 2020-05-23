#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;


#endif // COLORES_H_INCLUDED


/** \brief Muestra los datos de cada color de un vector de colores en forma encolumnada.
 *
 * \param marc[] eMarca Vector de colores a recorrer.
 * \param tammarc int Tamaño del vector de colores.
 * \return void
 *
 */
void mostrarColores(eColor col[], int tamcol);
