#include <iostream>
#include <climits>
using namespace std;

// Function to find the second largest element
int secondlargest(int arr[], int n) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (second_largest == INT_MIN) {
        return -1; // No second largest element
    }

    return second_largest;
}

// Function to find the second smallest element
int secondsmallest(int arr[], int n) {
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    if (second_smallest == INT_MAX) {
        return -1; // No second smallest element
    }

    return second_smallest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Second largest: " << secondlargest(arr, n) << endl;
    cout << "Second smallest: " << secondsmallest(arr, n) << endl;

    return 0;
}
