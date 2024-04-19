#ifndef STACK_LINKED_H
#define STACK_LINKED_H
#include <stdlib.h>
typedef struct lnode
{
    int data;
    struct lnode *next;
}node;
typedef struct
{
    node *Top;
}stackL;
stackL* CreatStackD();
void pushL(stackL *s,int item);
int popL(stackL *s);
int TopL(stackL *s);
int CountL(stackL *s);
#endif // STACK_LINKED_H
