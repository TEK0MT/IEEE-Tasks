#ifndef STACK_DYNAMIC_H
#define STACK_DYNAMIC_H
#include <stdlib.h>
typedef struct{
void **ARR;
int elementcount;
int maxsize;
int top;
}stackD;
stackD* CreatStackD(int size);
void pushD(stackD *s,void *item);
void* popD(stackD *s);
void* TopD(stackD *s);
int CountD(stackD *s);
#endif // STACK_DYNAMIC_H
