#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[51];
    char tipo[20];
    int tiempo;

}eBicicleta;

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParamS(char* idStr, char* nombreStr, char* tipoStr,char* tiempoStr);
eBicicleta* bicicleta_newParametros(int id, char* nombre, char* tipo,int tiempo);
int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_getId(eBicicleta* this,int* id);
int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_getNombre(eBicicleta* this,char* nombre);
int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_getTipo(eBicicleta* this,char* tipo);
int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);
int mostrarBicletas(LinkedList* lista);
void mostrarBicicleta( LinkedList* lista,int indice);
int menuPrincipal();

#endif // BICICLETAS_H_INCLUDED
