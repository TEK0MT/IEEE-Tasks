#ifndef STACK_ARR_H
#define STACK_ARR_H

#define STACK_MAX_SIZE 5
typedef struct
{
    int top;
    int size;
    int data[STACK_MAX_SIZE];
} stack;
void CreatStack(stack *s);
void push(stack *s,int data);
int pop(stack *s);
int Top(stack *s);
int stacksize(stack s);
void display(stack *s);
#endif // STACK_ARR_H
