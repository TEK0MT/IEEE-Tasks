//FILE NAME : LS_Queue.c
//AUTHOR : MOHAMED TAREK
// MADE IN 29 APRIL 2024 5:47 PM
#include "LS_Queue.h"
static int QueueFull(Queue q);
static int QueueEmpty(Queue q);
void CreatQueue(Queue *q,int sizee)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->maxsize = sizee;
}
void Enqueue(Queue *q,int data)
{
    node *temp = (node *)malloc(sizeof(node)); //Assuming it returned an node successfully
    temp->data = data; //copying data to the node
    temp->next = NULL;
    if(QueueFull(*q))
    {
        return ;
    }
    else {
        if (QueueEmpty(*q)) {
            q->front = temp;
            q->rear = temp;
        } else {
            q->rear->next = temp;
            q->rear = temp;
        }
        q->size++; //increasing element count
    }
}
int Dequeue(Queue *q)
{
    int data = -16559161; //the big number refer to error
    if(QueueEmpty(*q))
    {
        /*nothing*/
    }
    else
    {
        node *temp = q->front;
        data = q->front->data; //
        q->front = q->front->next;
        if(q->front == NULL) {
            q->rear == NULL;
        }
        q->size--;
        free(temp);
    }
    return data;
}
int QueueSize(Queue q)
{
    return (q.size);
}
void ClearQueue(Queue *q)
{
    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    q->size = 0;
}
static int QueueFull(Queue q)
{
    return (q.size == q.maxsize)?1:0;
}
static int QueueEmpty(Queue q)
{
    return !(q.size);
}