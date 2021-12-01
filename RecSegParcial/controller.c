#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include"movies.h"
#include <string.h>
#include "parser.h"


int controller_loadFromText(char* path, LinkedList* pArrayList)
{
	   int todoOk = 0;

	    if(path!=NULL && pArrayList!=NULL){

	        FILE* file = fopen(path, "r"); //lee archivo texto

	        if(file==NULL){
	            printf("No exite el archivo ingresado. Reintente\n");
	        }else{
	          todoOk = parser_peliculasFromText(file, pArrayList);

	        }
	        fclose(file);        //cierra archivo
	    }

	    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
		int todoOk;
	    eMovies* aux=NULL;

	    	if(path!=NULL && pArrayList!=NULL){
	    		FILE* file= fopen(path, "w");
				if(file==NULL)
				{
					printf("Error en abrir el archivo.\n");
					todoOk=0;

				}else{
                    fprintf(file,"Id,Nombre,Genero,Duracion.\n");
                    for(int i=0; i<ll_len(pArrayList); i++)
                    {
                        aux=(eMovies*)ll_get(pArrayList,i);
                        if(aux!=NULL)
                        {
                            fprintf(file,"%d,%10s,%10s,%d\n", aux->id, aux->nombre, aux->genero, aux->rating);
                            todoOk=1;
						}
						aux=NULL;
					}
				}

					fclose(file);
        }

	    return todoOk;
}


int controller_listPeliculas(LinkedList* pArrayList)
{
    eMovies* aux=NULL;
    int todoOk=0;

    if(pArrayList!=NULL)
    {
        printf("************************************************************\n");
        printf("                       Listar Peliculas\n");
        printf("************************************************************\n");
        printf("ID         Nombre               Tipo            Rating\n");
        printf("************************************************************\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
           aux = (eMovies*) ll_get(pArrayList,i);
           if(aux!=NULL){
            mostrarPelicula(aux);
           }

           todoOk=1;
        }
        printf("\n\n");

    }
    return todoOk;
}

//OK
int controller_valoresRandom(LinkedList* pArrayList){
    int todoOk=0;
    if(pArrayList!=NULL){
        if(ll_map(pArrayList, asignarRating)!=NULL){
            controller_listPeliculas(pArrayList);
            todoOk=1;
        }
    }
    return todoOk;
}

int controller_valoresRandomGenero(LinkedList* pArrayList){
    int todoOk=0;
    if(pArrayList!=NULL){
        if(ll_map(pArrayList, asignarGenero)!=NULL){
            controller_listPeliculas(pArrayList);
            todoOk=1;
        }
    }
    return todoOk;
}








int controller_sortPeliculas(LinkedList* pArrayList)
{
	int todoOk=0;
	if(pArrayList!=NULL){


                printf("**************************************************\n");
				printf("                 LISTA ORDENADA               \n");
				printf("**************************************************\n");
				if(!ll_sort(pArrayList,ordenarGeneroRating,1)){
                  controller_listPeliculas(pArrayList);

                    todoOk=1;
				} else{
                    printf("No se pudo ordenar la lista.\n");
				}


	}

	    return todoOk;
}



