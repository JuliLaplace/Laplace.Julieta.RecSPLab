#include <stdio.h>
#include <stdlib.h>
#include"menu.h"

int menu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE OPCIONES********\n");
        printf("*****************************************************************************************\n");
        printf("1. CARGAR ARCHIVO.\n");
        printf("2. IMPRIMIR LISTA DE PELICULAS.\n");
        printf("3. ASIGNAR RAITING.\n");
        printf("4. ASIGNAR GENERO.\n");
        printf("5. FILTRAR POR GENERO.\n");
        printf("6. ORDENAR PELICULAS.\n");
        printf("7. GUARDAR PELICULAS ORDENADAS.\n");
        printf("8. SALIR.\n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}

int subMenu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE GENEROS********\n");
        printf("*****************************************************************************************\n");
        printf("1. Comedy.\n");
        printf("2. Drama.\n");
        printf("3. Action.\n");
        printf("4. Horror.\n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}
