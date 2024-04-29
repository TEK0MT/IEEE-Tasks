//FILE NAME : main.c
//AUTHOR : MOHAMED TAREK
// MADE IN 29 APRIL 2024 5:42 PM

#include "LS_Queue.h"

int main()
{
    Queue q;
    CreatQueue(&q,4);
    Enqueue(&q,5);
    Enqueue(&q,8);
    Enqueue(&q,4);
    Enqueue(&q,9);
    printf("%i \n", Dequeue(&q));
    Enqueue(&q,6);
    printf("%i \n", Dequeue(&q));
    printf("%i \n", Dequeue(&q));
    printf("%i \n", Dequeue(&q));
    printf("%i \n", Dequeue(&q));
    printf("%i \n", Dequeue(&q));
    return 0;
}