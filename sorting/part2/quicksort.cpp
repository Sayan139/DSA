#include <iostream>
using namespace std;

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    // Find the correct position for the pivot
    while (i < j) {
        // Move i to the right while arr[i] is less than or equal to pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Move j to the left while arr[j] is greater than pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        // Swap arr[i] and arr[j] if they are not in the correct position
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index j
    swap(arr[low], arr[j]);
    return j;
}

// Quick Sort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pindex = partition(arr, low, high); // Partition the array
        quicksort(arr, low, pindex - 1); // Recursively sort the left part
        quicksort(arr, pindex + 1, high); // Recursively sort the right part
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1); // Calling Quick Sort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
