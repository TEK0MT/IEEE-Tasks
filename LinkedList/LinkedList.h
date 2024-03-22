#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
}dnode;


void InsertAtBeg_sl(node **head,int data);
void Insertbet_sl(node *head,int pos,int data);
void InsertAtEnd_sl(node *head,int data);
/**************************************************/
void InsertAtBeg_dl(dnode **head,int data);
void Insertbet_dl(dnode *head,int pos,int data);
void InsertAtEnd_dl(dnode *head,int data);
void dprint(dnode *head);
/***************************************************/
void print(node *head);
int countls(node *head);
#endif // LINKED_LIST_H
