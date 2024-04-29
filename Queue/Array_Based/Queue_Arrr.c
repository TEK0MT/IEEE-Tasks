// FILE NAME = Queue_Arr.c
// AUTHOR = MOHAMED TAREK
// MADE IN 29 APRIL 2024 3:16

#include "Queue_Arr.h"
static int QueueFull(Queue q);
static int QueueEmpty(Queue q);
void CreatQueue(Queue *q,int sizee)
{
    q->top = 0; //intialize top = 0
    q->rear = -1; //intialize rear = -1 to indicate its empty
    q->size = 0; //intiialize element count = 0
    q->maxsize = sizee;
}
void Enqueue(Queue *q,int data)
{
    if(QueueFull(*q))
    {
        return ;
    }
    else {
        if (q->rear == q->maxsize - 1 && q->size != q->maxsize ) //to make circular queue
        {
            q->rear = 0;
        } else {
            q->rear++;
        }
        //secound method instead of if statement
        /*  q->rear = (q->rear + 1) % q->maxsize;*/
        q->arr[q->rear] = data;
        q->size++;
    }
}
int Dequeue(Queue *q)
{
    if(QueueEmpty(*q))
    {
        return -156415165;
    }
    else {
        int data = q->arr[q->top];
        if (q->top == q->maxsize - 1) //to return the start of the array
        {
            q->top = 0;
        } else {
            q->top++;
        }
        q->size--;
        return data;
    }
}
int QueueSize(Queue q)
{
    return q.size;
}
void ClearQueue(Queue *q)
{
    q->top = 0; //return top = 0
    q->rear = -1; //return rear = -1 to indicate its empty and overwrite the old data
    q->size = 0; //return element count = 0
}
static int QueueFull(Queue q) //
{
    return (q.size == q.maxsize)?1:0;
}
static int QueueEmpty(Queue q)
{
    return (q.size == 0)?1:0;
}