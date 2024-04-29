// FILE NAME = main.c
// AUTHOR = MOHAMED TAREK
// MADE IN 29 APRIL 2024 3:16
#include <stdio.h>
#include "Queue_Arr.h"
int main(void) {
    Queue q;
    CreatQueue(&q,3);
    Enqueue(&q,5);
    Enqueue(&q,8);
    Enqueue(&q,9);
    printf("%i\n", Dequeue(&q));
    Enqueue(&q,7);
    printf("%i\n", Dequeue(&q));
    printf("%i\n", Dequeue(&q));
    printf("%i\n", Dequeue(&q));

    return 0;
}
