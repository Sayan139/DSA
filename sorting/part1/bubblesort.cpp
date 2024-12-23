#include <iostream>
using namespace std;

void bubblesort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        bool didswap = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = true;
            }
        }
        if (!didswap) {
            break;
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubblesort(arr, n);

    cout << "After applying bubble sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
