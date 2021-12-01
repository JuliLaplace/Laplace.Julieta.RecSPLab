#include"LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
/** \brief Carga los datos de las peliculas desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a abrir
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro cargar los datos correctamente o 0 si no pudo realizar la carga
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList);

/** \brief Guarda los datos de las peliculas en el archivo data.csv (modo texto).
 *
 * \param path char* archivo donde se guardaran los datos
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro guardar el archivo como texto, o 0 si no logro realizarlo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);


/** \brief muestra las peliculas de la lista
 *
 * \param pArrayList LinkedList* lista a mostrar
 * \return int retorna 1 si pudo mostrar los elementos de la lista o 0 si no logro realizarlo
 *
 */
int controller_listPeliculas(LinkedList* pArrayList);

/** \brief Funcion que genera valores numericos random en Lista
 *
 * \param pArrayList LinkedList* lista donde se implementaran los valores numericos
 * \return int retorna 1 si pudo generar valores random numericos en la lista, o 0 si no logro realizarlo.
 *
 */
int controller_valoresRandom(LinkedList* pArrayList);


/** \brief Ordena peliculas
 *
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro ordenarlos las peliculas correctamente o 0 si no pudo realizarlo
 *
 */
int controller_sortPeliculas(LinkedList* pArrayList);


/** \brief Funcion que genera valores de genero random en Lista
 *
 * \param pArrayList LinkedList* lista donde se implementaran los valores de genero
 * \return int
 *
 */
int controller_valoresRandomGenero(LinkedList* pArrayList);
