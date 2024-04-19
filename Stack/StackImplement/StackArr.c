#include "StackArr.h"
void CreatStack(stack *s)
{
    s->top = -1;
    s->size = 0;
}
void push(stack *s,int data)
{
    s->top++;
    s->size++;
    s->data[s->top] = data;
}
int pop(stack *s)
{
    int num = s->data[s->top];
    s->top--;
    s->size--;
    return num;
}
int Top(stack *s)
{
    return s->data[s->top];
}
int stacksize(stack s)
{
    return s->size;
}
void display(stack *s)
{
    int temp = s->top;
     while(temp > -1)
     {
         printf("%i\n",s->data[temp]);
     }
}
