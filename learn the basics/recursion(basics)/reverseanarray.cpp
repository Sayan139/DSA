#include <iostream>
#include <vector>
using namespace std;

// Iterative function to reverse an array
void reverseArray1(vector<int>& arr) {
    int i = 0;
    int e = arr.size() - 1;
    while (i < e) {
        swap(arr[i], arr[e]);
        i++;
        e--;
    }
}

// Recursive helper function to reverse an array
void helperfunction(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(arr[start], arr[end]);
    helperfunction(arr, start + 1, end - 1);
}

// Recursive function to reverse an array using helperfunction
void reverseArray2(vector<int>& arr) {
    helperfunction(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray1(arr);
    cout << "Reversed using reverseArray1: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    reverseArray2(arr2);
    cout << "Reversed using reverseArray2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
