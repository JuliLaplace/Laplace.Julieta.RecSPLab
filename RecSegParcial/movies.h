#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    char genero[50];
    int rating;
}eMovies;

#endif // MOVIES_H_INCLUDED


/** \brief Funcion que crea un nuevo campo de peliculas en memoria y lo inicializa
 *
 * \return eMovies*
 *
 */
eMovies* new_movie();

/** \brief Funcion que crea un nuevo campo de peliculas en memoria y lo carga con los datos (parametros) pasados
 *
 * \param idStr char* campo ID a setear
 * \param peliculaStr char* campo Nombre a setear
 * \param generoStr char* campo genero a setear
 * \param ratingStr char* campo raiting a setear
 * \return eMovies* retorna los elementos cargados por parametros de la estructurae Movies*
 *
 */
eMovies* pelicula_newParametros(char *idStr, char *peliculaStr, char *generoStr, char *ratingStr);

/** \brief Funcion que elimina un empleado cargado
 *
 * \param this eMovies* estructua
 * \return void
 *
 */
void pelicula_delete(eMovies *this);

/** \brief Funcion que setea un ID
 *
 * \param this eMovies*
 * \param id int
 * \return int
 *
 */
int pelicula_setId(eMovies *this, int id);
/** \brief Funcion que obtiene un ID de una pelicula
 *
 * \param this eMovies*
 * \param id int*
 * \return int
 *
 */
int pelicula_getId(eMovies *this, int *id);
/** \brief Funcion que setea un Nombre de pelicula
 *
 * \param this eMovies*
 * \param pelicula char*
 * \return int
 *
 */
int pelicula_setNombre(eMovies *this, char *pelicula);
/** \brief Funcion que obtiene un nombre de una pelicula
 *
 * \param this eMovies*
 * \param pelicula char*
 * \return int
 *
 */
int pelicula_getNombre(eMovies *this, char *pelicula);

/** \brief Funcion que setea un genero de pelicula
 *
 * \param this eMovies*
 * \param genero char*
 * \return int
 *
 */
int pelicula_setGenero(eMovies *this, char *genero);
/** \brief Funcion que obtiene un genero de una pelicula
 *
 * \param this eMovies*
 * \param genero char*
 * \return int
 *
 */
int pelicula_getGenero(eMovies *this, char *genero);
/** \brief Funcion que setea el raiting de una pelicula
 *
 * \param this eMovies*
 * \param rating int
 * \return int
 *
 */
int pelicula_setRating(eMovies *this, int rating);
/** \brief Funcion que obtiene el raiting de una pelicula
 *
 * \param this eMovies*
 * \param rating int*
 * \return int
 *
 */
int pelicula_getRating(eMovies *this, int *rating);

/** \brief Funcion que asigna diferentes numeros de raiting a los elementos de una lista
 *
 * \param pElement void* elemento a asignarle el raiting aleatorio
 * \return void*
 *
 */
void* asignarRating(void* pElement);

/** \brief Funcion que asigna diferentes generos de peliculas a los elementos de una lista
 *
 * \param pElement void*elemento a asignarle el genero aleatorio
 * \return void*
 *
 */
void* asignarGenero(void* pElement);

/** \brief Funcion que muestra una pelicula
 *
 * \param unaPelicula eMovies*
 * \return void
 *
 */
void mostrarPelicula(eMovies* unaPelicula);


/** \brief Funcion que filtra los elementos de la lista por tipo Drama
 *
 * \param pElement void* elemento a usar como parametro de filtro
 * \return int retorna 1 si el elemento pasa el filtro o 0 si no pasa el filtro.
 *
 */
int filtrarTipoDrama(void* pElement);

/** \brief Funcion que filtra los elementos de la lista por tipo Horror
 *
 * \param pElement void* elemento a usar como parametro de filtro
 * \return int retorna 1 si el elemento pasa el filtro o 0 si no pasa el filtro.
 *
 */
int filtrarTipoHorror(void* pElement);

/** \brief Funcion que filtra los elementos de la lista por tipo Comedy
 *
 * \param pElement void* elemento a usar como parametro de filtro
 * \return int retorna 1 si el elemento pasa el filtro o 0 si no pasa el filtro.
 *
 */
int filtrarTipoComedy(void* pElement);

/** \brief Funcion que filtra los elementos de la lista por tipo Action
 *
 * \param pElement void* elemento a usar como parametro de filtro
 * \return int retorna 1 si el elemento pasa el filtro o 0 si no pasa el filtro.
 *
 */
int filtrarTipoAction(void* pElement);

/** \brief Funcion que swapea entre peliculas dentro de una lista para ordenarla segun su genero y su raiting
 *
 * \param peli1 void* pelicula comparar
 * \param peli2 void* segunda pelicula a comparar
 * \return int
 *
 */
int ordenarGeneroRating(void* peli1, void* peli2);
