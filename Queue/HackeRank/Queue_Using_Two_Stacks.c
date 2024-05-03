/* Author : MOHAMED TAREK
 * Problem :Queue using two stacks
 * MADE ON 2 MAY 2024 2:26 AM
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Stack attributes
typedef struct
{
    int top;
    int *arr;
}stack;
//Intilaize Stack
void creat(stack *s,int size)
{
    s->top = -1;//Intialize top = -1 to refer its empty
    s->arr = (int *)malloc(size*sizeof(int)); //allocation of the dynamic array
}
//add element to the stack
void Enqueue(stack *s,int data)
{
    s->top++;
    s->arr[s->top] = data;//assign the data to the array
}
//remove element from the stack
int dequeue(stack *s)
{
    int data = s->arr[s->top];
    s->top--;
    return data;
}
//peek function
int top(stack *s)
{
    return s->arr[s->top];
}
//To achieve queue concept we must swap two arrays to perform FIFO rule
void swapstacks(stack *s,stack *k)
{
    while(s->top != -1)
    {
        Enqueue(k, dequeue(s));
    }
}
int main() {
    int q = 0;//Querey variable
    scanf("%i",&q);//take the q vraiable
    stack s,k;//stack and their intialization
    creat(&s, q);
    creat(&k, q);
    int choice = 0;//to take choice
    int data = 0;//to take data to enqueue
    while(q)
    {
        scanf("%i",&choice);
        if(choice == 1) // 1st for enqueue
        {
            scanf("%i",&data);
            Enqueue(&s, data);
        }
        else if(choice == 2)
        {
            swapstacks(&s, &k); //swap to perform FIFO rule
            dequeue(&k);
            swapstacks(&k, &s);//Swap again to return stacks again
        }
        //my hands tired from writiing comments bro u got the rest of the code 
        else {
            swapstacks(&s, &k);
            printf("%i\n",top(&k));
            swapstacks(&k, &s);
        }
        --q;
    }
      
    return 0;
}
