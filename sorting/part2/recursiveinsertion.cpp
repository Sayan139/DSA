#include <iostream>
using namespace std;

// Recursive Insertion Sort function
void insertionsort(int arr[], int i, int n) {
    if (i == n) {
        return; // Base case: when i reaches the end of the array
    }

    int j = i;
    // Move elements of arr[0..i-1], that are greater than arr[i], to one position ahead
    while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    // Recur for the next element
    insertionsort(arr, i + 1, n);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionsort(arr, 0, n); // Call the recursive insertion sort function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
