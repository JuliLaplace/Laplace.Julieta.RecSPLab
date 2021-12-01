#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"movies.h"


eMovies* new_movie(){
        eMovies* nuevaPelicula;
	    nuevaPelicula = (eMovies*) malloc(sizeof(eMovies));
	    if(nuevaPelicula!=NULL){
	        nuevaPelicula->id = 0;
	        strcpy(nuevaPelicula->nombre, " ");
	        strcpy(nuevaPelicula->genero, " ");
	        nuevaPelicula->rating = 0;

	    }

	    return nuevaPelicula;
}

eMovies* pelicula_newParametros(char *idStr, char *peliculaStr, char *generoStr, char *ratingStr){
    eMovies* nuevaPelicula = new_movie(); //aca pido malloc de eMovie*

	if(nuevaPelicula!=NULL && idStr!=NULL && peliculaStr!=NULL && generoStr!=NULL && ratingStr!=NULL){
	        if(!(pelicula_setId(nuevaPelicula, atoi(idStr)) && pelicula_setNombre(nuevaPelicula, peliculaStr) && pelicula_setGenero(nuevaPelicula, generoStr)
              && pelicula_setRating(nuevaPelicula, atoi(ratingStr)))){
	            pelicula_delete(nuevaPelicula);
	            nuevaPelicula=NULL;
	        }
	    }

	    return nuevaPelicula;
}

void pelicula_delete(eMovies *this){
        free(this);


}


//SETTER Y GETTER
int pelicula_setId(eMovies *this, int id){
    int todoOk=0;
	    if(this!=NULL && id>0){
	        this->id=id;
	        todoOk=1;
	    }


	return todoOk;
}

int pelicula_getId(eMovies *this, int *id){
    int todoOk=0;
	    if(this!=NULL && id!=NULL){
	        *id= this->id;
	        todoOk=1;
	    }


	    return todoOk;
}

int pelicula_setNombre(eMovies *this, char *pelicula){
    int todoOk=0;
	    if(this!=NULL && pelicula!=NULL){
	       if(strlen(pelicula)<50 && strlen(pelicula)>2){
	            strcpy(this->nombre, pelicula);

	            todoOk=1;
	       }

	    }

	return todoOk;
}

int pelicula_getNombre(eMovies *this, char *pelicula){
     int todoOk=0;
    if(this!=NULL && pelicula!=NULL){
        strcpy(pelicula, this->nombre);
        todoOk=1;
    }


    return todoOk;
}

int pelicula_setGenero(eMovies *this, char *genero){
    int todoOk=0;
	    if(this!=NULL && genero!=NULL){
	       if(strlen(genero)<50 && strlen(genero)>2){
	            strcpy(this->genero, genero);

	            todoOk=1;
	       }

	    }

	return todoOk;
}
int pelicula_getGenero(eMovies *this, char *genero){
     int todoOk=0;
    if(this!=NULL && genero!=NULL){
        strcpy(genero, this->genero);
        todoOk=1;
    }


    return todoOk;
}

int pelicula_setRating(eMovies *this, int rating){
    int todoOk = 0;
    if (this != NULL && rating >= 0.00)
    {
        this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getRating(eMovies *this, int *rating){
    int todoOk = 0;
    if (this != NULL && rating!=NULL)
    {
        *rating = this->rating;
        todoOk = 1;
    }
    return todoOk;
}


void mostrarPelicula(eMovies* unaPelicula)
{
    int auxId;
    char auxNombre[50];
    char auxGenero[50];
    int auxRating;

    if(unaPelicula!=NULL && pelicula_getId(unaPelicula,&auxId) &&
            pelicula_getNombre(unaPelicula, auxNombre) &&
            pelicula_getGenero(unaPelicula, auxGenero) &&
            pelicula_getRating(unaPelicula, &auxRating))
    {
        printf("%2d  %-10s                  %-10s        %d \n", auxId, auxNombre, auxGenero,auxRating);
    }else{
         printf("No hay peliculas que mostrar");
    }

}

//ASIGNAR RANDOM

void* asignarRating(void* pElement)
{
    eMovies* aux=NULL;
    int rating;
    int max = 10;
    int min = 1;

    aux= (eMovies*) pElement;
    if(pElement != NULL )
    {
        rating = rand() % (max - min + 1) + min;
        pelicula_setRating(aux, rating);

    }
    return aux;
}


void* asignarGenero(void* pElement)
{
    eMovies* aux=NULL;
    int rating;
    int max = 4;
    int min = 1;

    aux= (eMovies*) pElement;
    if(pElement != NULL )
    {
        rating = rand() % (max - min + 1) + min;
        if(rating==1){
            pelicula_setGenero(aux, "Drama");
        }
        if(rating==2){
            pelicula_setGenero(aux, "Comedy");
        }
        if(rating==3){
            pelicula_setGenero(aux, "Action");
        }
        if(rating==4){
            pelicula_setGenero(aux, "Horror");
        }

    }
    return aux;
}


//FILTROS
int filtrarTipoDrama(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Drama")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarTipoHorror(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Horror")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarTipoComedy(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Comedy")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}


int filtrarTipoAction(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Action")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

//ORDENAR

int ordenarGeneroRating(void* peli1, void* peli2)
{
    int todoOk=0;
	char genero[30];
	char genero2[30];
	int rating;
	int rating2;
	eMovies* auxPeli1;
	eMovies* auxPeli2;
    if(peli1!=NULL && peli2!=NULL){
        auxPeli1 = (eMovies*) peli1;
        auxPeli2 = (eMovies*) peli2;
        if(auxPeli1!=NULL && auxPeli2!=NULL)
        {
            pelicula_getGenero(auxPeli1, genero);
            pelicula_getGenero(auxPeli2, genero2);
            pelicula_getRating(auxPeli1, &rating);
            pelicula_getRating(auxPeli2,&rating2);

            if(strcmp(genero, genero2)< 0){
                todoOk=1;
            }else if(strcmp(genero, genero2)> 0){
                todoOk=-1;
            }else{
                if( strcmp(genero, genero2) == 0 )
                {
                    if(rating > rating2)
                    {
                        todoOk=1;
                    }
                    else if(rating < rating2)
                    {
                        todoOk=-1;
                    }
                }
            }
        }
    }

	return todoOk;
}
