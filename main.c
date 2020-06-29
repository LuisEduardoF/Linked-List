#include <stdio.h>
#include "sample.h"
#include "DataTemplate.h"
int main(void) {
	tList list = Inicialize();
	tData x = input(3), y = input(4), z = input(5), w = input(6);
	
	append(list, x);
	append(list, y);
	append(list, z);
	append(list, w);
	
	printf("List:\n");
	printList(list);
	printf("Tamanho da lista: %d\n", len(list));
	//clear(list);
	printf("\nStack:\n");
	tStack stack = Stack();
	
	push(stack, x);
	push(stack, y);
	push(stack, z);
	push(stack, w);
	
	printStack(stack);
	/*
	
	printf("Dado do topo:\n");
	printData(peek(stack));
	printf("Tamanho da stack: %d\n\n", size(stack));

	printf("Topo tirado:\n");
	tData V = pop(stack);
	printStack(stack);

	printf("Dado tirado:\n");
	printData(V);

	printf("Dado do topo:\n");
	printData(peek(stack));

	printf("Tamanho da stack: %d\n\n", size(stack));
	*/
	return 0;
}