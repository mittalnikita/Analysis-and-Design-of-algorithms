#include<iostream>
using namespace std;

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int s){
    if(s==0 || s==1){
        return;
    }

    bool swapped = false;
    for(int i=0; i<s-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            swapped = true;
        }
    }
    if((!swapped)){
        return;
    }
    bubbleSort(arr, s-1);
}

int main(){
    int arr[5] = {5, 4, 3, 2, 0};
    bubbleSort(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<' ';
    }
}