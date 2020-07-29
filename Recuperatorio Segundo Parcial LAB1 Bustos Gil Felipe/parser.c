#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include <string.h>
#include "parser.h"
#include "informes.h"
#include "Bicicletas.h"

int controller_loadFromText(LinkedList* pArrayListBicicletas)
{
    int todoOk = 1;
    char archivo[51];

    printf("\nIngrese el nombre del archivo: ");
    fflush(stdin);
    scanf("%s",archivo);

    strcat(archivo,".csv");

    FILE* f = fopen(archivo,"r");

    if(f != NULL)
    {
        if(parser_BicicletasFromText(f,pArrayListBicicletas)==0)
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
        else
        {
            printf("No se pudieron cargar los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

int parser_BicicletasFromText(FILE* pFile , LinkedList* pArrayListBicletas)
{
    int todoOk = 1;
    int cant;
    char cadena[4][51];


    eBicicleta* newBicicleta = (eBicicleta*) bicicleta_new();

    if (pFile == NULL || pArrayListBicletas == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListBicletas);
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",cadena[0], cadena[1], cadena[2], cadena[3]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",cadena[0], cadena[1], cadena[2], cadena[3]);
        if (cant == 4)
        {
            newBicicleta = bicicleta_newParamS(cadena[0], cadena[1], cadena[2], cadena[3]);

            if (newBicicleta != NULL)
            {
                ll_add(pArrayListBicletas, newBicicleta);
                todoOk = 0;
            }
        }

    }


    return todoOk;

}

int controller_saveAsText(char* path , LinkedList* pArrayListBicletas)
{
    int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[51];
	char auxTipo[20];
	int auxTiempo;


	eBicicleta* pBicicleta;

	if(pArrayListBicletas != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{

			fprintf(pFile, "id,nombre,tipo,tiempo\n");
			for(int i = 0; i < ll_len(pArrayListBicletas); i++)
			{
				pBicicleta = ll_get(pArrayListBicletas, i);

				if(!bicicleta_getId(pBicicleta,&auxId)&&
                   !bicicleta_getNombre(pBicicleta,auxNombre)&&
                   !bicicleta_getTipo(pBicicleta,auxTipo)&&
                   !bicicleta_getTiempo(pBicicleta,&auxTiempo))
				{
                    fprintf(pFile, "%d,%s,%s,%d\n",auxId,auxNombre,auxTipo,auxTiempo);
                    todoOk = 0;

				}
			}
			fclose(pFile);
		}
	}

    return todoOk;
}
