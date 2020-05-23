#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;


#endif // FECHAS_H_INCLUDED

/** \brief Solicita dia mes y año, y verifica que los datos sean correctos
 *
 * \param ptrFecha eFecha* Puntero a estructura fecha donde se almacenara la fecha ingresada si la misma es correcta
 * \return int Retorna 1 si la fecha se cargó correctamente, y 0 si la fecha es incorrecta.
 *
 */
int obtenerFecha(eFecha *ptrFecha);
