#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int controller_loadFromText(LinkedList* pArrayListBicicletas);
int parser_BicicletasFromText(FILE* pFile , LinkedList* pArrayListBicletas);
int controller_saveAsText(char* path , LinkedList* pArrayListBicletas);

#endif // PARSER_H_INCLUDED
