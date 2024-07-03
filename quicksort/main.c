#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int *x,int *y);
void quicksort(int a[],int low,int high);
int partition (int a[],int low,int high);
int main(void) {
    int a[8] = { 1 , 99 ,8 ,55 ,33,2,6,77};
    srand(time(NULL));
    quicksort(a,0,7);
    for(int i = 0; i < 7;i++)
    {
        printf("%i ",a[i]);
    }
    return 0;
}
void swap (int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quicksort(int a[],int low,int high){

    if(low < high)
    {
        int piovet = partition(a,low,high);
        quicksort(a,low,piovet - 1);
        quicksort(a,piovet + 1,high);

    }
}
int partition (int a[],int low,int high)
{
    int piovet_index = low + (rand() % (high - low));
    if(piovet_index != high){
        swap(&a[piovet_index],&a[high]);
    }
    int piovet = a[high];
    int i = low;
    for(int j = low;j < high;j++)
    {
        if(piovet >= a[j])
        {
            swap(&a[j],&a[i]);
            i++;
        }
    }
    swap(&a[i],&a[high]);
    return i;
}