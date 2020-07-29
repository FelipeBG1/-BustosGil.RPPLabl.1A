#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include <string.h>
#include "parser.h"
#include "informes.h"
#include "Bicicletas.h"


int getRandomTiempo()
{
    int aleatorio;

    aleatorio = rand()%(71)+50;

    return aleatorio;
}

void* settearTiempo(void* element)
{
    eBicicleta* auxBicicleta;
    int tiempo;
    if(element!=NULL)
    {
        tiempo=getRandomTiempo();
        auxBicicleta=(eBicicleta*)element;
        bicicleta_setTiempo(auxBicicleta,tiempo);
    }
    return auxBicicleta;
}

int bicicletaSetCampoTiempo(LinkedList* lista)
{
    LinkedList* auxLista;
    int todoOk=1;

    if(lista!=NULL)
    {
        auxLista=ll_map(lista,settearTiempo);
        if(auxLista!=NULL)
        {
            printf("Se asignaron los datos correctamente\n\n");
            todoOk=0;
        }
        else
        {
            printf("No se pudieron asignar los datos\n\n");
        }

    }

    return todoOk;
}

int bicicletaBMX(void* element)
{
    int todoOk=1;
    char tipo[20];
    eBicicleta* auxBicicleta;
    if(element!=NULL)
    {
        auxBicicleta=(eBicicleta*)element;
        bicicleta_getTipo(auxBicicleta,tipo);

        if(strcmp(tipo,"BMX")==0)
        {
            todoOk=0;
        }
    }

    return todoOk;
}

int bicicletaMTB(void* element)
{
    int todoOk=1;
    char tipo[20];
    eBicicleta* auxBicicleta;
    if(element!=NULL)
    {
        auxBicicleta=(eBicicleta*)element;
        bicicleta_getTipo(auxBicicleta,tipo);

        if(strcmp(tipo,"MTB")==0)
        {
            todoOk=0;
        }
    }

    return todoOk;
}

int bicicletaPaseo(void* element)
{
    int todoOk=1;
    char tipo[20];
    eBicicleta* auxBicicleta;
    if(element!=NULL)
    {
        auxBicicleta=(eBicicleta*)element;
        bicicleta_getTipo(auxBicicleta,tipo);

        if(strcmp(tipo,"PASEO")==0)
        {
            todoOk=0;
        }
    }

    return todoOk;
}

int bicicletaPlayera(void* element)
{
    int todoOk=1;
    char tipo[20];
    eBicicleta* auxBicicleta;
    if(element!=NULL)
    {
        auxBicicleta=(eBicicleta*)element;
        bicicleta_getTipo(auxBicicleta,tipo);

        if(strcmp(tipo,"PLAYERA")==0)
        {
            todoOk=0;
        }
    }

    return todoOk;
}

int menuFiltrado()
{
    int opcion;
    system("cls");
    printf("**** MENU DE FILTRADO ****\n\n");
    printf("1- BMX\n");
    printf("2- MTB\n");
    printf("3- PASEO\n");
    printf("4- PLAYERO\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}


LinkedList* filtrarPorTipo(LinkedList* lista)
{
    LinkedList* auxlista;
    int todoOk=1;
    if(lista!=NULL)
    {
        switch(menuFiltrado())
        {
            case 1:
                auxlista=ll_filter(lista,bicicletaBMX);
                if(auxlista!=NULL)
                {
                    todoOk=0;
                }
                break;
            case 2:
                auxlista=ll_filter(lista,bicicletaMTB);
                if(auxlista!=NULL)
                {
                    todoOk=0;
                }
                break;
            case 3:
                auxlista=ll_filter(lista,bicicletaPaseo);
                if(auxlista!=NULL)
                {
                    todoOk=0;
                }
                break;
            case 4:
                auxlista=ll_filter(lista,bicicletaPlayera);
                if(auxlista!=NULL)
                {
                    todoOk=0;
                }
                break;

            default:
                printf("Ingrese una opcion valida\n\n");
                break;
        }
    }
    if(todoOk==0)
    {
        printf("Se filtraron los datos\n\n");
    }

    return auxlista;
}

int ordenarBicicletas(LinkedList* lista)
{
    int todoOk = 1;

    if(lista != NULL)
    {

        if(!ll_sort(lista,comparaBicicletasTipo,1))
        {
            system("cls");
            mostrarBicletas(lista);
            todoOk = 0;
        }
        else
        {
            printf("No se pudieron ordenar las bicicletas\n");
        }
    }

    return todoOk;
}


int comparaBicicletasTipo(void * a, void* b)
{
    int retorno = 0;
    eBicicleta* p1;
    eBicicleta* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eBicicleta*) a;
        p2 = (eBicicleta*) b;

        retorno = strcmp(p1->tipo,p2->tipo);

        if(!strcmp(p1->tipo,p2->tipo))
        {
            retorno = comparaBicicletasTiempo(p1,p2);
        }

    }

    return retorno;
}

int comparaBicicletasTiempo(void* a, void* b)
{
    int returnAux=0;
    eBicicleta* e1;
    eBicicleta* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (eBicicleta*)a;
        e2 = (eBicicleta*)b;

        if(e1->tiempo > e2->tiempo)
        {
            returnAux=1;
        }
        else
        {
            if(e1->tiempo < e2->tiempo)
            {
                returnAux= -1;
            }
        }
    }
    return returnAux;
}
