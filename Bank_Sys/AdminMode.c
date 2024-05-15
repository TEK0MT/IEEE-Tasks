/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : AdminMode.c
 * MADE IN 6 MAY 2024 10:54 PM
 */
#include "LinkedList.h"
void AddClient(node **n,char *name,int age,int id,int balance,short password)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->name = strdup(name);

    temp->age = age;
    temp->id = id;
    temp->balance = balance;
    temp->password = password;
    temp->next = NULL;
    if(*n == NULL)
    {
        *n = temp;
    }
    else {
        node *t = *n;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }
}
void RemoveClient(node *n,int id)
{
    node *t = n;
    node *k = NULL;
    while(t->next->id != id)
    {
        t = t->next;
    }
    k = t->next;
    t->next = k->next;
    free(k);
}
void ShowAllClients(node *n)
{
    node *k = n;
    while(k != NULL)
    {
        printf("name : %s   id : %i   age : %i   balance : %i $\n",k->name,k->id,k->age,k->balance);
        k = k->next;
    }
}
void ShowClient(node *n,int id)
{
    node *k = n;
    while(k->id != id)
    {
        k = k->next;
    }
    printf("name : %s   id : %i   age : %i   balance : %i $\n",k->name,k->id,k->age,k->balance);
}
void Edit(node *n,int id,char *name,int age,int balance,short password)
{
    node *temp = n;
    while(temp->id != id)
    {
        temp = temp->next;
    }
    temp->name = strdup(name);
    temp->age = age;
    temp->balance = balance;
    temp->password = password;
}