#ifndef LIST
#define LIST
typedef struct node *tNode;
typedef struct list *tList;

//Inicializa a Lista
tList Inicialize();
//Adiciona no final da Lista
void append(tList, void*);
//Adiciona na posição da Lista
int insert(tList, void*, int);
//Faz uma cópia da Lista
//tList copy(tList);
//Remove a célula com o elemento indicado
void* erase(tList, void*);
//Remove a célula na posição indicada
void* pop(tList, int);
//Junta duas listas em uma lista completamente nova
tList merge(tList, tList);
//Acopla uma lista a outra
void extend(tList, tList);
//Inverte uma lista
void reverse(tList);
//Da free na lista
void clear(tList);
//Faz os prints da lista
void printList(tList);
//Retorna o tamanho atual da lista
int len(tList);
#endif