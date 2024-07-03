#include <bits/stdc++.h>
using namespace std;
int partiononing (int a[],int low_t,int high){
    int pivot = a[high];
    int low = (low_t - 1);

    for (int i = low_t; i <= high- 1; i++) {

        if (a[i] < pivot) {
            low++;
            swap(a[low], a[i]);
        }
    }
    swap(a[low + 1],a[high]);
    return (low + 1);
}
void quicksort(int a[],int low_t,int high) {
    if (low_t < high) {
        int pi = partiononing(a, low_t, high);

        quicksort(a, low_t, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
int main(){
    int n = 0;


    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    quicksort(a,0,n - 1);
    for(int i = 0;i < n;i++)
    {
        cout << a[i] << " ";
    }
    cout <<endl;
    for(int i = n-1;i >-1;i--)
    {
        cout << a[i] << " ";
    }
}


