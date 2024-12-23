#include <iostream>
using namespace std;

// Bubble Sort function using recursion
void bubblesort(int arr[], int n) {
    if (n == 1) {
        return;
    }

    bool didSwap = false;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            // Swap the elements if they are in the wrong order
            swap(arr[j], arr[j + 1]);
            didSwap = true;
        }
    }

    // If no swaps occurred, the array is already sorted
    if (!didSwap) {
        return;
    }

    // Recursively call the function for the rest of the array
    bubblesort(arr, n - 1);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubblesort(arr, n); // Calling the recursive bubble sort function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
