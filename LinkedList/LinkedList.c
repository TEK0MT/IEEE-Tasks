#include "LinkedList.h"
void InsertAtBeg_sl(node **head,int data)
{
    node *Temp = (node *)malloc(sizeof(node));
    Temp->data = data;
    if((*head) == NULL)
    {
        Temp->next = NULL;
    }
    else
    {
        Temp->next = (*head);
    }
    *head = Temp;
}
void Insertbet_sl(node *head,int pos,int data)
{
    node *Temp = (node *)malloc(sizeof(node));
    node *Temp1 = head;
    Temp->data = data;
    int count = 1;
    while(count < pos - 1)
    {
        Temp1 = Temp1->next;
        count++;
    }
    Temp->next = Temp1->next;
    Temp1->next = Temp;
}
void InsertAtEnd_sl(node *head,int data)
{
    node *Temp = (node *)malloc(sizeof(node));
    node *Temp1 = head;
    Temp->data = data;
    while(Temp1->next != NULL)
    {
        Temp1 = Temp1->next;
    }
    Temp->next = NULL;
    Temp1->next = Temp;
}
void print(node *head)
{
    node *Temp = head;
    while(Temp != NULL)
    {
        printf("%i ",Temp->data);
        Temp = Temp->next;
    }
}
int countls(node *head)
{
    node *Temp = head;
    int count = 0;
    while(Temp != NULL)
    {
        count++;
        Temp = Temp->next;
    }
    return count;
}
/*******************************************************/
void InsertAtBeg_dl(dnode **head,int data)
{
    dnode *Temp = (dnode *)malloc(sizeof(dnode));
    Temp->data = data;
    Temp->prev = NULL;
    if((*head) == NULL)
    {
        Temp->next = NULL;

    }
    else
    {
        Temp->next = (*head);
    }
    *head = Temp;
}
void Insertbet_dl(dnode *head,int pos,int data)
{
    dnode *Temp = (dnode *)malloc(sizeof(dnode));
    dnode *Temp1 = head;
    dnode *Temp2 = NULL;
    Temp->data = data;
    int count = 1;
    while(count < pos - 1)
    {
        Temp1 = Temp1->next;
        count++;
    }
    Temp2 = Temp1->next;
    Temp->next = Temp2;
    Temp2->prev = Temp;
    Temp1->next = Temp;
    Temp->prev = Temp1;

}
void InsertAtEnd_dl(dnode *head,int data)
{
    dnode *Temp = (dnode *)malloc(sizeof(dnode));
    dnode *Temp1 = head;
    Temp->data = data;
    while(Temp1->next != NULL)
    {
        Temp1 = Temp1->next;
    }
    Temp->next = NULL;
    Temp->prev = Temp1;
    Temp1->next = Temp;
}
void dprint(dnode *head)
{
    dnode *Temp = head;
    while(Temp != NULL)
    {
        printf("%i ",Temp->data);
        Temp = Temp->next;
    }
}
