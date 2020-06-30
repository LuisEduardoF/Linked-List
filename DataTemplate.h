#ifndef LIST
#define LIST
typedef struct list *tList;
typedef struct stack *tStack;
//	--Lista--
//Inicializa a Lista
tList Inicialize();
//Adiciona no final da Lista
void append(tList, void*);
//Adiciona na posição da Lista
int insert(tList, void*, int);
//Remove a célula com o elemento indicado
void* erase(tList, void*);
//Remove a célula na posição indicada
void* destroy(tList, int);
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
//Retorna a célula do topo da lista
void* top(tList);
//Retorna a célula do final da lista
void* bottom(tList);

//	--Pilha--
//Inicializa a pilha
tStack Stack();
//Verifica se a pilha está vazia
int empty(tStack);
//Retorna o tamanha da pilha
int size(tStack);
//Retorna o dado no topo da pilha
void* peek(tStack);
//Adiciona um dado no topo da lista
void push(tStack, void*);
//Retira um dado no topo da lista
void* pop(tStack);
//Printa a lista
void printStack(tStack);

#endif