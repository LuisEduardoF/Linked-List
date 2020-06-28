#ifndef SAMPLE
#define SAMPLE
typedef struct data *tData;
tData input(int);
void change(tData, int);
tData copyData(tData);
int compare(tData, tData);
void freeData(tData);
void printData(tData);
#endif