#include <iostream>
using namespace std;

// Function to perform left rotation
void leftrotate(int arr[], int n) {
    int x = arr[0];  // Store the first element
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift all elements one position to the left
    }
    arr[n - 1] = x;  // Place the first element at the last position
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    leftrotate(arr, n);  // Call the function to rotate the array

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
