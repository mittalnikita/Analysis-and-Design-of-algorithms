#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
private:
    vector<int> heap;

    void heapify(int n, int i) {
        int largest = i;          // Initialize largest as root
        int left = 2 * i + 1;      // left = 2*i + 1
        int right = 2 * i + 2;     // right = 2*i + 2

        // If left child is larger than root
        if (left < n && heap[left] > heap[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && heap[right] > heap[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            std::swap(heap[i], heap[largest]);

            // Recursively heapify the affected sub-tree
            heapify(n, largest);
        }
    }

public:
    HeapSort(vector<int>& arr) : heap(arr) {}

    void sort() {
        int n = heap.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(heap[0], heap[i]);

            // Call max heapify on the reduced heap
            heapify(i, 0);
        }
    }

    void print() {
        for (int i=0;i < heap.size();i++)
        cout << heap[i]<< " ";
        cout << endl;
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    HeapSort hs(arr);

    cout << "Original array: ";
    hs.print();

    hs.sort();

    cout << "Sorted array: ";
    hs.print();

    return 0;
}