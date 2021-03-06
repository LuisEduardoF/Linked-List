#include <stdlib.h>
#include <stdio.h>
#include "DataTemplate.h"
#include "sample.h"
/* Data structure -- CÉLULA de Lista:
	- Usada em listas duplas
	- Guarda sempre um dado e um ponteiro para o próximo dado e do dado anterior
*/
typedef struct node* tNode;
struct node{
	void* info;
	tNode ant, prox;
};
tNode createNode(void* info){
	tNode node = malloc(sizeof(tNode));
	node->info = info;
	node->prox = node->ant = NULL;
	return node;
}

/* Data structure -- Lista:
	- Big(O) cheat sheet:
		- Access: O(n)
		- Search: O(n)
		- Insert: O(1)
		- Deletion: O(1)
	- Guarda sequencia de dados muito grandes, e de maneira eficiente
	- Desvantagem de um array: O acesso se torna em tempo linear e não constante ( Menos acessável que um array )
	- Vantagens de um array: Inserir e deletar dados em tempo constante ( Mais mutável que um array )
*/
struct list{
	int lenght;
	tNode fst, end;
};
tList createList(){
	return malloc(sizeof(tList));
}
tList Inicialize(){
	tList list = createList();
	list->fst = NULL;
	list->end = NULL;
	list->lenght = 0;
	return list;
}
void append(tList list, void* info){
	tNode node = createNode(info);
	if(list->fst == NULL){
		list->fst = list->end = node;
		node->ant = NULL;
	}
	else{
		list->end->prox = node;
		node->ant = list->end;
		list->end = node;
	}
	list->end->prox = NULL;
	list->lenght++;
}
int insert(tList list, void* info, int pos){
	if(pos > list->lenght + 1 || pos < 0)
		return -1;
	
	tNode p = list->fst, ant = NULL, node = createNode(info);
	
	for(p = list->fst; p!= NULL; p = p->prox){
		if(pos == 0){
			break;
		}
		else{
			pos--;
			ant = p;
		}
	}
	if(p == NULL){
		append(list, info);
	}
	else if(p == list->fst){
		node->prox = list->fst;
		p->ant = node;
		list->fst = node;
	}
	else if(p == list->end){
		list->end->prox = node;
		node->ant = p;
		list->end = node;
	}
	
	else{
		ant->prox = node;
		node->ant = ant;
		node->prox = p;
		p->ant = node;
	}
	list->lenght++;

	return 1;
}
void* erase(tList list, void* info){
	tNode p = list->fst, ant = NULL;
	void* aux;
	for(p = list->fst; p!= NULL; p = p->prox){
		if(compare(p->info, info))
			break;
		ant = p;
	}
	if  (p == NULL){
		return NULL;
	}
	if (p == list->fst && p == list->end){
		list->fst = list->end = NULL;
	}
	if (p == list->end){
		list->end = ant;
		ant->prox = NULL;
	}
	if (p == list->fst){
		list->fst = p->prox;
		list->fst->ant = NULL;
	}
	else{
		ant->prox = p->prox;
		ant->prox->ant = ant;
	}
	aux = copyData(p->info);
	freeData(p->info);
	free(p);
	list->lenght--;
	return aux;
}
void* destroy(tList list, int pos){
	tNode p = list->fst, ant = NULL;
	void* aux;
	if(pos > list->lenght)
		return NULL;
	for(p = list->fst; p!= NULL; p = p->prox, pos--){
		if(!pos)
			break;
		ant = p;
	}
	if  (p == NULL){
		return NULL;
	}
	if (p == list->fst && p == list->end){
		list->fst = list->end = NULL;
	}
	if (p == list->end){
		list->end = ant;
		ant->prox = NULL;
	}
	if (p == list->fst){
		list->fst = p->prox;
		list->fst->ant = NULL;
	}
	else{
		ant->prox = p->prox;
		ant->prox->ant = ant;
	}
	aux = copyData(p->info);
	freeData(p->info);
	free(p);
	list->lenght --;
	return aux;
}
tList merge(tList first_list, tList end_list){
	tList new = Inicialize();
	for(tNode p = first_list->fst; p != NULL; p = p->prox){
		append(new, copyData(p->info));
	}
	for(tNode p = end_list->fst; p != NULL; p = p->prox){
		append(new, copyData(p->info));
	}
	return new;
}
void reverse(tList list){
	list->end = list->fst;
	tNode s = NULL;
	for(tNode p = list->fst; p!= NULL; p = p->ant){
		if(p->prox != NULL)
			list->fst = p->prox;
		s = p->prox;
		p->prox = p->ant;
		p->ant = s;
	}
}
void extend(tList list, tList list2){
	for(tNode p = list2->fst; p!= NULL; p = p->prox){
		append(list, copyData(p->info));
	}
	clear(list2);
}
void clear(tList list){
	for(tNode p = list->fst; p!= NULL; p = p->prox){
		freeData(p->info);
		free(p);
	}
	list->lenght = 0;
	free(list);
}
void printList(tList list){
	for(tNode p = list->fst; p!= NULL; p = p->prox){
		printData(p->info);
	}
}
int len(tList list){
	return list->lenght;
}
void* top(tList list){
	return list->fst->info;
}
void* bottom(tList list){
	return list->end->info;
}

//STACK DATA STRUCTURE
struct stack{
	tList top;
};
tStack createStack(){
	return malloc(sizeof(tStack));
}
tStack Stack(){
	tStack new = createStack();
	new->top = Inicialize();
	return new;
}
int empty(tStack pile){
	return len(pile->top);
}
int size(tStack pile){
	return len(pile->top);
}
void* peek(tStack pile){
	return top(pile->top);
}
void push(tStack pile, void* info){
	insert(pile->top, info, 0);
}
void* pop(tStack pile){
	return destroy(pile->top, 0);
}
void printStack(tStack pile){
	printList(pile->top);
}
