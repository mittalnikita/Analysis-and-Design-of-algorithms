#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class PriorityQ{

    private:
    vector<int> heap;

    void heapify(int node){
        int n = heap.size();
        int largest = node;
        int left = 2*node + 1;
        int right = 2*node + 2;

        if(left < n && heap[left] > heap[largest]){
            largest = left;
        } 
        if(right < n && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != node){
            swap(&heap[node], &heap[largest]);
            heapify(largest);
        }
    }

    public:

    void push(int value){
        heap.push_back(value);
        int node = heap.size() - 1;
        int parent = (node-1) / 2;

        heapify(parent);
    }

    int pop(){

        if(heap.empty()){
            cout<<"Priority queue is empty!!"<<endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    bool empty(){
        return heap.empty();
    }

    int top(){
        if(heap.empty()){
            return -1;
        }

        return heap[0];
    }

    int size(){
        return heap.size();
    }

};

int main(){

    PriorityQ p1;
    p1.push(20);
    p1.push(15);
    p1.push(30);
    p1.push(5);
    p1.push(0);
    p1.push(10);

    while(!p1.empty()){
        cout<<p1.pop()<< "  "; 
    }

    return 0;
}
