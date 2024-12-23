#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

// Function to find the largest element in the array
int largestele(int arr[], int n) {
    int largest = INT_MIN; // Initializing to the smallest possible integer value
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "The largest element is: " << largestele(array, n) << endl;
    return 0;
}
