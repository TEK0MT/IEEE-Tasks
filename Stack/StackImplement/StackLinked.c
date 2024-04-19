#include "StackLinked.h"
stackL* CreatStackD()
{
    stackL *s;
    s->Top = NULL;
}
void pushL(stackL *s,int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->next = s->Top;
    s->Top = temp;
}
int popL(stackL *s)
{
    int num = s->Top->data;
    node *temp = s->Top;
    s->Top = s->Top->next;
    free(temp);
    return num;
}
int TopL(stackL *s)
{
    return s->Top->data;
}
int CountL(stackL *s)
{
    node *temp = s->Top;
    int counter = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}
