#include<iostream>
using namespace std;

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMinIndex(int arr[], int start, int end){
    int minI = start;
    for(int i= start+1; i<=end; i++){
        if(arr[i] < arr[minI]){
            minI = i;
        }
    }
    return minI;
}

void selectionSort(int arr[], int n, int index=0){
    if(index == n-1){
        return;
    }

    int minIndex = findMinIndex(arr, index, n-1);
    if(minIndex != index){
        swap(arr[index], arr[minIndex]);
    }
    selectionSort(arr, n, index+1);
}

int main(){
    int arr[5] = {5, 4, 3, 2, 0};
    selectionSort(arr, 5, 0);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<' ';
    }
}