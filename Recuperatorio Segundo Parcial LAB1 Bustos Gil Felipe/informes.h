#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int getRandomTiempo();
void* settearTiempo(void* element);
int bicicletaSetCampoTiempo(LinkedList* lista);
int bicicletaBMX(void* element);
int bicicletaMTB(void* element);
int bicicletaPaseo(void* element);
int bicicletaPlayera(void* element);
int menuFiltrado();
LinkedList* filtrarPorTipo(LinkedList* lista);
int ordenarBicicletas(LinkedList* lista);
int comparaBicicletasTipo(void* a, void* b);
int comparaBicicletasTiempo(void* a, void* b);

#endif // INFORMES_H_INCLUDED
