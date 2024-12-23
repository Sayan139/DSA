#include <iostream>
using namespace std;

// Function to check if the array is sorted
bool check_array_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the array is sorted or rotated
bool check_if_sorted_or_rotated(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            count++;
        }
    }
    // Check if the last element is greater than the first
    if (arr[n - 1] > arr[0]) {
        count++;
    }
    return count <= 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Checking if the array is sorted
    if (check_array_sorted(arr, n)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    // Checking if the array is sorted or rotated
    if (check_if_sorted_or_rotated(arr, n)) {
        cout << "Array is sorted or rotated." << endl;
    } else {
        cout << "Array is neither sorted nor rotated." << endl;
    }

    return 0;
}
