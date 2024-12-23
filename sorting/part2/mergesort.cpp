#include <iostream>
#include <vector>
using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merging the two halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Adding remaining elements of left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Adding remaining elements of right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copying the sorted elements back to the original array
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

// Merge Sort function
void mergesort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);          // Recursively sorting the left half
    mergesort(arr, mid + 1, high);     // Recursively sorting the right half
    merge(arr, low, mid, high);       // Merging the two halves
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, n - 1);  // Calling mergesort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
