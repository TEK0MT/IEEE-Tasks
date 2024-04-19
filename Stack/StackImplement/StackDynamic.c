#include "StackDynamic.h"
stackD* CreatStackD(int size)
{
    stackD *s = (stackD *)malloc(sizeof(stackD));
    s->elementcount = 0;
    s->maxsize = size;
    s->top = -1;
    s->ARR = (void **)malloc(size * sizeof(void *));
    return s;
}
void pushD(stackD *s,void *item)
{
    s->top++;
    s->elementcount++;
    s->ARR[s->top] = item;
}
void* popD(stackD *s)
{
    void *data = NULL;
    data = s->ARR[s->top];
    s->top--;
    s->elementcount--;
    return data;
}
void* TopD(stackD *s)
{
    return s->ARR[s->top];
}
int CountD(stackD *s)
{
    return s->elementcount;
}
