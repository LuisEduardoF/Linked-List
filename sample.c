#include <stdio.h>
#include <stdlib.h>
#include "sample.h"
struct data{
	int num;
};
tData createData(){
	return malloc(sizeof(tData));
}
tData input(int x){
	tData data = createData();
	data->num = x;
	return data;
}
int compare(tData x, tData y){
	return x->num == y->num;
}
tData copyData(tData data){
	tData new = createData();
	new->num = data->num;
	return new;
}
void change(tData data, int x){
	data->num = x;
}
void freeData(tData data){
	free(data);
}
void printData(tData data){
	if(data == NULL){
		printf("Dado não processado\n");
	}
	else
		printf("%d\n", data->num);
}