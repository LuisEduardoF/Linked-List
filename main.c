#include <stdio.h>
#include "sample.h"
#include "DataTemplate.h"
int main(void) {
	tList list = List(), list2;
	tData x = input(3), y = input(4), z = input(5), w = input(6);
	
	append(list, x);
	append(list, y);
	append(list, z);
	append(list, w);
	printf("List:\n");
	printList(list);

	reverse(list);
	printf("Lista:\n");
	printList(list);
	clear(list);
	return 0;
}