//FILE NAME : LS_Queue.h
//AUTHOR : MOHAMED TAREK
// MADE IN 29 APRIL 2024 5:43 PM

#ifndef QUEUE_LS_QUEUE_H
#define QUEUE_LS_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct lsnode
{
    int data;
   struct lsnode *next;
}node;
typedef struct
{
    node *front;
    node *rear;
    int size;
    int maxsize;
}Queue;

void CreatQueue(Queue *q,int sizee);
void Enqueue(Queue *q,int data);
int Dequeue(Queue *q);
int QueueSize(Queue q);
void ClearQueue(Queue *q);
#endif //QUEUE_LS_QUEUE_H
