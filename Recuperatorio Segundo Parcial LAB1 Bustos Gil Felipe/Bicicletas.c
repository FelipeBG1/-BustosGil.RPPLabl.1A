#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include <string.h>
#include "parser.h"
#include "informes.h"
#include "Bicicletas.h"

void mostrarBicicleta( LinkedList* lista,int indice)
{
    eBicicleta* bicicleta;
    bicicleta = ll_get(lista, indice);

    printf("%4d    %10s   %10s   %4d\n", bicicleta->id_bike,bicicleta->nombre,bicicleta->tipo,bicicleta->tiempo);

}

int mostrarBicletas(LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  Id        Nombre         Tipo     Tiempo\n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarBicicleta(lista, i);
        }
    }
    else
    {
        printf("No hay bicicletas que listar\n");
    }
    return todoOk;
}

int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar tiempo\n");
    printf("4- Filtrar por tipo\n");
    printf("5- Mostrar posiciones\n");
    printf("6- Guardar posiciones\n");
    printf("7- Salir\n\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}

eBicicleta* bicicleta_new()
{
    eBicicleta* newBicicleta = (eBicicleta*) malloc(sizeof(eBicicleta));

    return newBicicleta;
}

eBicicleta* bicicleta_newParamS(char* idStr, char* nombreStr, char* tipoStr,char* tiempoStr)
{
    return bicicleta_newParametros(atoi(idStr),nombreStr,tipoStr,atoi(tiempoStr));
}

eBicicleta* bicicleta_newParametros(int id, char* nombre, char* tipo,int tiempo)
{
    eBicicleta* newBicicleta = bicicleta_new();

        if(newBicicleta != NULL)
        {
            bicicleta_setId(newBicicleta,id);
            bicicleta_setNombre(newBicicleta,nombre);
            bicicleta_setTipo(newBicicleta,tipo);
            bicicleta_setTiempo(newBicicleta,tiempo);
        }
        else
        {
            free(newBicicleta);
            newBicicleta=NULL;
        }
        return newBicicleta;
}

int bicicleta_setId(eBicicleta* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id_bike= id;
        todoOk=0;
    }
    return todoOk;
}

int bicicleta_getId(eBicicleta* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
       *id = this->id_bike;
       todoOk = 0;
    }
    return todoOk;
}

int bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 50)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 1;

    if(this != NULL && tipo != NULL && strlen(tipo) <= 19)
    {
        strcpy(this->tipo,tipo);
        todoOk = 0;
    }
    return todoOk;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo,this->tipo);
        todoOk = 0;
    }
    return todoOk;
}

int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int todoOk = 1;
    if(this != NULL && tiempo >=0 )
    {
        this->tiempo= tiempo;
        todoOk=0;
    }
    return todoOk;
}

int bicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int todoOk = 1;

    if(this != NULL && tiempo != NULL)
    {
       *tiempo = this->tiempo;
       todoOk = 0;
    }
    return todoOk;
}
