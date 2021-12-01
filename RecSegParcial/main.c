#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include"menu.h"
#include"controller.h"
#include "movies.h"
int main()
{
    srand(time(NULL));
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaGeneros = ll_newLinkedList();
    char archivoAbrir[20];
    int flagRating=0;
    int flagGeneros=0;
    int flagOrden=0;
    char respuesta='s';

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese nombre del archivo que desea abrir (ya existe el archivo movies.csv): ");
            fflush(stdin);
            gets(archivoAbrir);
            if(controller_loadFromText(archivoAbrir,lista))
            {
                printf("Datos de peliculas cargados desde el archivo %s con exito.\n ", archivoAbrir);

            }
            else
            {
                printf("Error en carga de archivo. Reintente.\n ");
            }
            break;
        case 2:
            if(ll_isEmpty(lista))
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            else if(!ll_isEmpty(lista))
            {
                controller_listPeliculas(lista);
                printf("Peliculas listadas correctamente.\n ");
            }
            break;
        case 3:

            if(ll_isEmpty(lista))
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            else if(!ll_isEmpty(lista))
            {
                if(controller_valoresRandom(lista)){
                    printf("Raitings asignados correctamente.\n");
                    flagRating=1;
                }

            }
            break;

        case 4:
            if(ll_isEmpty(lista))
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            else if(!ll_isEmpty(lista))
            {
                if(controller_valoresRandomGenero(lista)){
                    printf("Generos asignados correctamente.\n");
                    flagGeneros=1;
                }

            }
            break;

        case 5:
            if(!ll_isEmpty(lista) && flagGeneros && flagRating)
            {
                switch(subMenu())
                {
                case 1:
                    listaGeneros = ll_filter(lista, filtrarTipoComedy);
                    if(!controller_saveAsText("ListaTipoComedy.csv", listaGeneros))
                    {
                        printf("Error al guardar la lista\n");
                        ll_deleteLinkedList(listaGeneros);
                    }
                    else
                    {
                        printf("Peliculas tipo 'Comedy' guardadas correctamente.\n");
                    }

                    break;
                case 2:
                    listaGeneros = ll_filter(lista, filtrarTipoDrama);
                    if(!controller_saveAsText("ListaTipoDrama.csv", listaGeneros))
                    {
                        printf("Error al guardar la lista\n");
                        ll_deleteLinkedList(listaGeneros);
                    }
                    else
                    {
                        printf("Peliculas tipo 'Drama' guardadas correctamente.\n");
                    }


                    break;
                case 3:
                    listaGeneros = ll_filter(lista, filtrarTipoAction);
                    if(!controller_saveAsText("ListaTipoAction.csv", listaGeneros))
                    {
                        printf("Error al guardar la lista\n");
                        ll_deleteLinkedList(listaGeneros);
                    }
                    else
                    {
                        printf("Peliculas tipo 'Action' guardadas correctamente.\n");
                    }

                    break;
                case 4:
                    listaGeneros = ll_filter(lista, filtrarTipoHorror);
                    if(!controller_saveAsText("ListaTipoHorror.csv", listaGeneros))
                    {
                        printf("Error al guardar la lista\n");
                        ll_deleteLinkedList(listaGeneros);
                    }
                    else
                    {
                        printf("Peliculas tipo 'Horror' guardadas correctamente.\n");
                    }

                    break;

                default:
                    printf("La opcion ingresada es incorrecta.\n");
                    break;
                }
            }
            else if((!ll_isEmpty(lista) && !flagRating && !flagGeneros) || (!ll_isEmpty(lista) && flagRating && !flagGeneros) || (!ll_isEmpty(lista) && !flagRating && flagGeneros) ){
                printf("Primero debes asignar generos a la lista de peliculas (opcion 4) y raiting (opcion 3) para poder accederal filtro.\n");
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;

        case 6:
            if(!ll_isEmpty(lista) && flagRating && flagGeneros)
            {
                if(controller_sortPeliculas(lista))
                {
                    printf("Peliculas ordenadas por genero ascendente y raiting descendente correctamente.\n");
                    flagOrden=1;
                }
            }
            else if((!ll_isEmpty(lista) && !flagRating && !flagGeneros) || (!ll_isEmpty(lista) && flagRating && !flagGeneros) || (!ll_isEmpty(lista) && !flagRating && flagGeneros) )
            {
                printf("Primero debes asignar generos a la lista de peliculas (opcion 4) y raiting (opcion 3) para poder acceder a su ordenamiento.\n");
            } else{
                 printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;

        case 7:
            if(flagOrden)
            {
                if(controller_saveAsText("peliculasListaGeneroDuracion.csv", lista))
                {
                    printf("Peliculas guardadas correctamente.\n");
                }

            }
            else if(!(ll_isEmpty(lista)) && (!flagOrden))
            {
                printf("Primero debes ordenar las peliculas por genero (opcion 6).\n");
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;

        case 8:
            printf("Usted salio del programa.\n");

            ll_deleteLinkedList(lista);
            ll_deleteLinkedList(listaGeneros);
            lista=NULL;
            listaGeneros=NULL;

            respuesta='n';
            break;

        default:
            printf("La opcion ingresada es incorrecta. Reintente.\n");
            break;
        }
        system("pause");
    }
    while(respuesta=='s');
    return 0;
}
