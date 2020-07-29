#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include <string.h>
#include "parser.h"
#include "informes.h"
#include "Bicicletas.h"



int main()
{
    srand (time(NULL));
    char seguir = 's';
    char confirma;
    int flagCarga=0;
    int flagTiempo=0;
    int flagOrdenado=0;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaPorTipo = ll_newLinkedList();

     do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(controller_loadFromText(lista)==0)
            {
                flagCarga=1;
            }
            break;
        case 2:
            if(flagCarga)
            {
                mostrarBicletas(lista);
            }
            else
            {
                printf("Primero debe cargar los datos\n\n");
            }

            break;
        case 3:
            if(flagCarga)
            {
                if(bicicletaSetCampoTiempo(lista)==0)
                {
                    flagTiempo=1;
                }
            }
            else
            {
                printf("Primero debe cargar los datos\n\n");
            }
            break;
        case 4:
            if(flagTiempo || flagCarga)
            {
                listaPorTipo=filtrarPorTipo(lista);
                if(listaPorTipo!=NULL)
                {
                    if(controller_saveAsText("tipoSeleccionado.csv",listaPorTipo)==0)
                    {
                        printf("Se guardaron los datos en un archivo\n\n");
                    }
                }
            }
            else
            {
                printf("Primero debe cargar los datos\n\n");
            }

           break;
        case 5:
            if(flagTiempo)
            {
                if(ordenarBicicletas(lista)==0)
                {
                    flagOrdenado=1;
                }
            }
            else
            {
                printf("Primero debe cargar los datos\n\n");
            }



            break;
        case 6:
            if(flagOrdenado)
            {
                if(controller_saveAsText("listaOrdenada.csv",lista)==0)
                {
                    printf("Se guardaron los datos en un archivo\n\n");
                }
                else
                {
                    printf("No se pudieron guardar los datos\n\n");
                }

            }
            else
            {
                printf("Antes de guardar se debe ordenar la lista\n\n");
            }

            break;
        case 7:
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
        break;
       default:
        printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaPorTipo);



    return 0;
}




