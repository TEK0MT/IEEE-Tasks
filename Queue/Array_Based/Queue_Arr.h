// FILE NAME = Queue_Arr.h
// AUTHOR = MOHAMED TAREK
// MADE IN 29 APRIL 2024 3:16

#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H
typedef struct
{
    int top;
    int rear;
    int size;
    int maxsize;
    int arr[];
}Queue;

void CreatQueue(Queue *q,int sizee);
void Enqueue(Queue *q,int data);
int Dequeue(Queue *q);
int QueueSize(Queue q);
void ClearQueue(Queue *q);
#endif //QUEUE_ARR_H
