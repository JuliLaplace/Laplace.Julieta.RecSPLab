#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/** \brief Parsea los datos los datos de las peliculas desde el archivo path* pasado como parametro (modo texto).
 *
 * \param path char* puntero a char(direccion de memoria del archivo).
 * \param pArrayList LinkedList* puntero a estructura de la lista de peliculas LinkedList.
 * \return int retorna 0 si hubo un error en el parseo o 1 si pudo parsear los datos .
 *
 */
int parser_peliculasFromText(FILE* pFile , LinkedList* pArrayList);

