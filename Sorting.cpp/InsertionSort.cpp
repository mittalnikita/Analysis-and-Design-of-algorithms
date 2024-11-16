#include<iostream>
using namespace std;

void insertionSort(int arr[], int s){
    if(s==0 || s==1){
        return;
    }
    insertionSort(arr, s-1);

    int last = arr[s-1];
    int j = s-2;

    while(j>=0 && arr[j]>last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main(){
    int arr[5] = {5, 4, 3, 2, 0};
    insertionSort(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<' ';
    }
}