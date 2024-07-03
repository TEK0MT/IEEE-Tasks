#include <iostream>

using namespace std;
int partitioning(int n[],int low_t,int high){

    int piovet = n[high];
    int i = low_t;
    for(int j = low_t; j < high;j++){
        if(piovet >= n[j]){
            swap(n[j] , n[i]);
            i++;
        }
    }
    swap(n[i],n[high]);
    return i;
}
void quicksort(int n[],int low_t,int high){
    if(low_t < high){
        int piovet = partitioning(n,low_t,high);
        quicksort(n,low_t,piovet - 1);
        quicksort(n,piovet + 1,high);
    }
}
int main(){

    int size = 0;
    cin >> size;
    int n[size];
    for(int i = 0; i < size;i++)
    {
        cin >> n[i];
    }
    quicksort(n,0,size - 1);
    int midpoint = (size + 1) / 2;
    for(int i = 0; i < midpoint;i++){
        cout << n[i] << " ";
    }
    for(int i =midpoint - 1 ; i >= 0;i--){
        cout << n[i] << " ";
    }
    cout << endl;
    for(int i = size - 1; i >= midpoint;i--){
        cout << n[i] << " ";
    }
    for(int i = midpoint; i < size ;i++){
        cout << n[i] << " ";
    }
}