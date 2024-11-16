#include<iostream>
using namespace std;

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i<j){
        do{
            i++;
        } while(arr[i] <= pivot);

        while(arr[j] > pivot){
            j--;
        }

        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[low]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high){ 
        int p = partition(arr, low, high);

        quicksort(arr, low, p-1); // recursive calls
        quicksort(arr, p+1, high);
    }
}

int main(){
    int arr[5] = {5, 4, 3, 2, 0};
    quicksort(arr, 0, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<' ';
    }
}